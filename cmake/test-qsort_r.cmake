
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)

add_executable(test-qsort_r)

target_link_libraries(test-qsort_r PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-qsort_r PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-qsort_r.c
)

set_target_properties(test-qsort_r PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-qsort_r" COMMAND test-qsort_r)
