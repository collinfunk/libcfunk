
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdlib.cmake)

check_symbol_exists(getenv "stdlib.h" HAVE_GETENV)
check_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
check_symbol_exists(issetugid "unistd.h" HAVE_ISSETUGID)
check_symbol_exists(getgid "unistd.h" HAVE_GETGID)
check_symbol_exists(getegid "unistd.h" HAVE_GETEGID)
check_symbol_exists(getuid "unistd.h" HAVE_GETUID)
check_symbol_exists(geteuid "unistd.h" HAVE_GETEUID)

if (NOT HAVE_GETENV)
  set(HAVE_GETENV 0)
endif ()

if (NOT HAVE_SECURE_GETENV)
  set(HAVE_SECURE_GETENV 0)
endif ()

if (NOT HAVE_ISSETUGID)
  set(HAVE_ISSETUGID 0)
endif ()

if (NOT HAVE_GETGID)
  set(HAVE_GETGID 0)
endif ()

if (NOT HAVE_GETEGID)
  set(HAVE_GETEGID 0)
endif ()

if (NOT HAVE_GETUID)
  set(HAVE_GETUID 0)
endif ()

if (NOT HAVE_GETEUID)
  set(HAVE_GETEUID 0)
endif ()

