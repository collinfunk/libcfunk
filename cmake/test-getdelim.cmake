
include_guard(GLOBAL)

add_executable(test-getdelim)

target_link_libraries(test-getdelim PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-getdelim PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-getdelim.c
)

set_target_properties(test-getdelim PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

#add_test(NAME "test-getdelim" COMMAND test-getdelim)
