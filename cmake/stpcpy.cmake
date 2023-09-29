include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("stpcpy" "string.h")

set(LIBCFUNK_DECLARE_STPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_STPCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/stpcpy.c
  )
endif ()
