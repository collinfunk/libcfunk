
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

check_c_symbol("fseeko" "stdio.h")
check_c_symbol("fseek" "stdio.h")
check_c_symbol("_fseeki64" "stdio.h")

set(LIBCFUNK_DECLARE_FSEEKO "1" CACHE INTERNAL "")

if (NOT HAVE_FSEEKO)
  if (NOT HAVE_FSEEK AND NOT HAVE__FSEEKI64)
    message(FATAL_ERROR "Cannot find an implementation for fseeko.")
  elseif (NOT HAVE__FSEEKI64)
    message(WARNING "Using fseek as a replacement for fseeko. This may \
cause unexpected behavior on large files.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fseeko.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fseeko.cmake)
endif ()

