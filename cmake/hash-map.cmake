
include_guard(GLOBAL)

libcfunk_add_sources("hash-map.h;hash-map.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-hash-map.cmake)
endif ()

