
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

check_c_symbol("isalnum" "ctype.h")
check_c_symbol("isalpha" "ctype.h")
check_c_symbol("isascii" "ctype.h")
check_c_symbol("isblank" "ctype.h")
check_c_symbol("iscntrl" "ctype.h")
check_c_symbol("isdigit" "ctype.h")
check_c_symbol("isgraph" "ctype.h")
check_c_symbol("islower" "ctype.h")
check_c_symbol("isprint" "ctype.h")
check_c_symbol("ispunct" "ctype.h")
check_c_symbol("isspace" "ctype.h")
check_c_symbol("isupper" "ctype.h")
check_c_symbol("isxdigit" "ctype.h")
check_c_symbol("toascii" "ctype.h")
check_c_symbol("tolower" "ctype.h")
check_c_symbol("toupper" "ctype.h")

if (NOT HAVE_ISALNUM)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isalnum.c
  )
endif ()

if (NOT HAVE_ISALPHA)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isalpha.c
  )
endif ()

if (NOT HAVE_ISASCII)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isascii.c
  )
endif ()

if (NOT HAVE_ISBLANK)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isblank.c
  )
endif ()

if (NOT HAVE_ISCNTRL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iscntrl.c
  )
endif ()

if (NOT HAVE_ISDIGIT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isdigit.c
  )
endif ()

if (NOT HAVE_ISGRAPH)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isgraph.c
  )
endif ()

if (NOT HAVE_ISLOWER)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/islower.c
  )
endif ()

if (NOT HAVE_ISPRINT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isprint.c
  )
endif ()

if (NOT HAVE_ISPUNCT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ispunct.c
  )
endif ()

if (NOT HAVE_ISSPACE)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isspace.c
  )
endif ()

if (NOT HAVE_ISUPPER)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isupper.c
  )
endif ()

if (NOT HAVE_ISXDIGIT)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isxdigit.c
  )
endif ()

if (NOT HAVE_TOASCII)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/toascii.c
  )
endif ()

if (NOT HAVE_TOLOWER)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tolower.c
  )
endif ()

if (NOT HAVE_TOUPPER)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/toupper.c
  )
endif ()

