
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("timespec_get" "time.h" HAVE_TIMESPEC_GET)
endif ()

set(LIBCFUNK_DECLARE_TIMESPEC_GET "1" CACHE STRING "")

if (NOT HAVE_TIMESPEC_GET OR LIBCFUNK_REPLACE_TIMESPEC_GET)
  # Only link to 'librt' or 'libposix4' if nessecary. This is required on some
  # versions of Linux and Solaris.
  check_symbol_exists("clock_gettime" "time.h" HAVE_CLOCK_GETTIME_IN_LIBC)
  if (NOT HAVE_CLOCK_GETTIME_IN_LIBC)
    check_library_exists("rt" "clock_gettime" "" HAVE_CLOCK_GETTIME_IN_LIBRT)
    if (HAVE_CLOCK_GETTIME_IN_LIBRT)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    else ()
      check_library_exists("posix4" "clock_gettime" "" HAVE_CLOCK_GETTIME_IN_LIBPOSIX4)
      if (HAVE_CLOCK_GETTIME_IN_LIBPOSIX4)
        target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "posix4")
        list(APPEND CMAKE_REQUIRED_LIBRARIES "posix4")
        list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
      endif ()
    endif ()
  endif ()
  if (HAVE_CLOCK_GETTIME_IN_LIBC OR HAVE_CLOCK_GETTIME_IN_LIBRT OR HAVE_CLOCK_GETTIME_IN_LIBPOSIX4)
    set(HAVE_CLOCK_GETTIME "1" CACHE STRING "")
  endif ()
  # Fallback on 'gettimeofday'.
  if (NOT HAVE_CLOCK_GETTIME)
    include($CACHE{LIBCFUNK_MODULE_DIR}/gettimeofday.cmake)
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timespec_get.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-timespec_get.cmake)
endif ()

