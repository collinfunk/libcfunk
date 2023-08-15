
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strnlen "string.h" HAVE_STRNLEN)

set(LIBCFUNK_DECLARE_STRNLEN 1)

if (NOT HAVE_STRNLEN)
  set(HAVE_STRNLEN 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strnlen.c
  )
endif ()

