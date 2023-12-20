
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)

add_executable(test-qsort)

target_link_libraries(test-qsort PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-qsort PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-qsort.c
)

set_target_properties(test-qsort PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-qsort" COMMAND test-qsort)
