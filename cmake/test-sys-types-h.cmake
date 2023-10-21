
include_guard(GLOBAL)

# Windows might define 'time.h' here instead of sys/types.h.
include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

add_executable(test-sys-types-h)

target_link_libraries(test-sys-types-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-sys-types-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-sys-types-h.c
)

set_target_properties(test-sys-types-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-sys-types-h" COMMAND test-sys-types-h)
