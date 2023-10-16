
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("lseek" "unistd.h" HAVE_LSEEK)
  check_symbol_exists("_lseeki64" "unistd.h" HAVE__LSEEKI64)
else ()
  set(HAVE_LSEEK "" CACHE INTERNAL "")
  set(HAVE__LSEEKI64 "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_LSEEK "1" CACHE INTERNAL "")

if (NOT HAVE_LSEEK)
  if (NOT HAVE__LSEEKI64)
    message(FATAL_ERROR "No implementation for 'lseek' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/lseek.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-lseek.cmake)
endif ()

