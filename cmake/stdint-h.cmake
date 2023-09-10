
include_guard(GLOBAL)

# Generate <stdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDINT_H "1" CACHE INTERNAL "")

check_include_file("stdint.h" HAVE_STDINT_H)

check_type_size("uint8_t" SIZEOF_UINT8_T)
check_type_size("uint16_t" SIZEOF_UINT16_T)
check_type_size("uint32_t" SIZEOF_UINT32_T)
check_type_size("uint64_t" SIZEOF_UINT64_T)
