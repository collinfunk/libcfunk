include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include(${LIBCFUNK_MODULE_DIR}/getdelim.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("getline" "stdio.h" HAVE_GETLINE)
else ()
  set(HAVE_GETLINE "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_GETLINE "1" CACHE INTERNAL "")

if (NOT HAVE_GETLINE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()