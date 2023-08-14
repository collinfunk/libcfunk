
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strndup "string.h" HAVE_STRNDUP)

set(LIBCFUNK_DECLARE_STRNDUP 1)

if (NOT HAVE_STRNDUP)
  set(HAVE_STRNDUP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strndup.c
  )
endif ()

