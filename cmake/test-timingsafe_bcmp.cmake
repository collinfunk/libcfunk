
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)

add_executable(test-timingsafe_bcmp)

target_link_libraries(test-timingsafe_bcmp PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-timingsafe_bcmp PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-timingsafe_bcmp.c
)

set_target_properties(test-timingsafe_bcmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-timingsafe_bcmp" COMMAND test-timingsafe_bcmp)
