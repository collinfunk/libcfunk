
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strings.cmake)

# Doesn't make sense to put these separately.
check_symbol_exists(fls "strings.h" HAVE_FLS)
check_symbol_exists(flsl "strings.h" HAVE_FLSL)
check_symbol_exists(flsll "strings.h" HAVE_FLSLL)

set(LIBCFUNK_DECLARE_FLS 1)
set(LIBCFUNK_DECLARE_FLSL 1)
set(LIBCFUNK_DECLARE_FLSLL 1)

if (NOT HAVE_FLS)
  set(HAVE_FLS 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/fls.c
  )
endif()

if (NOT HAVE_FLSL)
  set(HAVE_FLSL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/flsl.c
  )
endif()

if (NOT HAVE_FLSLL)
  set(HAVE_FLSLL 0)

  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/flsll.c
  )
endif()

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-fls.cmake)
endif ()
