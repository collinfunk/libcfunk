
include_guard(GLOBAL)

check_include_files("sys/sysctl.h" HAVE_SYS_SYSCTL_H)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/physical-memory.h
  ${LIBCFUNK_SOURCE_DIR}/physical-memory.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-physical-memory.cmake)
endif ()
