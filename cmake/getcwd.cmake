
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

libcfunk_check_symbol_exists(getcwd "unistd.h" HAVE_GETCWD)
libcfunk_check_symbol_exists(_getcwd "unistd.h" HAVE__GETCWD)

set(LIBCFUNK_DECLARE_GETCWD 1)

if (NOT HAVE_GETCWD)
  libcfunk_add_sources("getcwd.c")
endif ()
