
include_guard(GLOBAL)

# Generate <sys/types.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TYPES_H "1" CACHE INTERNAL "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)

# This defines HAS_<type> to "TRUE" or "FALSE".
check_type_size("gid_t" GID_T)
check_type_size("uid_t" UID_T)
check_type_size("off_t" OFF_T)
check_type_size("__int64_t" __INT64_T)
