
include_guard(GLOBAL)

add_executable(test-utf32-mblen)

target_link_libraries(test-utf32-mblen PRIVATE
  ${LIBCFUNK_LIBRARY_NAME}
)

target_sources(test-utf32-mblen PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-utf32-mblen.c
)

set_target_properties(test-utf32-mblen PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
