include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcspn" "string.h" HAVE_STRCSPN)
else ()
  set(HAVE_STRCSPN "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRCSPN "1" CACHE INTERNAL "")

if (NOT HAVE_STRCSPN)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcspn.c
  )
endif ()