
include_guard(GLOBAL)

add_executable(test-copysignl)

target_link_libraries(test-copysignl PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-copysignl PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-copysignl.c
)

set_target_properties(test-copysignl PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-copysignl" COMMAND test-copysignl)
