
include_guard(GLOBAL)

add_executable(test-getpagesize)

target_link_libraries(test-getpagesize PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-getpagesize PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-getpagesize.c
)

set_target_properties(test-getpagesize PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
