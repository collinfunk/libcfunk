
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

set(LIBCFUNK_UNLOCKED_STDIO "1" CACHE STRING "")

check_symbol_exists("flockfile" "stdio.h" HAVE_FLOCKFILE)
check_symbol_exists("_lock_file" "stdio.h" HAVE__LOCK_FILE)
check_symbol_exists("funlockfile" "stdio.h" HAVE_FUNLOCKFILE)
check_symbol_exists("_unlock_file" "stdio.h" HAVE__UNLOCK_FILE)
check_symbol_exists("getchar_unlocked" "stdio.h" HAVE_GETCHAR_UNLOCKED)
check_symbol_exists("_getchar_nolock" "stdio.h" HAVE__GETCHAR_NOLOCK)
check_symbol_exists("getc_unlocked" "stdio.h" HAVE_GETC_UNLOCKED)
check_symbol_exists("_getc_nolock" "stdio.h" HAVE__GETC_NOLOCK)
check_symbol_exists("putchar_unlocked" "stdio.h" HAVE_PUTCHAR_UNLOCKED)
check_symbol_exists("_putchar_nolock" "stdio.h" HAVE__PUTCHAR_NOLOCK)
check_symbol_exists("putc_unlocked" "stdio.h" HAVE_PUTC_UNLOCKED)
check_symbol_exists("_putc_nolock" "stdio.h" HAVE__PUTC_NOLOCK)

