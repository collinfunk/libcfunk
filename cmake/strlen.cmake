include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strlen" "string.h" HAVE_STRLEN)
else ()
  set(HAVE_STRLEN "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRLEN "1" CACHE INTERNAL "")

if (NOT HAVE_STRLEN)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strlen.c
  )
endif ()