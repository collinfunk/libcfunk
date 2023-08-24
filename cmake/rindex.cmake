
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

check_symbol_exists(rindex "strings.h" HAVE_RINDEX)

set(LIBCFUNK_DECLARE_RINDEX 1)

if (NOT HAVE_RINDEX)
  set(HAVE_RINDEX 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/rindex.c
  )
endif ()

