
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-file-h.cmake)

if (HAVE_SYS_FILE_H)
  check_symbol_exists("flock" "sys/file.h" HAVE_FLOCK)
endif ()

set(LIBCFUNK_DECLARE_FLOCK "1" CACHE STRING "")

if (NOT HAVE_FLOCK OR LIBCFUNK_REPLACE_FLOCK)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  check_include_file("fcntl.h" HAVE_FCNTL_H)
  check_include_file("unistd.h" HAVE_UNISTD_H)
  if (HAVE_FCNTL_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "fcntl.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
    check_type_size("struct flock" STRUCT_FLOCK)
    if (HAVE_STRUCT_FLOCK)
      check_struct_has_member("struct flock" "l_type" "fcntl.h" HAVE_STRUCT_FLOCK_L_TYPE)
      check_struct_has_member("struct flock" "l_whence" "fcntl.h" HAVE_STRUCT_FLOCK_L_WHENCE)
      check_struct_has_member("struct flock" "l_start" "fcntl.h" HAVE_STRUCT_FLOCK_L_START)
      check_struct_has_member("struct flock" "l_len" "fcntl.h" HAVE_STRUCT_FLOCK_L_LEN)
      check_struct_has_member("struct flock" "l_pid" "fcntl.h" HAVE_STRUCT_FLOCK_L_PID)
    endif ()
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/flock.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-flock.cmake)
endif ()

