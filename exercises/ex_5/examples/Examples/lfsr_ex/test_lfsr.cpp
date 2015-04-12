//BEGIN test_lfsr.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See test_lfsr.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "test_lfsr.h"

extern unsigned errors;

void test_lfsr::do_reset() {
  wait(1,SC_NS);
  reset->write(true);
  sample->write(false);
  wait();
  wait();
  reset->write(false);
  wait();
  wait();
  cout << "INFO: Device reset at " << sc_time_stamp() << endl;
}//end test_lfsr::do_reset

void test_lfsr::test_lfsr_thread() {
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Shared test variables
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  const unsigned SAMPLE_PERIOD = 5;
  const unsigned SIGNATURES = 3;
  const unsigned TOTAL_SAMPLES =SIGNATURES*SAMPLE_PERIOD;
  const unsigned TESTWORDS = TOTAL_SAMPLES/32+1;
  unsigned long  data[TESTWORDS];
  sc_uint<32>    known_good[SIGNATURES];
  sc_time        t5NS(5,SC_NS);
  unsigned       bit_count;
  unsigned       signature_idx;
  const unsigned MAXSHOWN = 99;
  unsigned       failures = 0;
  unsigned       pass;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Initialize ports.
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  reset->write(false);
  sample->write(false);
  wait(SC_ZERO_TIME);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Generate a random sequence of TOTAL_SAMPLES bits.
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  for (unsigned i=0;i!=TESTWORDS;i++) {
    data[i] = rand();
  }//endfor

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Reset the design and apply the sequence and sample every
  // SAMPLE_PERIOD cycles for TOTAL_SAMPLES clocks saving the
  // sample in a known good array.
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << endl
       << "-------------------------------------------------------------" << endl
       << "INFO: 1st pass - Sampling known good." << endl
       << "-------------------------------------------------------------"
       << endl;
  do_reset();
  pass = 1;
  bit_count = 0;
  signature_idx = 0;
  for (unsigned i=0;i!=TESTWORDS;i++) {
    unsigned long sample32 = data[i];
    for (unsigned short b=0;b!=32;b++) {
      if (bit_count == TOTAL_SAMPLES) goto END_PASS1;
      sample->write(sample32&1?true:false);
      sample32 >>= 1;
      wait();
      if (bit_count < MAXSHOWN) {
        cout << "INFO: " << name() << " wrote " << sample->read() 
             << " for bit " << bit_count << " at " << sc_time_stamp()
             << endl;
      }
      if (bit_count % SAMPLE_PERIOD == 0 && bit_count != 0) {
        known_good[signature_idx] = signature->read();
        if (signature_idx < MAXSHOWN) {
          cout << "INFO: " << name() << " pass " << pass
               << " Saving known good sample "
               << "#" << signature_idx
               << " = 0x" << hex << known_good[signature_idx] << dec
               << endl;
        }
        signature_idx++;
      }//endif
      bit_count++;
    }//endfor b
  }//endfor i
  END_PASS1:

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Reset the design and apply the sequence and sample every
  // SAMPLE_PERIOD cycles for TOTAL_SAMPLES comparing the
  // sample to the known good array.
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << endl
       << "-------------------------------------------------------------" << endl
       << "INFO: 2nd pass - testing known good." << endl
       << "-------------------------------------------------------------"
       << endl;
  do_reset();
  pass = 2;
  bit_count = 0;
  signature_idx = 0;
  for (unsigned i=0;i!=TESTWORDS;i++) {
    unsigned long sample32 = data[i];
    for (unsigned short b=0;b!=32;b++) {
      if (bit_count == TOTAL_SAMPLES) goto END_PASS2;
      sample->write(sample32&1?true:false);
      sample32 >>= 1;
      wait();
      if (bit_count < MAXSHOWN) {
        cout << "INFO: " << name() << " wrote " << sample->read() << " for bit " << bit_count << " at " << sc_time_stamp()
             << endl;
      }
      if (bit_count % SAMPLE_PERIOD == 0 && bit_count != 0) {
        if (known_good[signature_idx] != signature->read()) {
          cout << "FAIL: " << name() << " pass " << pass
               << " sampling miscompared " << "#" << signature_idx
               << " = 0x" << hex << signature->read() << dec
               << " vs KG 0x" << hex << known_good[signature_idx] << dec
               << endl;
        } else {
          if (signature_idx < MAXSHOWN) {
            cout << "INFO: " << name() << " pass " << pass
                 << " OK sample " << "#" << signature_idx
                 << " = 0x" << hex << known_good[signature_idx] << dec
                 << endl;
          }
        }//endif
        signature_idx++;
      }//endif
      bit_count++;
    }//endfor b
  }//endfor i
  END_PASS2: if (failures != 0) {
    cout << "ERROR: Unexpected failure!" << endl;
    errors++;
  }//endif


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Reset the design, inject a single bit error into the sequence,
  // and apply the sequence and sample every SAMPLE_PERIOD cycles for
  // SAMPLE_PERIOD*SIGNATURE clocks comparing the sample to the known
  // good array.
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << endl
       << "-------------------------------------------------------------" << endl
       << "INFO: 3rd pass - Inject error." << endl
       << "-------------------------------------------------------------"
       << endl;
  do_reset();
  pass = 3;
  bit_count = 0;
  signature_idx = 0;
  unsigned failing_index = rand() % TOTAL_SAMPLES;
  cout << "INFO: Injection to occur at bit " << failing_index << endl;
  for (unsigned i=0;i!=TESTWORDS;i++) {
    unsigned long sample32 = data[i];
    for (unsigned short b=0;b!=32;b++) {
      if (bit_count == TOTAL_SAMPLES) goto END_PASS3;
      if (bit_count == failing_index) {
        cout << "INFO: Injecting error at "
             << " bit " << bit_count
             << endl;
        sample->write(sample32&1?false:true);
      } else {
        sample->write(sample32&1?true:false);
      }//endif
      sample32 >>= 1;
      bit_count++;
      wait();
      if (bit_count < MAXSHOWN) {
        cout << "INFO: " << name() << " wrote " << sample->read() 
             << " for bit " << bit_count << " at " << sc_time_stamp()
             << endl;
      }
      if (bit_count % SAMPLE_PERIOD == 0 && bit_count != 0) {
        if (known_good[signature_idx] != signature->read()) {
          failures++;
          cout << "FAIL: " << name()
               << " sampling miscompared " << "sample #" << signature_idx
               << " = 0x" << hex << signature->read() << dec
               << " vs KG 0x" << hex << known_good[signature_idx] << dec
               << endl;
        } else {
          if (signature_idx < MAXSHOWN) {
            cout << "INFO: " << name() << " pass " << pass
                 << " OK sample " << "#" << signature_idx
                 << " = 0x" << hex << known_good[signature_idx] << dec
                 << endl;
          }
        }//endif
        signature_idx++;
      }//endif
      bit_count++;
    }//endfor b
  }//endfor i
  END_PASS3: if (failures == 0) {
    cout << "ERROR: Missed injected failure!" << endl;
    errors++;
  }//endif


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cout << "Finishing." << endl;
  sc_stop();
}//end test_lfsr::test_lfsr_thread

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: test_lfsr.cpp,v 1.2 2004/02/09 13:38:47 dcblack Exp $
