
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wcstok" "wchar.h" HAVE_WCSTOK)
  if (HAVE_WCSTOK)
    check_c_source_compiles("
    #include <wchar.h>
    extern wchar_t *wcstok (wchar_t *, const wchar_t *, wchar_t **);
    int
    main (void)
    {
      return 0;
    }
    " WCSTOK_HAS_POSIX_PROTOTYPE)
    if (NOT WCSTOK_HAS_POSIX_PROTOTYPE)
      set(LIBCFUNK_REPLACE_WCSTOK "1" CACHE STRING "")
    endif ()
  endif ()
endif ()

set(LIBCFUNK_DECLARE_WCSTOK "1" CACHE STRING "")

if (NOT HAVE_WCSTOK OR LIBCFUNK_REPLACE_WCSTOK)
  include($CACHE{LIBCFUNK_MODULE_DIR}/wcsspn.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/wcscspn.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wcstok.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wcstok.cmake)
endif ()

