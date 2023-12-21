
include_guard(GLOBAL)

add_executable(test-stdnoreturn-h)

target_link_libraries(test-stdnoreturn-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdnoreturn-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdnoreturn-h.c
)

set_target_properties(test-stdnoreturn-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdnoreturn-h" COMMAND test-stdnoreturn-h)
