dnl Replace all this as appropriate

AC_INIT([incipio], [0.0.2], [https://example.com/foo/bar/incipio])
AC_CONFIG_SRCDIR([.])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([.])
AC_PROG_CC
AC_LANG([C])

dnl check for git/yuck/asciidoc
AC_CHECK_PROGS([GIT], [git])
AC_CHECK_PROGS([YUCK], [yuck])
AC_CHECK_PROGS([ASCIIDOC], [a2x])

if test -z "$GIT"; then
  AC_MSG_WARN([Git not detected, cannot compile with git version information.])
fi

if test -z "$YUCK"; then
  AC_MSG_WARN([yuck not detected, cannot generate arg parser.])
fi

if test -z "$ASCIIDOC"; then
  AC_MSG_WARN([a2x not detected, cannot generate man page.])
fi

AM_CONDITIONAL([HAVE_GIT], [test -n "$GIT"])
AM_CONDITIONAL([HAVE_YUCK], [test -n "$YUCK"])
AM_CONDITIONAL([HAVE_ASCIIDOC], [test -n "$ASCIIDOC"])
AM_CONDITIONAL([HAVE_GIT_DIR], [test -d .git])

AM_INIT_AUTOMAKE([foreign dist-bzip2 dist-xz subdir-objects std-options])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
