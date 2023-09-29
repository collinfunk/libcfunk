
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("ffs" "strings.h")
check_c_symbol("ffsl" "strings.h")
check_c_symbol("ffsll" "strings.h")

set(LIBCFUNK_DECLARE_FFS "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FFSL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FFSLL "1" CACHE INTERNAL "")

if (NOT HAVE_FFS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ffs.c
  )
endif ()

if (NOT HAVE_FFSL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ffsl.c
  )
endif ()

if (NOT HAVE_FFSLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ffsll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ffs.cmake)
endif ()
