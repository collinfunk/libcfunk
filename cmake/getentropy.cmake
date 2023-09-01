
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/sys-random.cmake)
include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

libcfunk_check_symbol_exists(getentropy "unistd.h;sys/random.h" HAVE_GETENTROPY)

set(LIBCFUNK_DECLARE_GETENTROPY 1)

if (NOT HAVE_GETENTROPY)
  libcfunk_add_sources("getentropy.c")
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getentropy.cmake)
endif ()

