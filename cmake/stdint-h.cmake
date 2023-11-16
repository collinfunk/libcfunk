
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

# Generate <stdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDINT_H "1" CACHE STRING "")

check_include_file("stdint.h" HAVE_STDINT_H)
check_include_file("inttypes.h" HAVE_INTTYPES_H)
check_include_file("wchar.h" HAVE_WCHAR_H)

if (HAVE_INTTYPES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "inttypes.h")
endif ()

if (HAVE_WCHAR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "wchar.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

# Signed exact-width integer types.
check_type_size("int8_t" INT8_T)
check_type_size("int16_t" INT16_T)
check_type_size("int32_t" INT32_T)
check_type_size("int64_t" INT64_T)

# Unsigned exact-width integer types.
check_type_size("uint8_t" UINT8_T)
check_type_size("uint16_t" UINT16_T)
check_type_size("uint32_t" UINT32_T)
check_type_size("uint64_t" UINT64_T)

# Signed minimum-width integer types.
check_type_size("int_least8_t" INT_LEAST8_T)
check_type_size("int_least16_t" INT_LEAST16_T)
check_type_size("int_least32_t" INT_LEAST32_T)
check_type_size("int_least64_t" INT_LEAST64_T)

# Unsigned minimum-width integer types.
check_type_size("uint_least8_t" UINT_LEAST8_T)
check_type_size("uint_least16_t" UINT_LEAST16_T)
check_type_size("uint_least32_t" UINT_LEAST32_T)
check_type_size("uint_least64_t" UINT_LEAST64_T)

# Signed fastest-width integer types.
check_type_size("int_fast8_t" INT_FAST8_T)
check_type_size("int_fast16_t" INT_FAST16_T)
check_type_size("int_fast32_t" INT_FAST32_T)
check_type_size("int_fast64_t" INT_FAST64_T)

# Unsigned fastest-width integer types.
check_type_size("uint_fast8_t" UINT_FAST8_T)
check_type_size("uint_fast16_t" UINT_FAST16_T)
check_type_size("uint_fast32_t" UINT_FAST32_T)
check_type_size("uint_fast64_t" UINT_FAST64_T)

# Integer types capable of holding object pointers.
check_type_size("intptr_t" INTPTR_T)
check_type_size("uintptr_t" UINTPTR_T)

# Greatest-width integer types.
check_type_size("intmax_t" INTMAX_T)
check_type_size("uintmax_t" UINTMAX_T)

# Other types which have macros in 'stdint.h'.
check_type_size("size_t" SIZE_T)
check_type_size("ptrdiff_t" PTRDIFF_T)
check_type_size("wchar_t" WCHAR_T)
check_type_size("wint_t" WINT_T)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdint-h.cmake)
endif ()
