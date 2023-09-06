include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("memrchr" "string.h" HAVE_MEMRCHR)
else ()
  set(HAVE_MEMRCHR "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_MEMRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_MEMRCHR)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/memrchr.c
  )
endif ()