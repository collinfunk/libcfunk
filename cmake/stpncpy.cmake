
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(stpncpy "string.h" HAVE_STPNCPY)

set(LIBCFUNK_DECLARE_STPNCPY 1)

if (NOT HAVE_STPNCPY)
  set(HAVE_STPNCPY 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/stpncpy.c
  )
endif ()

