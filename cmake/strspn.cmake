
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strspn "string.h" HAVE_STRSPN)

set(LIBCFUNK_DECLARE_STRSPN 1)

if (NOT HAVE_STRSPN)
  set(HAVE_STRSPN 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strspn.c
  )
endif ()
