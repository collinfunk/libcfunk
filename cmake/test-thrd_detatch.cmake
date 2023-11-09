
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/thrd_create.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/thrd_join.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/thrd_sleep.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/thrd_current.cmake)

add_executable(test-thrd_detatch)

target_link_libraries(test-thrd_detatch PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-thrd_detatch PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-thrd_detatch.c
)

set_target_properties(test-thrd_detatch PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-thrd_detatch" COMMAND test-thrd_detatch)
