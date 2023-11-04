
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

check_include_file("direct.h" HAVE_DIRECT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SYS_STAT_H OR HAVE_DIRECT_H)
  set(MKDIR_INCLUDES "")
  if (HAVE_SYS_STAT_H)
    list(APPEND MKDIR_INCLUDES "sys/stat.h")
  endif ()
  if (HAVE_DIRECT_H)
    list(APPEND MKDIR_INCLUDES "direct.h")
  endif ()
  check_symbol_exists("mkdir" "${MKDIR_INCLUDES}" HAVE_MKDIR)
  check_symbol_exists("_mkdir" "${MKDIR_INCLUDES}" HAVE__MKDIR)
  unset(MKDIR_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_MKDIR "1" CACHE STRING "")

if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_MKDIR "1" CACHE STRING "")
endif ()

if (NOT HAVE_MKDIR OR LIBCFUNK_REPLACE_MKDIR)
  if (NOT HAVE__MKDIR)
    message(FATAL_ERROR "No implementation of mkdir for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mkdir.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mkdir.cmake)
endif ()
