include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strndup" "string.h" HAVE_STRNDUP)
else ()
  set(HAVE_STRNDUP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRNDUP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNDUP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strndup.c
  )
endif ()