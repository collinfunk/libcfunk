
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mkdir" "sys/stat.h" HAVE_MKDIR)
  check_c_source_compiles("
  #include <sys/stat.h>

  int
  main (void)
  {
    int return_value = _mkdir (\"missing_mode_parameter\");
    return 0;
  }" HAVE__MKDIR)
else ()
  set(HAVE_MKDIR "" CACHE INTERNAL "")
  set(HAVE__MKDIR "" CACHE INTERNAL "")
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
