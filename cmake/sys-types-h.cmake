
include_guard(GLOBAL)

# Generate <sys/types.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TYPES_H "1" CACHE INTERNAL "")

check_c_system_headers("sys/types.h")

# This defines HAS_<type> to "TRUE" or "FALSE".
check_c_type_exists("gid_t" GID_T)
check_c_type_exists("uid_t" UID_T)
check_c_type_exists("off_t" OFF_T)
check_c_type_exists("__int64_t" __INT64_T)
