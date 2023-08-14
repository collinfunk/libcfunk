
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strchrnul "string.h" HAVE_STRCHRNUL)

set(LIBCFUNK_DECLARE_STRCHRNUL 1)

if (NOT HAVE_STRCHRNUL)
  set(HAVE_STRCHRNUL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strchrnul.c
  )
endif ()

