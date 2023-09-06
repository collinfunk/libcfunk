
include_guard(GLOBAL)

add_executable(test-alloca)

target_link_libraries(test-alloca PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-alloca PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-alloca.c
)

set_target_properties(test-alloca PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
