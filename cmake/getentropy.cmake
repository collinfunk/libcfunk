
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/sys-random.cmake)

check_symbol_exists(getentropy "unistd.h;sys/random.h" HAVE_GETENTROPY)

if (NOT HAVE_GETENTROPY)
  # Make sure it can be substituted in preprocessor.
  set(HAVE_GETENTROPY 0)

  # Uses getrandom as a replacement.
  include(${LIBCFUNK_MODULE_DIR}/getrandom.cmake)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getentropy.c
  )
endif ()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getentropy.cmake)
endif ()

