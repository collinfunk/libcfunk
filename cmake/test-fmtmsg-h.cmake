
include_guard(GLOBAL)

add_executable(test-fmtmsg-h)

target_link_libraries(test-fmtmsg-h PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fmtmsg-h PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fmtmsg-h.c
)

set_target_properties(test-fmtmsg-h PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fmtmsg-h" COMMAND test-fmtmsg-h)
