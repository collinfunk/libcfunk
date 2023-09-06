include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("swab" "unistd.h" HAVE_SWAB)
else ()
  set(HAVE_SWAB "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_SWAB "1" CACHE INTERNAL "")

if (NOT HAVE_SWAB)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/swab.c
  )
endif ()
