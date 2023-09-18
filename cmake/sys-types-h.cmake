
include_guard(GLOBAL)

# Generate <sys/types.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_TYPES_H "1" CACHE INTERNAL "")

check_include_file("sys/types.h" HAVE_SYS_TYPES_H)

# This defines HAS_<type> to "TRUE" or "FALSE".
check_type_size("gid_t" GID_T)
check_type_size("uid_t" UID_T)

# Make them useable by the preprocessor.
if (HAVE_GID_T)
  set(HAVE_GID_T "1" CACHE INTERNAL "")
else ()
  set(HAVE_GID_T "0" CACHE INTERNAL "")
endif ()

if (HAVE_UID_T)
  set(HAVE_UID_T "1" CACHE INTERNAL "")
else ()
  set(HAVE_UID_T "0" CACHE INTERNAL "")
endif ()
