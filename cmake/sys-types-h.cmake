
include_guard(GLOBAL)

# Generate <sys/types.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TYPES_H "1" CACHE INTERNAL "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)

# Types defined by <sys/types.h>
check_type_size("blkcnt_t" BLKCNT_T)
check_type_size("blksize_t" BLKSIZE_T)
check_type_size("clockid_t" CLOCKID_T)
check_type_size("dev_t" DEV_T)
check_type_size("gid_t" GID_T)
check_type_size("ino_t" INO_T)
check_type_size("mode_t" MODE_T)
check_type_size("off_t" OFF_T)
check_type_size("pid_t" PID_T)
check_type_size("size_t" SIZE_T)
check_type_size("ssize_t" SSIZE_T)
check_type_size("uid_t" UID_T)

# MSVC
check_type_size("__int64_t" __INT64_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-types-h.cmake)
endif ()

