
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/open.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/write.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/pipe.cmake)

add_executable(test-lseek)

target_link_libraries(test-lseek PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-lseek PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-lseek.c
)

set_target_properties(test-lseek PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-lseek" COMMAND test-lseek)
