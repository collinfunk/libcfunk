
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memset_explicit" "string.h" HAVE_MEMSET_EXPLICIT)
else ()
  set(HAVE_MEMSET_EXPLICIT "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMSET_EXPLICIT "1" CACHE INTERNAL "")

if (NOT HAVE_MEMSET_EXPLICIT)
  check_symbol_exists("memset_s" "string.h" HAVE_MEMSET_S)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memset-explicit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-memset-explicit.cmake)
endif ()
