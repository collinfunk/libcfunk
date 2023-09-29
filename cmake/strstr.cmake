
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strncmp.cmake)

check_c_symbol("strstr" "string.h")

set(LIBCFUNK_DECLARE_STRSTR "1" CACHE INTERNAL "")

if (NOT HAVE_STRSTR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strstr.c
  )
endif ()
