
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/filename.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/euidaccess.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("execvpe" "unistd.h" HAVE_EXECVPE)
else ()
  set(HAVE_EXECVPE "" CACHE INTERAL "")
endif ()

set(LIBCFUNK_DECLARE_EXECVPE "1" CACHE INTERNAL "")

if (NOT HAVE_EXECVPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execvpe.c
  )
endif ()