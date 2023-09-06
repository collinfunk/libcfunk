include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strpbrk" "string.h" HAVE_STRPBRK)
else ()
  set(HAVE_STRPBRK "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRPBRK "1" CACHE INTERNAL "")

if (NOT HAVE_STRPBRK)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strpbrk.c
  )
endif ()