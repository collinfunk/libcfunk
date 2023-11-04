
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/realloc.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("reallocf" "stdlib.h" HAVE_REALLOCF)
endif ()

set(LIBCFUNK_DECLARE_REALLOCF "1" CACHE INTERNAL "")

if (NOT HAVE_REALLOCF)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/reallocf.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-reallocf.cmake)
endif ()
