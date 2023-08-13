
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strdup "string.h" HAVE_STRDUP)

if (NOT HAVE_STRDUP)
  set(HAVE_STRDUP 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strdup.c
  )
endif ()

