
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/remove.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/creat.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/close.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stat.cmake)

add_executable(test-fchmod)

target_link_libraries(test-fchmod PRIVATE
  "$CACHE{LIBCFUNK_LIBRARY_NAME}"
)

target_sources(test-fchmod PRIVATE
  $CACHE{LIBCFUNK_TEST_SOURCE_DIR}/test-fchmod.c
)

set_target_properties(test-fchmod PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY $CACHE{LIBCFUNK_TEST_BUILD_DIR}
)

add_test(NAME "test-fchmod" COMMAND test-fchmod)
