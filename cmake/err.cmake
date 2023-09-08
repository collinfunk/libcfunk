
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/err-h.cmake)

if (HAVE_ERR_H)
  check_symbol_exists("err" "err.h" HAVE_ERR)
  check_symbol_exists("verr" "err.h" HAVE_VERR)
  check_symbol_exists("errc" "err.h" HAVE_ERRC)
  check_symbol_exists("verrc" "err.h" HAVE_VERRC)
  check_symbol_exists("errx" "err.h" HAVE_ERRX)
  check_symbol_exists("verrx" "err.h" HAVE_VERRX)
  check_symbol_exists("warn" "err.h" HAVE_WARN)
  check_symbol_exists("vwarn" "err.h" HAVE_VWARN)
  check_symbol_exists("warnc" "err.h" HAVE_WARNC)
  check_symbol_exists("vwarnc" "err.h" HAVE_VWARNC)
  check_symbol_exists("warnx" "err.h" HAVE_WARNX)
  check_symbol_exists("vwarnx" "err.h" HAVE_VWARNX)
else ()
  set(HAVE_ERR "" CACHE INTERNAL "")
  set(HAVE_VERR "" CACHE INTERNAL "")
  set(HAVE_ERRC "" CACHE INTERNAL "")
  set(HAVE_VERRC "" CACHE INTERNAL "")
  set(HAVE_ERRX "" CACHE INTERNAL "")
  set(HAVE_VERRX "" CACHE INTERNAL "")
  set(HAVE_WARN "" CACHE INTERNAL "")
  set(HAVE_VWARN "" CACHE INTERNAL "")
  set(HAVE_WARNC "" CACHE INTERNAL "")
  set(HAVE_VWARNC "" CACHE INTERNAL "")
  set(HAVE_WARNX "" CACHE INTERNAL "")
  set(HAVE_VWARNX "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_ERR OR NOT HAVE_VERR OR NOT HAVE_ERRC OR NOT HAVE_VERRC
    OR NOT HAVE_ERRX OR NOT HAVE_VERRX OR NOT HAVE_WARN OR NOT HAVE_VWARN
    OR NOT HAVE_WARNC OR NOT HAVE_VWARNC OR NOT HAVE_WARNX OR NOT HAVE_VWARNX)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/err.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-err.cmake)
endif ()
