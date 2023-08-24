
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

check_symbol_exists(index "strings.h" HAVE_INDEX)

set(LIBCFUNK_DECLARE_INDEX 1)

if (NOT HAVE_INDEX)
  set(HAVE_INDEX 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/index.c
  )
endif ()

