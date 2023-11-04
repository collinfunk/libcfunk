
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-random-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_SYS_RANDOM_H)
  check_symbol_exists("getrandom" "sys/random.h" HAVE_GETRANDOM)
endif ()

if (NOT HAVE_GETRANDOM)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  # Other systems can use /dev/random and /dev/urandom
  if (HAVE_WINDOWS_H)
    check_include_files("windows.h;bcrypt.h" HAVE_BCRYPT_H)
    if (HAVE_BCRYPT_H)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "bcrypt")
    else ()
      message(FATAL_ERROR "Unsupported windows version.")
    endif ()
  endif ()
endif ()

set(LIBCFUNK_DECLARE_GETRANDOM "1" CACHE INTERNAL "")

if (NOT HAVE_GETRANDOM)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getrandom.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getrandom.cmake)
endif ()

