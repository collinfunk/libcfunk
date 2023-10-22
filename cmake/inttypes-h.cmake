
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <inttypes.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_INTTYPES_H "1" CACHE INTERNAL "")

check_include_file("inttypes.h" HAVE_INTTYPES_H)

if (HAVE_INTTYPES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "inttypes.h")
  check_type_size("imaxdiv_t" IMAXDIV_T)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "inttypes.h")
else ()
  set(HAVE_IMAXDIV_T "" CACHE INTERNAL "")
endif ()

# Only show prototypes for checked functions.
set(LIBCFUNK_DECLARE_IMAXABS "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_IMAXDIV "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRTOIMAX "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STRTOUMAX "0" CACHE INTERNAL "")
