
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strcmp "string.h" HAVE_STRCMP)

set(LIBCFUNK_DECLARE_STRCMP 1)

if (NOT HAVE_STRCMP)
  set(HAVE_STRCMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcmp.c
  )
endif ()
