
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

check_symbol_exists(getcwd "unistd.h" HAVE_GETCWD)
check_symbol_exists(_getcwd "unistd.h" HAVE__GETCWD)

set(LIBCFUNK_DECLARE_GETCWD 1)

if (NOT HAVE_GETCWD)
  set(HAVE_GETCWD 0)

  # Just assume Windows
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getcwd.c
  )
endif ()

if (NOT HAVE__GETCWD)
  set(HAVE__GETCWD 0)
endif ()
