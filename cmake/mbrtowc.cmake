
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("mbrtowc" "wchar.h" HAVE_MBRTOWC)
endif ()

# TODO
if (NOT HAVE_MBRTOWC)
  message(FATAL_ERROR "No implementation of 'mbrtowc' for your system.")
endif ()
