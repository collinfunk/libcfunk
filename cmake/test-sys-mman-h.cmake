
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-sys-mman-h)

target_link_libraries(test-sys-mman-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-mman-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-mman-h.c
)

set_target_properties(test-sys-mman-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-mman-h" COMMAND test-sys-mman-h)
