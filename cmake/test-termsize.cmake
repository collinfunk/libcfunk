
include_guard(GLOBAL)

add_executable(test-termsize)

target_link_libraries(test-termsize PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-termsize PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-termsize.c
)

set_target_properties(test-termsize PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
