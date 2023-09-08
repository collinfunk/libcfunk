include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strncmp" "string.h" HAVE_STRNCMP)
else ()
  set(HAVE_STRNCMP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRNCMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCMP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncmp.c
  )
endif ()