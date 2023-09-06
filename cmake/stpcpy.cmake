include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("stpcpy" "string.h" HAVE_STPCPY)
else ()
  set(HAVE_STPCPY "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STPCPY "1" CACHE INTERNAL "")

if (NOT HAVE_STPCPY)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/stpcpy.c
  )
endif ()