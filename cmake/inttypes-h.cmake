
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <inttypes.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_INTTYPES_H "1" CACHE INTERNAL "")

check_c_system_headers("inttypes.h")

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_IMAXABS "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRTOIMAX "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRTOUMAX "0" CACHE INTERNAL "")
