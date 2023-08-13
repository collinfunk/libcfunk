
# TODO:
# Move these into cmake files for modular builds.

if (HAVE_STRING_H)
  check_symbol_exists(strchrnul "string.h" HAVE_STRCHRNUL)
  check_symbol_exists(strmode "string.h" HAVE_STRMODE)
  check_symbol_exists(explicit_bzero "string.h" HAVE_EXPLICIT_BZERO)
  check_symbol_exists(memset_explicit "string.h" HAVE_MEMSET_EXPLICIT)
  check_symbol_exists(SecureZeroMemory "windows.h" HAVE_SECUREZEROMEMORY)
  check_symbol_exists(strdup "string.h" HAVE_STRDUP)
  check_symbol_exists(strndup "string.h" HAVE_STRNDUP)
  check_symbol_exists(stpcpy "string.h" HAVE_STPCPY)
else ()
  # If we don't put these CMake won't replace @HAVE_STRING_H@ with 0 :(
  set(HAVE_STRING_H 0)
endif ()

if (HAVE_STDIO_H)
  check_symbol_exists(flockfile "stdio.h" HAVE_FLOCKFILE)
  check_symbol_exists(funlockfile "stdio.h" HAVE_FUNLOCKFILE)
  check_symbol_exists(getc_unlocked "stdio.h" HAVE_GETC_UNLOCKED)
  check_symbol_exists(getchar_unlocked "stdio.h" HAVE_GETCHAR_UNLOCKED)
  check_symbol_exists(putc_unlocked "stdio.h" HAVE_PUTC_UNLOCKED)
  check_symbol_exists(putchar_unlocked "stdio.h" HAVE_PUTCHAR_UNLOCKED)
  check_symbol_exists(_lock_file "stdio.h" HAVE__LOCK_FILE)
  check_symbol_exists(_unlock_file "stdio.h" HAVE__UNLOCK_FILE)
  check_symbol_exists(_getc_nolock "stdio.h" HAVE__GETC_NOLOCK)
  check_symbol_exists(_getchar_nolock "stdio.h" HAVE__GETCHAR_NOLOCK)
  check_symbol_exists(_putc_nolock "stdio.h" HAVE__PUTC_NOLOCK)
  check_symbol_exists(_putchar_nolock "stdio.h" HAVE__PUTCHAR_NOLOCK)
  check_symbol_exists(getdelim "stdio.h" HAVE_GETDELIM)
  check_symbol_exists(getline "stdio.h" HAVE_GETLINE)
else ()
  set(HAVE_STDIO_H 0)
endif ()

check_type_size("char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

target_sources(cfunk PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/bstree.h
  ${LIBCFUNK_SOURCE_DIR}/bswap.h
  ${LIBCFUNK_SOURCE_DIR}/circular-shift.h
  ${LIBCFUNK_SOURCE_DIR}/crc32.h
  ${LIBCFUNK_SOURCE_DIR}/hash-map.h
  ${LIBCFUNK_SOURCE_DIR}/list.h
  ${LIBCFUNK_SOURCE_DIR}/md4.h
  ${LIBCFUNK_SOURCE_DIR}/md5.h
  ${LIBCFUNK_SOURCE_DIR}/rbtree.h
  ${LIBCFUNK_SOURCE_DIR}/sha256.h
  ${LIBCFUNK_SOURCE_DIR}/sha512.h
  ${LIBCFUNK_SOURCE_DIR}/slist.h
  ${LIBCFUNK_SOURCE_DIR}/splay-tree.h
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.h
  ${LIBCFUNK_SOURCE_DIR}/bstree.c
  ${LIBCFUNK_SOURCE_DIR}/crc32.c
  ${LIBCFUNK_SOURCE_DIR}/hash-map.c
  ${LIBCFUNK_SOURCE_DIR}/list.c
  ${LIBCFUNK_SOURCE_DIR}/md4.c
  ${LIBCFUNK_SOURCE_DIR}/md5.c
  ${LIBCFUNK_SOURCE_DIR}/rbtree.c
  ${LIBCFUNK_SOURCE_DIR}/sha256.c
  ${LIBCFUNK_SOURCE_DIR}/sha512.c
  ${LIBCFUNK_SOURCE_DIR}/slist.c
  ${LIBCFUNK_SOURCE_DIR}/splay-tree.c
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.c
)

if (NOT HAVE_STRCHRNUL)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strchrnul.c
  )
endif ()

if (NOT HAVE_STRMODE)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strmode.c
  )
endif ()

if (NOT HAVE_EXPLICIT_BZERO)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/explicit-bzero.c
  )
endif ()

if (NOT HAVE_STRDUP)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strdup.c
  )
endif ()

if (NOT HAVE_STRNDUP)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/strndup.c
  )
endif ()

if (NOT HAVE_STPCPY)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/stpcpy.c
  )
endif ()

if (NOT HAVE_GETDELIM)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getdelim.c
  )
endif ()

if (NOT HAVE_GETLINE)
  target_sources(cfunk PRIVATE
    ${LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()

