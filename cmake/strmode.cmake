include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strmode" "string.h" HAVE_STRMODE)
else ()
  set(HAVE_STRMODE "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRMODE "1" CACHE INTERNAL "")

if (NOT HAVE_STRMODE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strmode.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include(${LIBCFUNK_MODULE_DIR}/test-strmode.cmake)
endif ()
