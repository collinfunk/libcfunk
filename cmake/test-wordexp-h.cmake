
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-wordexp-h)

target_link_libraries(test-wordexp-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-wordexp-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-wordexp-h.c
)

set_target_properties(test-wordexp-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-wordexp-h" COMMAND test-wordexp-h)
