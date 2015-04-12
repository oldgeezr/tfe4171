#!/usr/bin/gmake -f
# COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc --------{{{#
# See ESLX_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}#

#----------------------------------------------------------------------
# Uncomment and replace the following to set the name of the executable;
# otherwise, the name of the directory will be used.
#---
#MODULE=NAME_OF_EXECUTABLE

#----------------------------------------------------------------------
# Uncoment and set the following to specify which files consitute source
# files to be compiled into objects; otherwise, filenames matching *.cpp
# will be used.
#---
#SRCS=LIST_OF_CPP_FILES

#----------------------------------------------------------------------
# Default mode (exe => create executable, sim => run the simulation)
#---
#DFLT=sim

WORK=.
SYSTEMC_LIB=$(firstword $(wildcard $(SYSTEMC)/lib*))

.PHONY: all clean Hello_C Hello_Cpp Hello_SystemC Hello_Verilog

all: Hello_C Hello_Cpp Hello_SystemC Hello_Verilog

clean:
	rm -fr *.o *.x *.vvp *.deps dependencies.mk

Hello_C:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling Hello World in vanilla C"
	gcc  -O0 -g -ggdb -I$(WORK)/ -o $(WORK)/Hello_C.x $(WORK)/Hello_C.c
	@echo "+++ Executing +++++++++++++++++++"
	$(WORK)/Hello_C.x

Hello_Cpp:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling Hello World in simple C++"
	g++  -O0 -g -ggdb -I$(WORK)/ -o $(WORK)/Hello_Cpp.x $(WORK)/Hello_Cpp.cpp
	@echo "+++ Executing +++++++++++++++++++"
	$(WORK)/Hello_Cpp.x

Hello_SystemC:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling Hello World in SystemC"
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -arch i386\
            -c $(WORK)/Hello_Cpp.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -arch i386\
            -c $(WORK)/Hello_SystemC.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -arch i386\
            -c $(WORK)/main.cpp
	g++ -O0 -g -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -L$(WORK)/ -L$(SYSTEMC_LIB)\
            -arch i386\
            -o $(WORK)/Hello_SystemC.x \
            $(WORK)/Hello_SystemC.o $(WORK)/main.o\
            -lsystemc -lm   2>&1 | c++filt
	@echo "+++ Executing +++++++++++++++++++"
	$(WORK)/Hello_SystemC.x

Hello_Verilog:
	@echo "+++++++++++++++++++++++++++++++++"
	@echo "Compiling Hello World in Verilog"
	@echo "Assuming icarus verilog"
	iverilog -o $(WORK)/Hello_Verilog.vvp $(WORK)/Hello_Verilog.v
	@echo "+++ Executing +++++++++++++++++++"
	vvp $(WORK)/Hello_Verilog.vvp

# COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc.--------{{{#
# See ESLX_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}#
# END $Id$
