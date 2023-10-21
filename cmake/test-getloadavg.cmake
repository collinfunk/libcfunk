
include_guard(GLOBAL)

add_executable(test-getloadavg)

target_link_libraries(test-getloadavg PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getloadavg PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getloadavg.c
)

set_target_properties(test-getloadavg PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-getloadavg" COMMAND test-getloadavg)
