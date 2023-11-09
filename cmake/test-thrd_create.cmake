
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/thrd_join.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-thrd_create)

target_link_libraries(test-thrd_create PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_create PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_create.c
)

set_target_properties(test-thrd_create PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_create" COMMAND test-thrd_create)
