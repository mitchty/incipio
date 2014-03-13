AUTOMAKE_OPTIONS = foreign std-options
SUFFIXES = .yucc
DISTCLEANFILES = incipio.yucc
EXTRA_DIST = $(BUILT_SOURCES)
EXTRA_DIST += autogen.sh
EXTRA_DIST += incipio.yucc
EXTRA_DIST += incipio.yuck

bin_PROGRAMS = incipio
incipio_SOURCES = incipio.c
incipio_SOURCES += incipio.yucc

# Be explicit about our dependence on this generated file.
incipio.c: incipio.yucc

# Only useful for development.
.yuck.yucc:
	yuck gen -o $@ $<

# Not really needed but useful at times.
cleanall: clean distclean
	-rm -fr autom4te.cache
	-rm -f Makefile Makefile.in aclocal.m4 compile config.h.in configure depcomp install-sh missing incipio-*.tar.gz
