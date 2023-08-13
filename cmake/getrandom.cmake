
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/sys-random.cmake)

check_symbol_exists(getrandom "sys/random.h" HAVE_GETRANDOM)

if (NOT HAVE_GETRANDOM)
  # Make sure it can be substituted in preprocessor.
  set(HAVE_GETRANDOM 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getrandom.c
  )
endif ()

