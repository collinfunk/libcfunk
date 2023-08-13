
include_guard(GLOBAL)

# inttypes.h uses stdint.h
include(${LIBCFUNK_MODULE_DIR}/stdint.cmake)

check_include_file("inttypes.h" HAVE_INTTYPES_H)

set(LIBCFUNK_GENERATE_INTTYPES_H TRUE)

if (HAVE_INTTYPES_H)
else ()
  set(HAVE_INTTYPES_H 0)
endif ()

