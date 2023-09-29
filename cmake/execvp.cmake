
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/execvpe.cmake)

check_c_symbol("execvp" "unistd.h")

set(LIBCFUNK_DECLARE_EXECVP "1" CACHE INTERNAL "")

if (NOT HAVE_EXECVP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execvp.c
  )
endif ()

