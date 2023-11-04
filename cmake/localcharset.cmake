
include_guard(GLOBAL)

check_include_file("langinfo.h" HAVE_LANGINFO_H)
check_include_file("locale.h" HAVE_LOCALE_H)
check_include_file("xlocale.h" HAVE_XLOCALE_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("winnls.h" HAVE_WINNLS_H)

if (HAVE_LANGINFO_H)
  check_symbol_exists("nl_langinfo" "langinfo.h" HAVE_NL_LANGINFO)
  if (HAVE_NL_LANGINFO)
    check_symbol_exists("CODESET" "langinfo.h" HAVE_NL_LANGINFO_CODESET)
  endif ()
endif ()

if (HAVE_LOCALE_H)
  check_symbol_exists("setlocale" "locale.h" HAVE_SETLOCALE)
endif ()

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/localcharset.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/localcharset.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-localcharset.cmake)
endif ()

