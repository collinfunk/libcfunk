
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-random-h.cmake)

check_c_symbol("getrandom" "sys/random.h")
check_c_system_headers("windows.h")
check_c_system_headers("windows.h;bcrypt.h")

if (NOT HAVE_GETRANDOM)
  # Other systems can use /dev/random and /dev/urandom
  if (HAVE_WINDOWS_H)
    if (HAVE_BCRYPT_H)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" "bcrypt")
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

