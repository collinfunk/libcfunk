
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)

add_executable(test-timingsafe-bcmp)

target_link_libraries(test-timingsafe-bcmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-timingsafe-bcmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-timingsafe-bcmp.c
)

set_target_properties(test-timingsafe-bcmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-timingsafe-bcmp" COMMAND test-timingsafe-bcmp)
