include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memmove" "string.h" HAVE_MEMMOVE)
else ()
  set(HAVE_MEMMOVE "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMMOVE "1" CACHE INTERNAL "")

if (NOT HAVE_MEMMOVE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memmove.c
  )
endif ()