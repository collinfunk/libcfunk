
include_guard(GLOBAL)

# Generate <string.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STRING_H "1" CACHE INTERNAL "")

check_include_file("string.h" HAVE_STRING_H)

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_EXPLICIT_BZERO "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMCHR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMCMP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMCPY "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMMOVE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMRCHR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MEMSET "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_RAWMEMCHR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STPCPY "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRCAT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRCHR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRCHRNUL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRCMP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRCSPN "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRDUP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRLEN "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRMODE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRNCAT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRNCMP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRNCPY "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRNDUP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRNLEN "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRPBRK "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRRCHR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRSEP "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRSPN "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TIMINGSAFE_BCMP "0" CACHE INTERNAL "")

