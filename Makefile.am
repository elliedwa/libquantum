AM_CPPFLAGS = -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3 -D_GLIBCXX_ASSERTIONS
AM_CFLAGS = -Wall -Wextra -Wformat -Wformat=2 -Wconversion \
		-Werror=implicit -Werror=incompatible-pointer-types \
		-Werror=int-conversion  -fstrict-flex-arrays=3 -fstack-clash-protection \
		-fstack-protector-strong -Wtrampolines -Wbidi-chars=any
AM_LDFLAGS = -Wl,-z,nodlopen -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now

noinst_LIBRARIES = lib/libquantum.a
lib_libquantum_a_SOURCES = src/linear.c src/linear.h

LDADD = lib/libquantum.a
check_PROGRAMS = test/test_NP_CHECK \
		test/test_scalar_types_real \
		test/test_scalar_types_complex

DISABLE_HARD_ERRORS = true
TESTS = $(check_PROGRAMS)
XFAIL_TESTS = test/test_NP_CHECK
