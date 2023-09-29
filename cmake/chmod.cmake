
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

check_c_symbol("chmod" "sys/stat.h")

set(LIBCFUNK_DECLARE_CHMOD "1" CACHE INTERNAL "")

if (NOT HAVE_CHMOD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/chmod.c
  )
endif ()
