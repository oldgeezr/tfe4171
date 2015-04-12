#!/usr/bin/make -f
# -*- make -*- vim:syntax=make:tw=72
# COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc.--------{{{#
# See ESLX_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}

#----------------------------------------------------------------------
# Uncomment and replace the following to set the name of the
# executable file; otherwise, the name of the directory where make
# executes will be used.
#---
ifndef UNIT
UNIT:=pcix
endif

#----------------------------------------------------------------------
# Uncomment and set the following to specify which files consitute
# source files to be compiled into objects; otherwise, ALL filenames
# matching *.cpp in the current directory will be used.

#----------------------------------------------------------------------
# Set the following to provide runtime arguments to the executable when
# running.
#---
ifndef RUNTIME_ARGS
 ifneq "$(wildcard rcfg.xml)" ""
  RUNTIME_ARGS:=--rcfg rcfg.xml
 endif
endif

#----------------------------------------------------------------------
#---
ifndef SRCS
SRCS:=ea_pcix_trans.cpp main.cpp pcix.cpp
endif

#----------------------------------------------------------------------
# Default target (objs => compile only, exe => create executable,
# run => execute the simulation)
#---
DFLT:=run

#----------------------------------------------------------------------
# A list of boost libraries you use in the design. Include the -l 
# prefix. ea_report requires regex
BOOST_LIBS:=-lboost_regex

#----------------------------------------------------------------------
# Other optional macros you may wish to set. It is preferrable that
# these are the only additional flags you set.
#
#OTHER_CFLAGS:=
#OTHER_LDFLAGS:=
#OTHER_INCDIRS:=
#OTHER_LIBDIRS:=
#OTHER_LIBS:=
#USING_SYSTEMC:=1
#USING_SCV:=1
#USING_TLM:=1

#----------------------------------------------------------------------
# *** DO NOT EDIT BELOW THIS LINE ***** DO NOT EDIT BELOW THIS LINE ***
#----------------------------------------------------------------------
# The following locates the closest definition file containing the rules
# that are used to compile designs anywhere here or above to three levels
# or in the $ESLX/etc directory..
ifndef ESLX
  $(warning Defining ESLX)
  ESLX:=/eda/eslx/default
endif
# Allow for overrides locally, but normally use $ESLX/etc
RULEDIRS := . .. ../.. ../../.. $(ESLX)/etc
RULES := $(firstword $(wildcard $(addsuffix /Makefile.rules,$(RULEDIRS))))
$(warning Including $(RULES))
include $(RULES)

# COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc.--------{{{#
# See ESLX_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}
#END $Id$
