
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

# Generate <stdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDINT_H "1" CACHE INTERNAL "")

check_c_system_headers("stdint.h")

# Signed exact-width integer types.
check_c_type_exists("int8_t")
check_c_type_exists("int16_t")
check_c_type_exists("int32_t")
check_c_type_exists("int64_t")

# Unsigned exact-width integer types.
check_c_type_exists("uint8_t")
check_c_type_exists("uint16_t")
check_c_type_exists("uint32_t")
check_c_type_exists("uint64_t")

# Signed minimum-width integer types.
check_c_type_exists("int_least8_t")
check_c_type_exists("int_least16_t")
check_c_type_exists("int_least32_t")
check_c_type_exists("int_least64_t")

# Unsigned minimum-width integer types.
check_c_type_exists("uint_least8_t")
check_c_type_exists("uint_least16_t")
check_c_type_exists("uint_least32_t")
check_c_type_exists("uint_least64_t")

# Signed fastest-width integer types.
check_c_type_exists("int_fast8_t")
check_c_type_exists("int_fast16_t")
check_c_type_exists("int_fast32_t")
check_c_type_exists("int_fast64_t")

# Unsigned fastest-width integer types.
check_c_type_exists("uint_fast8_t")
check_c_type_exists("uint_fast16_t")
check_c_type_exists("uint_fast32_t")
check_c_type_exists("uint_fast64_t")

# Integer types capable of holding object pointers.
check_c_type_exists("intptr_t")
check_c_type_exists("uintptr_t")

# Greatest-width integer types.
check_c_type_exists("intmax_t")
check_c_type_exists("uintmax_t")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdint-h.cmake)
endif ()
