
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/getgroups.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("group_member" "unistd.h" HAVE_GROUP_MEMBER)
endif ()

set(LIBCFUNK_DECLARE_GROUP_MEMBER "1" CACHE STRING "")

if (NOT HAVE_GROUP_MEMBER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/group_member.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-group_member.cmake)
endif ()

