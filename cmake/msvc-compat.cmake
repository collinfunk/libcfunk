
include_guard(GLOBAL)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("crtdbg.h" HAVE_CRTDBG_H)
check_include_file("stdlib.h" HAVE_STDLIB_H)

if (HAVE_STDLIB_H)
  check_symbol_exists("_set_invalid_parameter_handler" "stdlib.h" HAVE__SET_INVALID_PARAMETER_HANDLER)
else ()
  set(HAVE__SET_INVALID_PARAMETER_HANDLER "" CACHE INTERNAL "")
endif ()

if (HAVE_CRTDBG_H)
  check_symbol_exists("_CrtSetReportMode" "crtdbg.h" HAVE__CRTSETREPORTMODE)
else ()
  set(HAVE__CRTSETREPORTMODE "" CACHE INTERNAL "")
endif ()

if (HAVE__SET_INVALID_PARAMETER_HANDLER)
  include($CACHE{LIBCFUNK_MODULE_DIR}/attributes.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/msvc-compat.c
    $CACHE{LIBCFUNK_SOURCE_DIR}/msvc-compat.h
  )
  if (LIBCFUNK_ENABLE_TESTS)
    include($CACHE{LIBCFUNK_MODULE_DIR}/test-msvc-compat.cmake)
  endif ()
endif ()

