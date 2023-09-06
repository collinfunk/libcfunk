include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strnlen" "string.h" HAVE_STRNLEN)
else ()
  set(HAVE_STRNLEN "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRNLEN "1" CACHE INTERNAL "")

if (NOT HAVE_STRNLEN)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strnlen.c
  )
endif ()