include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("getusershell" "unistd.h" HAVE_GETUSERSHELL)
  check_symbol_exists("setusershell" "unistd.h" HAVE_SETUSERSHELL)
  check_symbol_exists("endusershell" "unistd.h" HAVE_ENDUSERSHELL)
else ()
  set(HAVE_GETUSERSHELL "" CACHE INTERNAL "")
  set(HAVE_SETUSERSHELL "" CACHE INTERNAL "")
  set(HAVE_ENDUSERSHELL "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_ENDUSERSHELL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_GETUSERSHELL "1" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_SETUSERSHELL "1" CACHE INTERNAL "")

if (NOT HAVE_GETUSERHSELL OR NOT HAVE_ENDUSERSHELL OR NOT HAVE_SETUSERSHELL)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()
