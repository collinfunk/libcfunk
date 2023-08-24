
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

check_symbol_exists(bcmp "strings.h" HAVE_BCMP)

set(LIBCFUNK_DECLARE_BCMP 1)

if (NOT HAVE_BCMP)
  set(HAVE_BCMP 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bcmp.c
  )
endif ()

