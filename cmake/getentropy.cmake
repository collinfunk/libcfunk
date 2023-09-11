
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-random-h.cmake)

# This is implemented in a system call on most operating systems
# and provided by glibc in <sys/random.h>. Check unistd.h and sys/random.h.
check_symbol_exists("getentropy" "unistd.h;sys/random.h" HAVE_GETENTROPY)

set(LIBCFUNK_DECLARE_GETENTROPY "1" CACHE INTERNAL "")

# Provided a replacement function using getrandom
if (NOT HAVE_GETENTROPY)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getrandom.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getentropy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getentropy.cmake)
endif ()

