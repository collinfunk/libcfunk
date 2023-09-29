
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/alloca-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/environ.cmake)

check_c_symbol("execl" "unistd.h")
check_c_symbol("execve" "unistd.h")

set(LIBCFUNK_DECLARE_EXECL "1" CACHE INTERNAL "")

if (NOT HAVE_EXECL)
  # FIXME
  if (NOT HAVE_EXECVE)
    message(FATAL_ERROR "No implementation is avaiable for `execve'.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/execl.c
  )
endif ()
