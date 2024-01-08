
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <sys/types.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TYPES_H "1" CACHE STRING "")

# Some types might be in the time headers.
check_include_file("sys/types.h" HAVE_SYS_TYPES_H)
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
check_include_file("time.h" HAVE_TIME_H)

if (HAVE_SYS_TYPES_H)
  find_file(SYS_TYPES_H_PATH NAMES "sys/types.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (HAVE_SYS_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/time.h")
endif ()

if (HAVE_TIME_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "time.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

# Types defined by <sys/types.h>
check_type_size("blkcnt_t" BLKCNT_T)
check_type_size("blksize_t" BLKSIZE_T)
check_type_size("clock_t" CLOCK_T)
check_type_size("clockid_t" CLOCKID_T)
check_type_size("dev_t" DEV_T)
check_type_size("fsblkcnt_t" FSBLKCNT_T)
check_type_size("fsfilcnt_t" FSFILCNT_T)
check_type_size("gid_t" GID_T)
check_type_size("id_t" ID_T)
check_type_size("ino_t" INO_T)
check_type_size("mode_t" MODE_T)
check_type_size("nlink_t" NLINK_T)
check_type_size("off_t" OFF_T)
check_type_size("pid_t" PID_T)
check_type_size("ssize_t" SSIZE_T)
check_type_size("suseconds_t" SUSECONDS_T)
check_type_size("time_t" TIME_T)
check_type_size("timer_t" TIMER_T)
check_type_size("uid_t" UID_T)
check_type_size("useconds_t" USECONDS_T)

# MSVC
check_type_size("__int64_t" __INT64_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-types-h.cmake)
endif ()

