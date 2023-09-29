
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/getgroups.cmake)

check_c_symbol("group_member" "unistd.h")

set(LIBCFUNK_DECLARE_GROUP_MEMBER "1" CACHE INTERNAL "")

if (NOT HAVE_GROUP_MEMBER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/group-member.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-group-member.cmake)
endif ()

