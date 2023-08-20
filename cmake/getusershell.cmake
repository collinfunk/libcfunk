
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/unistd.cmake)

check_symbol_exists(getusershell "unistd.h" HAVE_GETUSERSHELL)
check_symbol_exists(setusershell "unistd.h" HAVE_SETUSERSHELL)
check_symbol_exists(endusershell "unistd.h" HAVE_ENDUSERSHELL)

set(LIBCFUNK_DECLARE_GETUSERSHELL 1)
set(LIBCFUNK_DECLARE_SETUSERSHELL 1)
set(LIBCFUNK_DECLARE_ENDUSERSHELL 1)

if (NOT HAVE_GETUSERSHELL)
  set(HAVE_GETUSERSHELL 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()

if (NOT HAVE_SETUSERSHELL)
  set(HAVE_SETUSERSHELL 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()

if (NOT HAVE_GETUSERSHELL)
  set(HAVE_GETUSERSHELL 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()

if (NOT HAVE_ENDUSERSHELL)
  set(HAVE_ENDUSERSHELL 0)
  target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getusershell.c
  )
endif ()
