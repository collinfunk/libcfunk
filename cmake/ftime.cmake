
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-timeb-h.cmake)

if (HAVE_SYS_TIMEB_H)
  check_symbol_exists("ftime" "sys/timeb.h" HAVE_FTIME)
endif ()

# TODO
if (NOT HAVE_FTIME)
  message(FATAL_ERROR "No implementation of 'ftime' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

