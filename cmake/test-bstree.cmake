
include_guard(GLOBAL)

add_executable(test-bstree)

target_link_libraries(test-bstree PRIVATE ${LIBCFUNK_LIBRARY_NAME})

target_sources(test-bstree PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-bstree.c
)

set_target_properties(test-bstree PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
