
include_guard(GLOBAL)

check_include_files("sys/sysctl.h" HAVE_SYS_SYSCTL_H)

libcfunk_add_sources("physical-memory.h;physical-memory.c")

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-physical-memory.cmake)
endif ()
