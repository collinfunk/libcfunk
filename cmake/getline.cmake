
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio.cmake)
include(${LIBCFUNK_MODULE_DIR}/getdelim.cmake)

# Maybe just put this with getdelim since they are pretty much the same thing.
check_symbol_exists(getline "stdio.h" HAVE_GETLINE)

set(LIBCFUNK_DECLARE_GETLINE 1)

if (NOT HAVE_GETLINE)
  set(HAVE_GETLINE 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()

