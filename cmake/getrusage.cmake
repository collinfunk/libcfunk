
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-resource-h.cmake)

if (HAVE_SYS_RESOURCE_H)
  check_symbol_exists("getrusage" "sys/resource.h" HAVE_GETRUSAGE)
endif ()

set(LIBCFUNK_DECLARE_GETRUSAGE "1" CACHE INTERNAL "")

if (NOT HAVE_GETRUSAGE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getrusage.c
  )
endif ()

