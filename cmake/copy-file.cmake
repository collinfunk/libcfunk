
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/read-nointr.cmake)
include(${LIBCFUNK_MODULE_DIR}/write-full.cmake)

libcfunk_add_sources("copy-file.h;copy-file.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-copy-file.cmake)
endif ()
