
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

if (HAVE_SIGNAL_H)
  check_symbol_exists("str2sig" "string.h" HAVE_STR2SIG)
  check_symbol_exists("sig2str" "string.h" HAVE_SIG2STR)
endif ()

set(LIBCFUNK_DECLARE_STR2SIG "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SIG2STR "1" CACHE INTERNAL "")

if (NOT HAVE_STR2SIG OR NOT HAVE_SIG2STR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/str2sig.c
  )
endif ()

