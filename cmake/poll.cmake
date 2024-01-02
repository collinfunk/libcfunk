
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/poll-h.cmake)

if (HAVE_POLL_H)
  check_symbol_exists("poll" "poll.h" HAVE_POLL)
endif ()

# TODO
if (NOT HAVE_POLL)
  message(FATAL_ERROR "No implementation of 'poll' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

