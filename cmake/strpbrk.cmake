
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strpbrk "string.h" HAVE_STRPBRK)

set(LIBCFUNK_DECLARE_STRPBRK 1)

if (NOT HAVE_STRPBRK)
  set(HAVE_STRPBRK 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strpbrk.c
  )
endif ()
