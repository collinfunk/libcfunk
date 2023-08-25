
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

check_symbol_exists(swab "unistd.h" HAVE_SWAB)

set(LIBCFUNK_DECLARE_SWAB 1)

if (NOT HAVE_SWAB)
  set(HAVE_SWAB 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/swab.c
  )
endif ()
