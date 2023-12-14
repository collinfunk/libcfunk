
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

add_executable(test-utmp-h)

target_link_libraries(test-utmp-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-utmp-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-utmp-h.c
)

set_target_properties(test-utmp-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-utmp-h" COMMAND test-utmp-h)
