#!/usr/bin/make -f
# -*- make -*- vim:syntax=make:tw=72
# COPYRIGHT (C) 2004,2007 Eklectic Ally, Inc. DBA ESLX Inc.--------{{{#
# See ESLX_LICENSE for information on legal usage of this file.   #
# -----------------------------------------------------------------}}}

SUBDIRS = $(filter-out ./,$(dir $(shell find . -name Makefile)))

.PHONY: all clean check run show

Ruler=echo "";echo "------------------------------------------------------------------------------------";echo "cd $$i && $(MAKE)"

all:
	@for i in $(SUBDIRS); do $(Ruler);(cd $$i && $(MAKE)); done

check:
	@for i in $(SUBDIRS); do $(Ruler);(cd $$i && $(MAKE) check); done

run:
	@for i in $(SUBDIRS); do $(Ruler);(cd $$i && $(MAKE) run); done

clean:
	@for i in $(SUBDIRS); do $(Ruler);(cd $$i && $(MAKE) clean); done


show:
	@for i in $(SUBDIRS); do echo "$$i"; done

#EOF
