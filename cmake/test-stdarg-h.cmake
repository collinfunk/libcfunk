
include_guard(GLOBAL)

add_executable(test-stdarg-h)

target_link_libraries(test-stdarg-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-stdarg-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-stdarg-h.c
)

set_target_properties(test-stdarg-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-stdarg-h" COMMAND test-stdarg-h)
