
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isalnum" "ctype.h" HAVE_ISALNUM)
  check_symbol_exists("isalpha" "ctype.h" HAVE_ISALPHA)
  check_symbol_exists("isascii" "ctype.h" HAVE_ISASCII)
  check_symbol_exists("isblank" "ctype.h" HAVE_ISBLANK)
  check_symbol_exists("iscntrl" "ctype.h" HAVE_ISCNTRL)
  check_symbol_exists("isdigit" "ctype.h" HAVE_ISDIGIT)
  check_symbol_exists("isgraph" "ctype.h" HAVE_ISGRAPH)
  check_symbol_exists("islower" "ctype.h" HAVE_ISLOWER)
  check_symbol_exists("isprint" "ctype.h" HAVE_ISPRINT)
  check_symbol_exists("ispunct" "ctype.h" HAVE_ISPUNCT)
  check_symbol_exists("isspace" "ctype.h" HAVE_ISSPACE)
  check_symbol_exists("isupper" "ctype.h" HAVE_ISUPPER)
  check_symbol_exists("isxdigit" "ctype.h" HAVE_ISXDIGIT)
  check_symbol_exists("toascii" "ctype.h" HAVE_TOASCII)
  check_symbol_exists("tolower" "ctype.h" HAVE_TOLOWER)
  check_symbol_exists("toupper" "ctype.h" HAVE_TOUPPER)
else ()
  set(HAVE_ISALNUM "" CACHE INTERNAL "")
  set(HAVE_ISALPHA "" CACHE INTERNAL "")
  set(HAVE_ISASCII "" CACHE INTERNAL "")
  set(HAVE_ISBLANK "" CACHE INTERNAL "")
  set(HAVE_ISCNTRL "" CACHE INTERNAL "")
  set(HAVE_ISDIGIT "" CACHE INTERNAL "")
  set(HAVE_ISGRAPH "" CACHE INTERNAL "")
  set(HAVE_ISLOWER "" CACHE INTERNAL "")
  set(HAVE_ISPRINT "" CACHE INTERNAL "")
  set(HAVE_ISPUNCT "" CACHE INTERNAL "")
  set(HAVE_ISSPACE "" CACHE INTERNAL "")
  set(HAVE_ISUPPER "" CACHE INTERNAL "")
  set(HAVE_ISXDIGIT "" CACHE INTERNAL "")
  set(HAVE_TOASCII "" CACHE INTERNAL "")
  set(HAVE_TOLOWER "" CACHE INTERNAL "")
  set(HAVE_TOUPPER "" CACHE INTERNAL "")
endif ()

if (NOT HAVE_ISALNUM)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isalnum.c
  )
endif ()

if (NOT HAVE_ISALPHA)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isalpha.c
  )
endif ()

if (NOT HAVE_ISASCII)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isascii.c
  )
endif ()

if (NOT HAVE_ISBLANK)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isblank.c
  )
endif ()

if (NOT HAVE_ISCNTRL)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/iscntrl.c
  )
endif ()

if (NOT HAVE_ISDIGIT)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isdigit.c
  )
endif ()

if (NOT HAVE_ISGRAPH)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isgraph.c
  )
endif ()

if (NOT HAVE_ISLOWER)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/islower.c
  )
endif ()

if (NOT HAVE_ISPRINT)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isprint.c
  )
endif ()

if (NOT HAVE_ISPUNCT)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/ispunct.c
  )
endif ()

if (NOT HAVE_ISSPACE)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isspace.c
  )
endif ()

if (NOT HAVE_ISUPPER)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isupper.c
  )
endif ()

if (NOT HAVE_ISXDIGIT)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/isxdigit.c
  )
endif ()

if (NOT HAVE_TOASCII)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/toascii.c
  )
endif ()

if (NOT HAVE_TOLOWER)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/tolower.c
  )
endif ()

if (NOT HAVE_TOUPPER)
  target_sources({LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/toupper.c
  )
endif ()

