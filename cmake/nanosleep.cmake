
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("nanosleep" "time.h" HAVE_NANOSLEEP_IN_LIBC)
  if (NOT HAVE_NANOSLEEP_IN_LIBC)
    check_library_exists("rt" "nanosleep" "" HAVE_NANOSLEEP_IN_LIBRT)
    if (HAVE_NANOSLEEP_IN_LIBRT)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    else ()
      check_library_exists("posix4" "nanosleep" "" HAVE_NANOSLEEP_IN_LIBPOSIX4)
      if (HAVE_NANOSLEEP_IN_LIBPOSIX4)
        target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "posix4")
        list(APPEND CMAKE_REQUIRED_LIBRARIES "posix4")
        list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
      endif ()
    endif ()
  endif ()
  if (HAVE_NANOSLEEP_IN_LIBC OR HAVE_NANOSLEEP_IN_LIBRT OR HAVE_NANOSLEEP_IN_LIBPOSIX4)
    set(HAVE_NANOSLEEP "1" CACHE STRING "")
  endif ()
endif ()

set(LIBCFUNK_DECLARE_NANOSLEEP "1" CACHE STRING "")

if (NOT HAVE_NANOSLEEP)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/nanosleep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nanosleep.cmake)
endif ()

