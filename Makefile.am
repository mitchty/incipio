SUFFIXES = .yucc
DISTCLEANFILES = incipio.yucc
EXTRA_DIST = $(BUILT_SOURCES)
EXTRA_DIST += autogen
EXTRA_DIST += incipio.yucc
EXTRA_DIST += incipio.yuck

bin_PROGRAMS = incipio
incipio_SOURCES = incipio.c
incipio_SOURCES += incipio.yucc
incipio_SOURCES += version.c
incipio_CPPFLAGS = -DHAVE_VERSION_H

if HAVE_GIT
if HAVE_GIT_DIR
GIT_VERSION = $(shell git rev-parse --short HEAD)
GIT_DESCRIBE = $(shell git describe --dirty=-modified | sed -e 's/^v//g')
incipio_CPPFLAGS += -DGIT_VERSION="\"$(shell echo $(GIT_DESCRIBE) | grep $(GIT_VERSION) > /dev/null 2>&1 && echo $(GIT_DESCRIBE) || echo $(GIT_DESCRIBE).$(GIT_VERSION))\""
endif
endif

if HAVE_ASCIIDOC
incipio.1: incipio.1.txt
	a2x -d manpage -f manpage $<
endif

if HAVE_YUCK
incipio.c: incipio.yucc version.c
.yuck.yucc:
	yuck gen -o $@ $<
else
incipio.c: version.c
endif

# Not really needed but useful at times.
cleanall: clean distclean
	-rm -fr autom4te.cache
	-rm -f Makefile Makefile.in aclocal.m4 compile config.h.in configure depcomp install-sh missing incipio-*.tar.* *~
