
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

check_c_symbol("ftello" "stdio.h")
check_c_symbol("ftell" "stdio.h")
check_c_symbol("_ftelli64" "stdio.h")

set(LIBCFUNK_DECLARE_FTELLO "1" CACHE INTERNAL "")

if (NOT HAVE_FTELLO)
  if (NOT HAVE_FTELL AND NOT HAVE__FTELLI64)
    message(FATAL_ERROR "Cannot find an implementation for ftello.")
  elseif (NOT HAVE__FTELLI64)
    message(WARNING "Using ftell as a replacement for ftello. This may \
cause unexpected behavior on large files.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ftello.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ftello.cmake)
endif ()

