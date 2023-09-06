
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/sys-random-h.cmake)

if (HAVE_SYS_RANDOM_H)
  check_symbol_exists("getrandom" "sys/random.h" HAVE_GETRANDOM)
else ()
  set (HAVE_GETRANDOM "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_GETRANDOM)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  # Other systems can use /dev/random and /dev/urandom
  if (HAVE_WINDOWS_H)
    check_include_files("windows.h;bcrypt.h" HAVE_BCRYPT_H)
    if (HAVE_BCRYPT_H)
      target_link_libraries(${LIBCFUNK_LIBRARY_NAME} "bcrypt")
    else ()
      message(FATAL_ERROR "Unsupported windows version.")
    endif ()
  endif ()
endif ()

set(LIBCFUNK_DECLARE_GETRANDOM "1" CACHE INTERNAL "")

if (NOT HAVE_GETRANDOM)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getrandom.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-getrandom.cmake)
endif ()

