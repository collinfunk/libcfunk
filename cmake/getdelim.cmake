include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include(${LIBCFUNK_MODULE_DIR}/unlocked-stdio.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("getdelim" "stdio.h" HAVE_GETDELIM)
else ()
  set(HAVE_GETDELIM "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_GETDELIM "1" CACHE INTERNAL "")

if (NOT HAVE_GETDELIM)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getdelim.c
  )
endif ()