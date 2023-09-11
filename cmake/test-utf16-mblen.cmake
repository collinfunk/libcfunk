
include_guard(GLOBAL)

add_executable(test-utf16-mblen)

target_link_libraries(test-utf16-mblen PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-utf16-mblen PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-utf16-mblen.c
)

set_target_properties(test-utf16-mblen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
