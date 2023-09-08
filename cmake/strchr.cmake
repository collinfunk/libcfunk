include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strchr" "string.h" HAVE_STRCHR)
else ()
  set(HAVE_STRCHR "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_STRCHR)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strchr.c
  )
endif ()