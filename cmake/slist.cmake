
include_guard(GLOBAL)

libcfunk_add_sources("slist.h;slist.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-slist.cmake)
endif ()
