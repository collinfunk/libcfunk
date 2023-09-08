include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strdup" "string.h" HAVE_STRDUP)
else ()
  set(HAVE_STRDUP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRDUP "1" CACHE INTERNAL "")

if (NOT HAVE_STRDUP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strdup.c
  )
endif ()