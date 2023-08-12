
add_library(cfunk)

target_include_directories(cfunk PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/
  ${CMAKE_CURRENT_BINARY_DIR}/
  ${CMAKE_CURRENT_BINARY_DIR}/compat/
)

list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")

# string.h
check_include_file("string.h" HAVE_STRING_H)
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

# strings.h
check_include_file("strings.h" HAVE_STRINGS_H)
if (HAVE_STRINGS_H)
  check_symbol_exists(ffs "strings.h" HAVE_FFS)
  check_symbol_exists(ffsl "strings.h" HAVE_FFSL)
  check_symbol_exists(ffsll "strings.h" HAVE_FFSLL)
  check_symbol_exists(fls "strings.h" HAVE_FLS)
  check_symbol_exists(flsl "strings.h" HAVE_FLSL)
  check_symbol_exists(flsll "strings.h" HAVE_FLSLL)
  check_symbol_exists(popcount "strings.h" HAVE_POPCOUNT)
  check_symbol_exists(popcountl "strings.h" HAVE_POPCOUNTL)
  check_symbol_exists(popcountll "strings.h" HAVE_POPCOUNTLL)
else ()
  set(HAVE_STRINGS_H 0)
endif ()

# stdlib.h
check_include_file("stdlib.h" HAVE_STDLIB_H)
if (HAVE_STDLIB_H)
  check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)
else ()
  set(HAVE_STDLIB_H 0)
endif ()

# stdio.h
check_include_file("stdio.h" HAVE_STDIO_H)
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

check_include_file("sys/random.h" HAVE_SYS_RANDOM_H)
if (HAVE_SYS_RANDOM_H)
  check_symbol_exists(getrandom "sys/random.h" HAVE_GETRANDOM)
  check_symbol_exists(getentropy "sys/random.h" HAVE_GETENTROPY)
else ()
  check_include_files("windows.h;bcrypt.h" HAVE_BCRYPT_H)
  if (HAVE_BCRYPT_H)
    target_link_libraries(cfunk PUBLIC "bcrypt")
  else ()
    set(HAVE_BCRYPT_H 0)
  endif ()
  set(HAVE_SYS_RANDOM_H 0)
endif ()

check_include_file("stdint.h" HAVE_STDINT_H)
check_include_file("inttypes.h" HAVE_INTTYPES_H)

if (NOT HAVE_STDINT_H)
  set(HAVE_STDINT_H 0)
endif ()

if (NOT HAVE_INTTYPES_H)
  set(HAVE_INTTYPES_H 0)
endif ()

check_type_size("char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/string.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/string.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/strings.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/strings.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/stdlib.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/stdlib.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/stdio.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/stdio.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/stdint.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/stdint.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/inttypes.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/inttypes.h
)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/compat/sys/random.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/compat/sys/random.h
)

target_sources(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/bstree.h
  ${CMAKE_CURRENT_LIST_DIR}/bswap.h
  ${CMAKE_CURRENT_LIST_DIR}/circular-shift.h
  ${CMAKE_CURRENT_LIST_DIR}/crc32.h
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.h
  ${CMAKE_CURRENT_LIST_DIR}/list.h
  ${CMAKE_CURRENT_LIST_DIR}/md4.h
  ${CMAKE_CURRENT_LIST_DIR}/md5.h
  ${CMAKE_CURRENT_LIST_DIR}/rbtree.h
  ${CMAKE_CURRENT_LIST_DIR}/read-full.h
  ${CMAKE_CURRENT_LIST_DIR}/read-nointr.h
  ${CMAKE_CURRENT_LIST_DIR}/sha256.h
  ${CMAKE_CURRENT_LIST_DIR}/sha512.h
  ${CMAKE_CURRENT_LIST_DIR}/slist.h
  ${CMAKE_CURRENT_LIST_DIR}/splay-tree.h
  ${CMAKE_CURRENT_LIST_DIR}/write-full.h
  ${CMAKE_CURRENT_LIST_DIR}/write-nointr.h
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.h
  ${CMAKE_CURRENT_LIST_DIR}/bstree.c
  ${CMAKE_CURRENT_LIST_DIR}/crc32.c
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.c
  ${CMAKE_CURRENT_LIST_DIR}/list.c
  ${CMAKE_CURRENT_LIST_DIR}/md4.c
  ${CMAKE_CURRENT_LIST_DIR}/md5.c
  ${CMAKE_CURRENT_LIST_DIR}/rbtree.c
  ${CMAKE_CURRENT_LIST_DIR}/read-full.c
  ${CMAKE_CURRENT_LIST_DIR}/read-nointr.c
  ${CMAKE_CURRENT_LIST_DIR}/sha256.c
  ${CMAKE_CURRENT_LIST_DIR}/sha512.c
  ${CMAKE_CURRENT_LIST_DIR}/slist.c
  ${CMAKE_CURRENT_LIST_DIR}/splay-tree.c
  ${CMAKE_CURRENT_LIST_DIR}/write-full.c
  ${CMAKE_CURRENT_LIST_DIR}/write-nointr.c
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.c
)

if (NOT HAVE_STRCHRNUL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strchrnul.c
  )
endif ()

if (NOT HAVE_STRMODE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strmode.c
  )
endif ()

if (NOT HAVE_EXPLICIT_BZERO)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/explicit-bzero.c
  )
endif ()

if (NOT HAVE_STRDUP)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strdup.c
  )
endif ()

if (NOT HAVE_STRNDUP)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strndup.c
  )
endif ()

if (NOT HAVE_STPCPY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/stpcpy.c
  )
endif ()

if (NOT HAVE_FFS)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffs.c
  )
endif ()

if (NOT HAVE_FFSL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffsl.c
  )
endif ()

if (NOT HAVE_FFSLL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffsll.c
  )
endif ()

if (NOT HAVE_FLS)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fls.c
  )
endif ()

if (NOT HAVE_FLSL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/flsl.c
  )
endif ()

if (NOT HAVE_FLSLL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/flsll.c
  )
endif ()

if (NOT HAVE_POPCOUNT)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/popcount.c
  )
endif ()

if (NOT HAVE_POPCOUNTL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/popcountl.c
  )
endif ()

if (NOT HAVE_POPCOUNTLL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/popcountll.c
  )
endif ()

if (NOT HAVE_REALLOCARRAY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/reallocarray.c
  )
endif ()

if (NOT HAVE_GETDELIM)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getdelim.c
  )
endif ()

if (NOT HAVE_GETLINE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getline.c
  )
endif ()

if (NOT HAVE_GETRANDOM)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getrandom.c
  )
endif ()


if (NOT HAVE_GETENTROPY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getentropy.c
  )
endif ()
