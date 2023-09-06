
include_guard(GLOBAL)

add_executable(test-stat-timespec)

target_link_libraries(test-stat-timespec PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-stat-timespec PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-stat-timespec.c
)

set_target_properties(test-stat-timespec PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
