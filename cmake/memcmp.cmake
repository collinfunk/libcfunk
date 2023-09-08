include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memcmp" "string.h" HAVE_MEMCMP)
else ()
  set(HAVE_MEMCMP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMCMP "1" CACHE INTERNAL "")

if (NOT HAVE_MEMCMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memcmp.c
  )
endif ()