
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sched-h.cmake)

if (HAVE_SCHED_H)
  check_symbol_exists("sched_yield" "sched.h" HAVE_SCHED_YIELD_IN_LIBC)
  if (NOT HAVE_SCHED_YIELD_IN_LIBC)
    check_library_exists("rt" "sched_yield" "" HAVE_SCHED_YIELD_IN_LIBRT)
    if (HAVE_SCHED_YIELD_IN_LIBRT)
      target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "rt")
      list(APPEND CMAKE_REQUIRED_LIBRARIES "rt")
      list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
    else ()
      check_library_exists("posix4" "sched_yield" "" HAVE_SCHED_YIELD_IN_LIBPOSIX4)
      if (HAVE_SCHED_YIELD_IN_LIBPOSIX4)
        target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "posix4")
        list(APPEND CMAKE_REQUIRED_LIBRARIES "posix4")
        list(REMOVE_DUPLICATES CMAKE_REQUIRED_LIBRARIES)
      endif ()
    endif ()
  endif ()
  if (HAVE_SCHED_YIELD_IN_LIBC OR HAVE_SCHED_YIELD_IN_LIBRT OR HAVE_SCHED_YIELD_IN_LIBPOSIX4)
    set(HAVE_SCHED_YIELD "1" CACHE STRING "")
  endif ()
endif ()

set(LIBCFUNK_DECLARE_SCHED_YIELD "1" CACHE STRING "")

if (NOT HAVE_SCHED_YIELD)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sched_yield.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sched_yield.cmake)
endif ()

