
include_guard(GLOBAL)

# Generate <langinfo.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LANGINFO_H "1" CACHE STRING "")

check_include_file("langinfo.h" HAVE_LANGINFO_H)
check_include_file("locale.h" HAVE_LOCALE_H)
check_include_file("xlocale.h" HAVE_XLOCALE_H)
check_include_file("nl_types.h" HAVE_NL_TYPES_H)

if (HAVE_LANGINFO_H OR HAVE_NL_TYPES_H)
  set(NL_ITEM_INCLUDES "")
  if (HAVE_LANGINFO_H)
    list(APPEND NL_ITEM_INCLUDES "langinfo.h")
  endif ()
  if (HAVE_NL_TYPES_H)
    list(APPEND NL_ITEM_INCLUDES "nl_types.h")
  endif ()
  foreach (header ${NL_ITEM_INCLUDES})
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "${header}")
  endforeach ()
  check_type_size("nl_item" NL_ITEM)
  foreach (header ${NL_ITEM_INCLUDES})
    list(REMOVE_ITEM CMAKE_EXTRA_INCLUDE_FILES "${header}")
  endforeach ()
  unset(NL_ITEM_INCLUDES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-langinfo-h.cmake)
endif ()
