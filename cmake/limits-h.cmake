
include_guard(GLOBAL)

# Generate <limits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIMITS_H "1" CACHE INTERNAL "")

check_include_file("limits.h" HAVE_LIMITS_H)

# Signed integer types.
check_type_size("signed char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

# Unsigned integer types.
check_type_size("unsigned char" SIZEOF_UNSIGNED_CHAR)
check_type_size("unsigned short" SIZEOF_UNSIGNED_SHORT)
check_type_size("unsigned int" SIZEOF_UNSIGNED_INT)
check_type_size("unsigned long" SIZEOF_UNSIGNED_LONG)
check_type_size("unsigned long long" SIZEOF_UNSIGNED_LONG_LONG)
