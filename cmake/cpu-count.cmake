
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/popcount.cmake)

check_c_system_headers("sys/sysctl.h")
check_c_system_headers("sched.h")
check_c_system_headers("windows.h")
check_c_system_headers("windows.h;sysinfoapi.h")
check_c_symbol("sched_getaffinity" "sched.h")

if (HAVE_WINDOWS_H)
  if (NOT HAVE_SYSINFOAPI_H)
    message(FATAL_ERROR "Could not find <sysinfoapi.h> on your machine.")
  endif ()
endif ()

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/cpu-count.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/cpu-count.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-cpu-count.cmake)
endif ()

