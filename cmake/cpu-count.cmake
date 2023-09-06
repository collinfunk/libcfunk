
include_guard(GLOBAL)

check_include_file("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_files("windows.h;sysinfoapi.h" HAVE_SYSINFOAPI_H)

if (HAVE_WINDOWS_H)
  if (HAVE_SYSINFOAPI_H)
    message(WARNING "cpu_count_avaliable () is inaccurate and will return more \
than are actually avaliable.")
  else ()
    message(FATAL_ERROR "Could not find <sysinfoapi.h> on your machine.")
  endif ()
endif ()

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/cpu-count.c
  ${LIBCFUNK_SOURCE_DIR}/cpu-count.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-cpu-count.cmake)
endif ()

