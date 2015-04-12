The following instructions are an aid to using the files that accompany
the second edition of the book "SystemC: From the Ground Up", by David
Black, Jack Donovan, Bill Bunton and Anna Keist.

These files are licensed for use exclusively by readers of the book that
have access to a legally purchased a copy of the book. This includes
students with access to library copies. We do ask that you not republish
these files without contacting us and obtaining explicit written (e-mail
is fine) permission. You may use extracts of the examples in your own
work without licensing restrictions; however, they come with no warranty
of fitness or lack of defects. Use at your own risk.

The exercises and examples are divided into sub-directories corresponding to
the various chapters in the 2nd edition. Exercises provide only what you need
to get started on the various suggested exercises and no more. That is to say,
we are not supplying solutions to all the problems. You will also find some
examples that are not used as exercises, but think will be useful in your
comprehension of the material.

HOW TO COMPILE

In order to compile these exercises, you will need to meet a few
pre-requisites. You will need the following tools or their equivalent:

A reasonably complete and standards compliant C++ compiler and linker.
If you plan on using the GNU Compiler Collection (GCC), we highly
recommend using versions 4.1 or better. Any reasonably recent
installation of Linux will probably be sufficient. Versions older than
4.1 may not be able to take advantage of some of the newer libraries
released by OSCI.

You will likely find the need for a debugger. If you are unable to
purchase a good commercial debugger, we suggest at least having access
to gdb or ddd.

An installation of SystemC corresponding to IEEE-1666-2005. The OSCI
proof-of-concept version 2.2, which is freely available as open-source
from http://www.systemc.org will do nicely. You should also obtain a
copy of TLM 2.0.1. Follow the installation instructions carefully. Once
installed, you should setup an environment variable named SYSTEMC_HOME
to contain a path to the top of the installation location (just above
the include/ directory).

An installation of the Boost library version 1.38 or newer will help
with a couple of the exercises and it can be quite useful for a lot of
modeling problems.  Once installed, you should set the environment
variable BOOST_HOME to point to the installation location.

Copyright 2010 sftgu.com. All rights reserved.

