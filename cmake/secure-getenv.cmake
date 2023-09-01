
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

set(LIBCFUNK_DECLARE_SECURE_GETENV 1)

libcfunk_check_symbol_exists(getenv "stdlib.h" HAVE_GETENV)
libcfunk_check_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
libcfunk_check_symbol_exists(issetugid "unistd.h" HAVE_ISSETUGID)
libcfunk_check_symbol_exists(getgid "unistd.h" HAVE_GETGID)
libcfunk_check_symbol_exists(getegid "unistd.h" HAVE_GETEGID)
libcfunk_check_symbol_exists(getuid "unistd.h" HAVE_GETUID)
libcfunk_check_symbol_exists(geteuid "unistd.h" HAVE_GETEUID)

if (NOT HAVE_SECURE_GETENV)
  libcfunk_add_sources("secure-getenv.c")
endif ()

