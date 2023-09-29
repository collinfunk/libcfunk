
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/err-h.cmake)

check_c_symbol("err" "err.h")
check_c_symbol("verr" "err.h")
check_c_symbol("errc" "err.h")
check_c_symbol("verrc" "err.h")
check_c_symbol("errx" "err.h")
check_c_symbol("verrx" "err.h")
check_c_symbol("warn" "err.h")
check_c_symbol("vwarn" "err.h")
check_c_symbol("warnc" "err.h")
check_c_symbol("vwarnc" "err.h")
check_c_symbol("warnx" "err.h")
check_c_symbol("vwarnx" "err.h")


if (NOT HAVE_ERR OR NOT HAVE_VERR OR NOT HAVE_ERRC OR NOT HAVE_VERRC
    OR NOT HAVE_ERRX OR NOT HAVE_VERRX OR NOT HAVE_WARN OR NOT HAVE_VWARN
    OR NOT HAVE_WARNC OR NOT HAVE_VWARNC OR NOT HAVE_WARNX OR NOT HAVE_VWARNX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/err.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-err.cmake)
endif ()

