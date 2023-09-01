
include_guard(GLOBAL)

# inttypes.h uses stdint.h
include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)

libcfunk_check_include_file("inttypes.h" HAVE_INTTYPES_H)

set(LIBCFUNK_GENERATE_INTTYPES_H TRUE)
set(LIBCFUNK_DECLARE_STRTOUMAX 0)
set(LIBCFUNK_DECLARE_STRTOIMAX 0)
