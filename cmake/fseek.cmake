
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

set(LIBCFUNK_DECLARE_FSEEK "1" CACHE STRING "")
set(LIBCFUNK_REPLACE_FSEEK "1" CACHE STRING "")

if (LIBCFUNK_REPLACE_FSEEK)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fseeko.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fseek.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fseek.cmake)
endif ()

