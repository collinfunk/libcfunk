
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/read-nointr.cmake)

libcfunk_add_sources("read-full.h;read-full.c")

if (LIBCFUNK_BUILD_TESTS)
  # This test uses them both, even though they can be used seperatly
  include(${LIBCFUNK_MODULE_DIR}/write-full.cmake)
  include(${LIBCFUNK_MODULE_DIR}/test-read-write-full.cmake)
endif ()

