
include_guard(GLOBAL)

add_executable(test-basename)

target_link_libraries(test-basename PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-basename PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-basename.c
)

set_target_properties(test-basename PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
