
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/stdio.cmake)

check_symbol_exists(flockfile "stdio.h" HAVE_FLOCKFILE)
check_symbol_exists(funlockfile "stdio.h" HAVE_FUNLOCKFILE)
check_symbol_exists(getc_unlocked "stdio.h" HAVE_GETC_UNLOCKED)
check_symbol_exists(getchar_unlocked "stdio.h" HAVE_GETCHAR_UNLOCKED)
check_symbol_exists(putc_unlocked "stdio.h" HAVE_PUTC_UNLOCKED)
check_symbol_exists(putchar_unlocked "stdio.h" HAVE_PUTCHAR_UNLOCKED)

if (NOT HAVE_FLOCKFILE)
  set (HAVE_FLOCKFILE 0)
  check_symbol_exists(_lock_file "stdio.h" HAVE__LOCK_FILE)
endif ()

if (NOT HAVE_FUNLOCKFILE)
  set (HAVE_FUNLOCKFILE 0)
  check_symbol_exists(_unlock_file "stdio.h" HAVE__UNLOCK_FILE)
endif()

if (NOT HAVE_GETC_UNLOCKED)
  set (HAVE_GETC_UNLOCKED 0)
  check_symbol_exists(_getc_nolock "stdio.h" HAVE__GETC_NOLOCK)
endif ()

if (NOT HAVE_GETCHAR_UNLOCKED)
  set (HAVE_GETCHAR_UNLOCKED 0)
  check_symbol_exists(_getchar_nolock "stdio.h" HAVE__GETCHAR_NOLOCK)
endif ()

if (NOT HAVE_PUTC_UNLOCKED)
  set (HAVE_PUTC_UNLOCKED 0)
  check_symbol_exists(_putc_nolock "stdio.h" HAVE__PUTC_NOLOCK)
endif ()

if (NOT HAVE_PUTCHAR_UNLOCKED)
  set (HAVE_PUTCHAR_UNLOCKED 0)
  check_symbol_exists(_putchar_nolock "stdio.h" HAVE__PUTCHAR_NOLOCK)
endif ()

if (NOT HAVE__LOCK_FILE)
  set(HAVE__LOCK_FILE 0)
endif ()

if (NOT HAVE__UNLOCK_FILE)
  set(HAVE__UNLOCK_FILE 0)
endif ()

if (NOT HAVE__GETC_NOLOCK)
  set(HAVE__GETC_NOLOCK 0)

endif ()

if (NOT HAVE__GETCHAR_NOLOCK)
  set(HAVE__GETCHAR_NOLOCK 0)
endif ()

if (NOT HAVE__PUTC_NOLOCK)
  set(HAVE__PUTC_NOLOCK 0)
endif ()

if (NOT HAVE__PUTCHAR_NOLOCK)
  set(HAVE__PUTCHAR_NOLOCK 0)
endif ()

