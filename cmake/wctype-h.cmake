
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

# Generate <wctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_WCTYPE_H "1" CACHE INTERNAL "")

check_include_file("wchar.h" HAVE_WCHAR_H)
check_include_file("wctype.h" HAVE_WCTYPE_H)

set(LIBCFUNK_DECLARE_ISWALNUM "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWALPHA "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWBLANK "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWCNTRL "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWCTYPE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWDIGIT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWGRAPH "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWLOWER "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWPRINT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWPUNCT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWSPACE "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWUPPER "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_ISWXDIGIT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TOWLOWER "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_TOWUPPER "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_WCTYPE "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wctype-h.cmake)
endif ()
