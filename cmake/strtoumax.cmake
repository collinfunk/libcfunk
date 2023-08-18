
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/inttypes.cmake)

check_symbol_exists(strtoumax "inttypes.h" HAVE_STRTOUMAX)

set(LIBCFUNK_DECLARE_STRTOUMAX 1)

if (NOT HAVE_STRTOUMAX)
  set(HAVE_STRTOUMAX 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoumax.c
  )
endif ()
