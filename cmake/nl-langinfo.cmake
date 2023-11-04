
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/locale-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/langinfo-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/localeconv.cmake)

if (HAVE_LANGINFO_H)
  check_symbol_exists("nl_langinfo" "langinfo.h" HAVE_NL_LANGINFO)
  if (HAVE_NL_LANGINFO)
    check_symbol_exists("CODESET" "langinfo.h" HAVE_NL_LANGINFO_CODESET)
  endif ()
endif ()

set(LIBCFUNK_DECLARE_NL_LANGINFO "1" CACHE INTERNAL "")

if (NOT HAVE_NL_LANGINFO)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/nl-langinfo.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nl-langinfo.cmake)
endif ()

