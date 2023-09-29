
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/alloca-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/execvp.cmake)

check_c_symbol("execlp" "unistd.h")

set(LIBCFUNK_DECLARE_EXECLP "1" CACHE INTERNAL "")

if (NOT HAVE_EXECLP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execlp.c
  )
endif ()
