
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("fls" "strings.h")
check_c_symbol("flsl" "strings.h")
check_c_symbol("flsll" "strings.h")

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
