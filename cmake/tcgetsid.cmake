
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/termios-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-ioctl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/tcgetsid.cmake)

if (HAVE_TERMIOS_H)
  check_symbol_exists("tcgetsid" "termios.h" HAVE_TCGETSID)
endif ()

set(LIBCFUNK_DECLARE_TCGETSID "1" CACHE STRING "")

if (NOT HAVE_TCGETSID)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tcgetsid.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tcgetsid.cmake)
endif ()

