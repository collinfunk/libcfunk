
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/inttypes.cmake)

check_symbol_exists(strtoimax "inttypes.h" HAVE_STRTOIMAX)

set(LIBCFUNK_DECLARE_STRTOIMAX 1)

if (NOT HAVE_STRTOIMAX)
  set(HAVE_STRTOIMAX 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoimax.c
  )
endif ()
