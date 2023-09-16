
include_guard(GLOBAL)

add_executable(test-_Noreturn)

target_link_libraries(test-_Noreturn PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-_Noreturn PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-_Noreturn.c
)

set_target_properties(test-_Noreturn PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
