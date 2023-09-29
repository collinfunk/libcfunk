include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

set(LIBCFUNK_UNLOCKED_STDIO "1" CACHE INTERNAL "")

check_c_symbol("flockfile" "stdio.h")
check_c_symbol("_lock_file" "stdio.h")
check_c_symbol("funlockfile" "stdio.h")
check_c_symbol("_unlock_file" "stdio.h")
check_c_symbol("getchar_unlocked" "stdio.h")
check_c_symbol("_getchar_nolock" "stdio.h")
check_c_symbol("getc_unlocked" "stdio.h")
check_c_symbol("_getc_nolock" "stdio.h")
check_c_symbol("putchar_unlocked" "stdio.h")
check_c_symbol("_putchar_nolock" "stdio.h")
check_c_symbol("putc_unlocked" "stdio.h")
check_c_symbol("_putc_nolock" "stdio.h")

