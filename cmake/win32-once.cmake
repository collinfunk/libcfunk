
include_guard(GLOBAL)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/win32-once.c
    $CACHE{LIBCFUNK_SOURCE_DIR}/win32-once.h
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS AND HAVE_WINDOWS_H)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-win32-once.cmake)
endif ()

