
include_guard(GLOBAL)

# Generate <locale.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LOCALE_H "1" CACHE STRING "")

check_include_file("locale.h" HAVE_LOCALE_H)
check_include_file("xlocale.h" HAVE_XLOCALE_H)

if (HAVE_LOCALE_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "locale.h")
endif ()

if (HAVE_XLOCALE_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "xlocale.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct lconv" STRUCT_LCONV)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-locale-h.cmake)
endif ()

