
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/malloc-h.cmake)

check_include_file("stdlib.h" HAVE_STDLIB_H)

# The memalign function might be in stdlib.h or malloc.h.
if (HAVE_MALLOC_H OR HAVE_STDLIB_H)
  set(MEMALIGN_INCLUDES "")
  if (HAVE_MALLOC_H)
    list(APPEND MEMALIGN_INCLUDES "malloc.h")
  endif ()
  if (HAVE_STDLIB_H)
    list(APPEND MEMALIGN_INCLUDES "stdlib.h")
  endif ()
  check_symbol_exists("memalign" "${MEMALIGN_INCLUDES}" HAVE_MEMALIGN)
  unset(MEMALIGN_INCLUDES)
endif ()

# TODO
if (NOT HAVE_MEMALIGN)
  message(FATAL_ERROR "No implementation of 'memalign' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-memalign.cmake)
endif ()

