
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-stpcpy)

target_link_libraries(test-stpcpy PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stpcpy PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stpcpy.c
)

set_target_properties(test-stpcpy PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stpcpy" COMMAND test-stpcpy)
