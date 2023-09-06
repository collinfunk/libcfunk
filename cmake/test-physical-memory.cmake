
include_guard(GLOBAL)

add_executable(test-physical-memory)

target_link_libraries(test-physical-memory PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-physical-memory PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-physical-memory.c
)

set_target_properties(test-physical-memory PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
