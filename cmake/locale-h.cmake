
include_guard(GLOBAL)

# Generate <locale.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LOCALE_H "1" CACHE INTERNAL "")

check_include_file("locale.h" HAVE_LOCALE_H)

if (HAVE_LOCALE_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "locale.h")
  check_type_size("struct lconv" STRUCT_LCONV)
  list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "locale.h")
else ()
  set(HAVE_STRUCT_LCONV "" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-locale-h.cmake)
endif ()
