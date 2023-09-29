include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_c_symbol("swab" "unistd.h")

set(LIBCFUNK_DECLARE_SWAB "1" CACHE INTERNAL "")

if (NOT HAVE_SWAB)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/swab.c
  )
endif ()
