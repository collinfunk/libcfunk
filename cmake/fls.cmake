
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRINGS_H)
  check_symbol_exists("fls" "strings.h" HAVE_FLS)
  check_symbol_exists("flsl" "strings.h" HAVE_FLSL)
  check_symbol_exists("flsll" "strings.h" HAVE_FLSLL)
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
