# Automakefile for the audiowav project by Curtis Sand.
# https://bitbucket.org/fret/audiowav.git

# Always set this so that we can just '#include "SRCFILE"', for any SRCFILE
# under the "src" dir, from anywhere, including our tests directory.
AM_CPPFLAGS = -I$(top_srcdir)/src -std=c++17

bin_PROGRAMS = audiowav

audiowav_SOURCES = \
  src/main.cpp \
  src/wavegen.hpp \
	src/wavegen.cpp \
	src/logging.hpp \
	src/dsound.hpp \
	src/dsound.cpp \
	src/util.hpp \
	src/util.cpp

audiowav_CXXFlags = $$(pkg-config --cflags sndfile)
audiowav_LDFLAGS = $$(pkg-config --libs sndfile)

# Testing setup. Type 'make check' or 'make recheck' to run the tests.
# TESTS defines a list of tests to run. Define their sources in the usual way.
TEST_FLAGS = $(AM_CPPFLAGS) -I$(top_srcdir)/google-test/include \
-DGTEST_OS_CYGWIN=1 -DGTEST_HAS_PTHREAD=1
TEST_LIBS = $(top_srcdir)/google-test/make/gtest_main.a
THE_TESTS = tests/wavegen tests/util
TESTS = $(THE_TESTS)
check_PROGRAMS = $(THE_TESTS)


tests_wavegen_SOURCES = tests/wavegen_test.cpp \
  src/wavegen.hpp \
	src/wavegen.cpp \
	src/logging.hpp \
	src/dsound.hpp \
	src/dsound.cpp

tests_wavegen_CPPFLAGS = $(TEST_FLAGS)
tests_wavegen_LDADD =  $(TEST_LIBS)
tests_wavegen_LDFLAGS = -pthread

tests_util_SOURCES = tests/util_test.cpp \
  src/wavegen.hpp \
	src/wavegen.cpp \
	src/logging.hpp \
	src/dsound.hpp \
	src/dsound.cpp

tests_util_CPPFLAGS = $(TEST_FLAGS)
tests_util_LDADD =  $(TEST_LIBS)
tests_util_LDFLAGS = -pthread
