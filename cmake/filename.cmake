
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdbool-h.cmake)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/filename.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/filename.h
)

if ($CACHE{LIBCFUNK_ENABLE_TESTS})
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-macros.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-last-component.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-strip-extension.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-strip-slashes.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-join-extension.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-filename-join-directory.cmake)
endif ()
