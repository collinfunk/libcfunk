
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

check_c_symbol("mkdir" "sys/stat.h")
check_c_compiles("
#include <sys/stat.h>

int
main (void)
{
  int return_value = _mkdir (\"missing_mode_parameter\");
  return 0;
}" HAVE__MKDIR)

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
