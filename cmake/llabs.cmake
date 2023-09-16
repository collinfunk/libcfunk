
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("llabs" "stdlib.h" HAVE_LLABS)
else ()
  set(HAVE_LLABS "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_LLABS "1" CACHE INTERNAL "")

if (NOT HAVE_LLABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/llabs.c
  )
endif ()
