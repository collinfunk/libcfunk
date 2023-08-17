
include_guard(GLOBAL)

check_include_files("windows.h;sysinfoapi.h" HAVE_SYSINFOAPI_H)
check_include_files("sys/sysctl.h" HAVE_SYS_SYSCTL_H)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/cpu-count.h
  ${LIBCFUNK_SOURCE_DIR}/cpu-count.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-cpu-count.cmake)
endif ()
