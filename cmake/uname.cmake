
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-utsname-h.cmake)

if (HAVE_SYS_UTSNAME_H)
  check_symbol_exists("uname" "sys/utsname.h" HAVE_UNAME)
endif ()

set(LIBCFUNK_DECLARE_UNAME "1" CACHE INTERNAL "")

if (NOT HAVE_UNAME)
  include($CACHE{LIBCFUNK_MODULE_DIR}/gethostname.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/uname.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-uname.cmake)
endif ()

