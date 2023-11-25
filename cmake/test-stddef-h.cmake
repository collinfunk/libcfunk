
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-stddef-h)

target_link_libraries(test-stddef-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stddef-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stddef-h.c
)

set_target_properties(test-stddef-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stddef-h" COMMAND test-stddef-h)
