
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/memcmp.cmake)

add_executable(test-argz_create)

target_link_libraries(test-argz_create PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-argz_create PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-argz_create.c
)

set_target_properties(test-argz_create PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-argz_create" COMMAND test-argz_create)
