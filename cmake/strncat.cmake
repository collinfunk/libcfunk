include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strncat" "string.h" HAVE_STRNCAT)
else ()
  set(HAVE_STRNCAT "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRNCAT "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCAT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strncat.c
  )
endif ()