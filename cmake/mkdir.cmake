
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

check_include_file("direct.h" HAVE_DIRECT_H)

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

set(LIBCFUNK_DECLARE_MKDIR "1" CACHE INTERNAL "")

if (HAVE_MKDIR AND HAVE__MKDIR)
  set(HAVE_MKDIR "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_MKDIR)
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
