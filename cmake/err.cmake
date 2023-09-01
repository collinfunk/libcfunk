
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/program-name.cmake)

libcfunk_check_include_file("err.h" HAVE_ERR_H)
libcfunk_check_symbol_exists(err "err.h" HAVE_ERR)
libcfunk_check_symbol_exists(verr "err.h" HAVE_VERR)
libcfunk_check_symbol_exists(errc "err.h" HAVE_ERRC)
libcfunk_check_symbol_exists(verrc "err.h" HAVE_VERRC)
libcfunk_check_symbol_exists(errx "err.h" HAVE_ERRX)
libcfunk_check_symbol_exists(verrx "err.h" HAVE_VERRX)
libcfunk_check_symbol_exists(warn "err.h" HAVE_WARN)
libcfunk_check_symbol_exists(vwarn "err.h" HAVE_VWARN)
libcfunk_check_symbol_exists(warnc "err.h" HAVE_WARNC)
libcfunk_check_symbol_exists(vwarnc "err.h" HAVE_VWARNC)
libcfunk_check_symbol_exists(warnx "err.h" HAVE_WARNX)
libcfunk_check_symbol_exists(vwarnx "err.h" HAVE_VWARNX)

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

libcfunk_add_sources("err.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-err.cmake)
endif ()

