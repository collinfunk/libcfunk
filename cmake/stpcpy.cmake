
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

check_symbol_exists(stpcpy "string.h" HAVE_STPCPY)

if (NOT HAVE_STPCPY)
  set(HAVE_STPCPY 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/stpcpy.c
  )
endif ()

