#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([libquantum],[0.0.1])
AC_CONFIG_SRCDIR([src/ela/ela_macros.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects]) 

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([memset regcomp])


AC_CONFIG_FILES([ Makefile ])
AC_REQUIRE_AUX_FILE([tap-driver.sh])
AC_OUTPUT
