
include_guard(GLOBAL)

add_executable(test-tcgetsid)

target_link_libraries(test-tcgetsid PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-tcgetsid PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-tcgetsid.c
)

set_target_properties(test-tcgetsid PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)
