include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("rawmemchr" "string.h" HAVE_RAWMEMCHR)
else ()
  set(HAVE_RAWMEMCHR "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_RAWMEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_RAWMEMCHR)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/rawmemchr.c
  )
endif ()