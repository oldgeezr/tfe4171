//BEGIN connections.cpp (systemc)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//See connections.h for more information
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Interface API for sc_signal<int>

    const sc_event& value_changed_event() const {}

    // read the current value
    const int& read() const {}

    // get a reference to the current value (for tracing)
    const int& get_data_ref() const {}

    // was there a value changed event?
    bool event() const {}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//END $Id: interfaces.inc,v 1.1 2004/01/17 03:44:58 dcblack Exp $
