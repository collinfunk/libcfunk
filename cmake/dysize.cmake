include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("dysize" "time.h" HAVE_DYSIZE)
else ()
  set(HAVE_DYSIZE "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_DYSIZE "1" CACHE INTERNAL "")

if (NOT HAVE_DYSIZE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/dysize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-dysize.cmake)
endif ()

