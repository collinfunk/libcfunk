
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

check_symbol_exists(bcopy "strings.h" HAVE_BCOPY)

set(LIBCFUNK_DECLARE_BCOPY 1)

if (NOT HAVE_BCOPY)
  set(HAVE_BCOPY 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/bcopy.c
  )
endif ()

