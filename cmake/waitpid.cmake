
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-wait-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_SYS_WAIT_H)
  check_symbol_exists("waitpid" "sys/wait.h" HAVE_WAITPID)
else ()
  set(HAVE_WAITPID "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_WAITPID "1" CACHE INTERNAL "")

if (NOT HAVE_WAITPID)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/waitpid.c
  )
endif ()
