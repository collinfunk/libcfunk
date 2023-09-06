include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcat" "string.h" HAVE_STRCAT)
else ()
  set(HAVE_STRCAT "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRCAT "1" CACHE INTERNAL "")

if (NOT HAVE_STRCAT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcat.c
  )
endif ()