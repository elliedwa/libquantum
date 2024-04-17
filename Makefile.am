AM_CPPFLAGS = -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3 -D_GLIBCXX_ASSERTIONS
AM_CFLAGS = -Wall -Wextra -Wformat -Wformat=2 -Wconversion \
		-Werror=implicit -Werror=incompatible-pointer-types \
		-Werror=int-conversion  -fstrict-flex-arrays=3 -fstack-clash-protection \
		-fstack-protector-strong -Wtrampolines -Wbidi-chars=any
AM_LDFLAGS = -Wl,-z,nodlopen -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now

noinst_LIBRARIES = libtap.a libelaerr.a libelablock.a \
									 libelavector.a

check_PROGRAMS = test_block test_vector
test_block_LDADD = libelablock.a libelaerr.a libtap.a
test_block_SOURCES = src/ela/block/test_block.c

test_vector_LDADD = libelavector.a libelablock.a libelaerr.a libtap.a
test_vector_SOURCES = src/ela/vector/test_vector.c

pkginclude_HEADERS = src/ela/err/ela_error.h \
										 src/ela/block/ela_block.h \
										 src/ela/block/ela_block_double.h \
										 src/ela/block/ela_block_complex_double.h  \
										 src/ela/vector/ela_vector.h \
										 src/ela/vector/ela_vector_double.h
libelaerr_a_SOURCES = src/ela/err/error.c
libtap_a_SOURCES = src/ela/test/tap.c src/ela/test/tap.h
libelablock_a_SOURCES = src/ela/block/block.c src/ela/block/init.c
libelavector_a_SOURCES = src/ela/vector/vector.c \
												 src/ela/vector/init.c



TEST_LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
									$(top_srcdir)/build-aux/tap-driver.sh

TESTS = $(check_PROGRAMS)


