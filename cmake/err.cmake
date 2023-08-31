
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/program-name.cmake)

check_include_file("err.h" HAVE_ERR_H)
check_symbol_exists(err "err.h" HAVE_ERR)
check_symbol_exists(verr "err.h" HAVE_VERR)
check_symbol_exists(errc "err.h" HAVE_ERRC)
check_symbol_exists(verrc "err.h" HAVE_VERRC)
check_symbol_exists(errx "err.h" HAVE_ERRX)
check_symbol_exists(verrx "err.h" HAVE_VERRX)
check_symbol_exists(warn "err.h" HAVE_WARN)
check_symbol_exists(vwarn "err.h" HAVE_VWARN)
check_symbol_exists(warnc "err.h" HAVE_WARNC)
check_symbol_exists(vwarnc "err.h" HAVE_VWARNC)
check_symbol_exists(warnx "err.h" HAVE_WARNX)
check_symbol_exists(vwarnx "err.h" HAVE_VWARNX)

set(LIBCFUNK_GENERATE_ERR_H TRUE)
set(LIBCFUNK_DECLARE_ERR 1)
set(LIBCFUNK_DECLARE_VERR 1)
set(LIBCFUNK_DECLARE_ERRC 1)
set(LIBCFUNK_DECLARE_VERRC 1)
set(LIBCFUNK_DECLARE_ERRX 1)
set(LIBCFUNK_DECLARE_VERRX 1)
set(LIBCFUNK_DECLARE_WARN 1)
set(LIBCFUNK_DECLARE_VWARN 1)
set(LIBCFUNK_DECLARE_WARNC 1)
set(LIBCFUNK_DECLARE_VWARNC 1)
set(LIBCFUNK_DECLARE_WARNX 1)
set(LIBCFUNK_DECLARE_VWARNX 1)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/err.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-err.cmake)
endif ()

if (NOT HAVE_ERR_H)
  set(HAVE_ERR_H 0)
endif ()

if (NOT HAVE_ERR)
  set(HAVE_ERR 0)
endif ()

if (NOT HAVE_VERR)
  set(HAVE_VERR 0)
endif ()

if (NOT HAVE_ERRC)
  set(HAVE_ERRC 0)
endif ()

if (NOT HAVE_VERRC)
  set(HAVE_VERRC 0)
endif ()

if (NOT HAVE_ERRX)
  set(HAVE_ERRX 0)
endif ()

if (NOT HAVE_VERRX)
  set(HAVE_VERRX 0)
endif ()

if (NOT HAVE_WARN)
  set(HAVE_WARN 0)
endif ()

if (NOT HAVE_VWARN)
  set(HAVE_VWARN 0)
endif ()

if (NOT HAVE_WARNC)
  set(HAVE_WARNC 0)
endif ()

if (NOT HAVE_VWARNC)
  set(HAVE_VWARNC 0)
endif ()

if (NOT HAVE_WARNX)
  set(HAVE_WARNX 0)
endif ()

if (NOT HAVE_VWARNX)
  set(HAVE_VWARNX 0)
endif ()
