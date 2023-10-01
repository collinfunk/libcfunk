
include_guard(GLOBAL)

# Defines O_BINARY and O_TEXT to the underscore-prefixed names on Windows.
# On other systems these are defined to 0.
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

# These functions are required to change the mode of a file.
# If they are unavaliable we assume O_TEXT and O_BINARY have no special
# meaning.
check_symbol_exists("setmode" "io.h" HAVE_SETMODE)
check_symbol_exists("_setmode" "io.h" HAVE__SETMODE)
check_symbol_exists("fileno" "stdio.h" HAVE_FILENO)
check_symbol_exists("_fileno" "stdio.h" HAVE__FILENO)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/binary-mode.h
  $CACHE{LIBCFUNK_SOURCE_DIR}/binary-mode.c
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-binary-mode.cmake)
endif ()
