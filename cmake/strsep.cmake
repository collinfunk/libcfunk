
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strsep "string.h" HAVE_STRSEP)

set(LIBCFUNK_DECLARE_STRSEP 1)

if (NOT HAVE_STRSEP)
  set(HAVE_STRSEP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strsep.c
  )
endif ()

