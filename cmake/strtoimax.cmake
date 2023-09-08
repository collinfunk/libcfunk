
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("strtoimax" "inttypes.h" HAVE_STRTOIMAX)
else ()
  set(HAVE_STRTOIMAX "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRTOIMAX "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOIMAX)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strtoimax.c
  )
endif ()