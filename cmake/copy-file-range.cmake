
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("copy_file_range" "unistd.h" HAVE_COPY_FILE_RANGE)
endif ()

set(LIBCFUNK_DECLARE_COPY_FILE_RANGE "1" CACHE INTERNAL "")

if (NOT HAVE_COPY_FILE_RANGE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/copy-file-range.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-copy-file-range.cmake)
endif ()

