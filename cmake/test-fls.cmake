
include_guard(GLOBAL)

add_executable(test-fls)

target_link_libraries(test-fls PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-fls PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-fls.c
)

set_target_properties(test-fls PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
