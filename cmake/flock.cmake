
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-file-h.cmake)

if (HAVE_SYS_FILE_H)
  check_symbol_exists("flock" "sys/file.h" HAVE_FLOCK)
else ()
  set(HAVE_FLOCK "" CACHE INTERNAL "")
endif ()

check_include_file("fcntl.h" HAVE_FCNTL_H)
check_include_file("unistd.h" HAVE_UNISTD_H)

if (HAVE_FCNTL_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "fcntl.h")
  check_type_size("struct flock" STRUCT_FLOCK)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "fcntl.h")
  check_struct_has_member("struct flock" "l_type" "fcntl.h" HAVE_STRUCT_FLOCK_L_TYPE)
  check_struct_has_member("struct flock" "l_whence" "fcntl.h" HAVE_STRUCT_FLOCK_L_WHENCE)
  check_struct_has_member("struct flock" "l_start" "fcntl.h" HAVE_STRUCT_FLOCK_L_START)
  check_struct_has_member("struct flock" "l_len" "fcntl.h" HAVE_STRUCT_FLOCK_L_LEN)
  check_struct_has_member("struct flock" "l_pid" "fcntl.h" HAVE_STRUCT_FLOCK_L_PID)
else ()
  set(HAVE_STRUCT_FLOCK "" CACHE INTERNAL "")
  set(HAVE_STRUCT_FLOCK_L_TYPE "" CACHE INTERNAL "")
  set(HAVE_STRUCT_FLOCK_L_WHENCE "" CACHE INTERNAL "")
  set(HAVE_STRUCT_FLOCK_L_START "" CACHE INTERNAL "")
  set(HAVE_STRUCT_FLOCK_L_LEN "" CACHE INTERNAL "")
  set(HAVE_STRUCT_FLOCK_L_PID "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FLOCK "1" CACHE INTERNAL "")

if (NOT HAVE_FLOCK)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/flock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-flock.cmake)
endif ()

