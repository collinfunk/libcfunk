include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strerrorname_np" "string.h" HAVE_STRERRORNAME_NP)
else ()
  set(HAVE_STRERRORNAME_NP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRERRORNAME_NP "1" CACHE INTERNAL "")

if (NOT HAVE_STRERRORNAME_NP)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strerrorname-np.c
  )
endif ()
