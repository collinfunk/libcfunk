
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("lseek" "unistd.h" HAVE_LSEEK)
  check_symbol_exists("_lseeki64" "unistd.h" HAVE__LSEEKI64)
endif ()

set(LIBCFUNK_DECLARE_LSEEK "1" CACHE STRING "")

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_LSEEK "1" CACHE STRING "")
  check_symbol_exists("_lseeki64" "io.h" HAVE__LSEEKI64)
  if (NOT HAVE__LSEEKI64)
    check_symbol_exists("_lseek" "io.h" HAVE__LSEEK)
  endif ()
endif ()

if (NOT HAVE_LSEEK OR LIBCFUNK_REPLACE_LSEEK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/lseek.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-lseek.cmake)
endif ()

