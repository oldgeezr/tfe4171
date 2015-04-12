#!/usr/bin/make -f
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
DFLT=sim

# Following finds Makefile.defs in the current directory or a parent
RULES := $(firstword $(wildcard $(foreach D,. .. ../.. ../../..,$D/Makefile.defs)))
# Let the user know where we found Makefile.defs
$(warning include $(RULES))

# You may simply this by simply defining MODULE and removing the part
# that includes Makefile.ex.
ifdef MODULE
  include $(RULES)
else
# Following makefile has two purposes:
# 1. Automatically determines the MODULE name and creates a MODULE.log
#    file record of the make activities. This is not strictly needed
#    if MODULE is defined. This also works either above or within the
#    target example directory.
# 2. There is a convenience 'all' target.
# 3. For the developer, several targets aid creation of
#    the examples. None of this is required for compilation of the
#    examples.
  include Makefile.ex
endif

# COPYRIGHT (C) 2004 Eklectic Ally, Inc.---------------------------{{{#
# See EKLECTIC_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}#
#END $Id: Makefile,v 1.4 2004/05/07 13:51:24 dcblack Exp $
