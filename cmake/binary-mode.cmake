
include_guard(GLOBAL)

# Defines O_BINARY and O_TEXT to the underscore-prefixed names on Windows.
# On other systems these are defined to 0.
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fileno.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("io.h" HAVE_IO_H)

if (HAVE_IO_H)
  check_symbol_exists("setmode" "io.h" HAVE_SETMODE)
  check_symbol_exists("_setmode" "io.h" HAVE__SETMODE)
endif ()

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/binary-mode.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/binary-mode.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-binary-mode.cmake)
endif ()
