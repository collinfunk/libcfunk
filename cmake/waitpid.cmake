
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-wait-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

check_c_symbol("waitpid" "sys/wait.h")

set(LIBCFUNK_DECLARE_WAITPID "1" CACHE INTERNAL "")

if (NOT HAVE_WAITPID)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/waitpid.c
  )
endif ()
