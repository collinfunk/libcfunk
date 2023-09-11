
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("fls" "strings.h" HAVE_FLS)
  check_symbol_exists("flsl" "strings.h" HAVE_FLSL)
  check_symbol_exists("flsll" "strings.h" HAVE_FLSLL)
else ()
  set (HAVE_FLS "" CACHE INTERNAL "")
  set (HAVE_FLSL "" CACHE INTERNAL "")
  set (HAVE_FLSLL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FLS "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FLSL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FLSLL "1" CACHE INTERNAL "")

if (NOT HAVE_FLS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fls.c
  )
endif ()

if (NOT HAVE_FLSL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/flsl.c
  )
endif ()

if (NOT HAVE_FLSLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/flsll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fls.cmake)
endif ()
