
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

add_executable(test-timingsafe-bcmp)

target_link_libraries(test-timingsafe-bcmp PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-timingsafe-bcmp PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-timingsafe-bcmp.c
)

set_target_properties(test-timingsafe-bcmp PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
