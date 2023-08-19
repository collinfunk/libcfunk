
include_guard(GLOBAL)

add_executable(test-getdelim)

target_link_libraries(test-getdelim PRIVATE ${LIBCFUNK_LIBRARY_NAME})

include(${LIBCFUNK_MODULE_DIR}/getline.cmake)

target_sources(test-getdelim PRIVATE
  ${LIBCFUNK_TEST_SOURCE_DIR}/test-getdelim.c
)

set_target_properties(test-getdelim PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${LIBCFUNK_TEST_BUILD_DIR}
)
