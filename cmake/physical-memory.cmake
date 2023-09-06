
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/filename.cmake)

check_include_file("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/physical-memory.c
  ${LIBCFUNK_SOURCE_DIR}/physical-memory.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-physical-memory.cmake)
endif ()

