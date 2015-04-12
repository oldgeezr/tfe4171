#!/usr/bin/gmake -f
# COPYRIGHT (C) 2004 Eklectic Ally, Inc.---------------------------{{{#
# See EKLECTIC_LICENSE for information on legal usage of this file.   #
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

.PHONY: all Hello_C Hello_Cpp Hello_Verilog Hello_SystemC

all: Hello_C Hello_Cpp Hello_Verilog Hello_SystemC

Hello_C:
	gcc  -I$(WORK)/ -o $(WORK)/Hello_C.x $(WORK)/Hello_C.c
	$(WORK)/Hello_C.x

Hello_Cpp:
	g++  -I$(WORK)/ -o $(WORK)/Hello_Cpp.x $(WORK)/Hello_Cpp.cpp
	$(WORK)/Hello_Cpp.x

Hello_Verilog:
	@echo "Assuming icarus verilog"
	iverilog -o $(WORK)/Hello_Verilog.vvp $(WORK)/Hello_Verilog.v
	vvp $(WORK)/Hello_Verilog.vvp

Hello_SystemC:
	g++ -O0 -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -c $(WORK)/Hello_SystemC.cpp
	g++ -O0 -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -c $(WORK)/main.cpp
	g++ -O0 -ggdb -Wno-deprecated\
            -DDEBUG_SYSTEMC\
            -I$(WORK)/ -I$(SYSTEMC)/include -I/include\
            -L$(WORK)/ -L$(SYSTEMC_LIB)\
            -o $(WORK)/Hello_SystemC.x \
            $(WORK)/Hello_SystemC.o $(WORK)/main.o\
            -lsystemc -lm   2>&1 | c++filt
	$(WORK)/Hello_SystemC.x

# COPYRIGHT (C) 2004 Eklectic Ally, Inc.---------------------------{{{#
# See EKLECTIC_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}#
# END $Id: Makefile,v 1.2 2004/04/08 15:40:40 dcblack Exp $
