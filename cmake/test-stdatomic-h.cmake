
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-stdatomic-h)

target_link_libraries(test-stdatomic-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdatomic-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdatomic-h.c
)

set_target_properties(test-stdatomic-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdatomic-h" COMMAND test-stdatomic-h)
