
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/popcount.cmake)

check_include_file("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_file("sched.h" HAVE_SCHED_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_files("windows.h;sysinfoapi.h" HAVE_SYSINFOAPI_H)

if (HAVE_WINDOWS_H)
  if (NOT HAVE_SYSINFOAPI_H)
    message(FATAL_ERROR "Could not find <sysinfoapi.h> on your machine.")
  endif ()
endif ()

if (HAVE_SCHED_H)
  check_symbol_exists("sched_getaffinity" "sched.h" HAVE_SCHED_GETAFFINITY)
else ()
  set(HAVE_SCHED_GETAFFINITY "" CACHE INTERNAL "")
endif ()

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/cpu-count.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/cpu-count.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-cpu-count.cmake)
endif ()

