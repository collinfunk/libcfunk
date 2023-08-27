
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(strcspn "string.h" HAVE_STRCSPN)

set(LIBCFUNK_DECLARE_STRCSPN 1)

if (NOT HAVE_STRCSPN)
  set(HAVE_STRCSPN 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strcspn.c
  )
endif ()
