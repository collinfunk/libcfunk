
add_library(cfunk)

target_include_directories("cfunk" PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_BINARY_DIR})

# Convert a boolean representation to a 1 or 0 string for use with
# the C preprocessor
function (bool_to_int str_var bool_var)
  if (${bool_var})
    set(${str_var} "1" PARENT_SCOPE)
  else ()
    set(${str_var} "0" PARENT_SCOPE)
  endif ()
endfunction ()

# Set a local variable to the given value if it does not exist in the cache.
function (set_if_uncached variable value)
  if (NOT DEFINED CACHE{${variable}})
    set(${variable} ${value} PARENT_SCOPE)
  endif ()
endfunction ()

if (LIBCFUNK_MODULE_BASE16)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/base16.c
    ${CMAKE_CURRENT_LIST_DIR}/base16.h
  )
endif ()

if (LIBCFUNK_MODULE_BASE32)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/base32.c
    ${CMAKE_CURRENT_LIST_DIR}/base32.h
  )
endif ()

if (LIBCFUNK_MODULE_BASE64)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/base64.c
    ${CMAKE_CURRENT_LIST_DIR}/base64.h
  )
endif ()

if (LIBCFUNK_MODULE_BCMP)
  if (NOT HAVE_BCMP)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/bcmp.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_BCOPY)
  if (NOT HAVE_BCOPY)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/bcopy.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_BSTREE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/bstree.c
    ${CMAKE_CURRENT_LIST_DIR}/bstree.h
  )
endif ()

if (LIBCFUNK_MODULE_BSWAP)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/bswap.h
  )
endif ()

if (LIBCFUNK_MODULE_BZERO)
  if (NOT HAVE_BZERO)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/bzero.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_CIRCULAR_SHIFT)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/circular-shift.h
  )
endif ()

if (LIBCFUNK_MODULE_COPY_FILE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/copy-file.c
    ${CMAKE_CURRENT_LIST_DIR}/copy-file.h
  )
endif ()

if (LIBCFUNK_MODULE_CPU_COUNT)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/cpu-count.c
    ${CMAKE_CURRENT_LIST_DIR}/cpu-count.h
  )
endif ()

if (LIBCFUNK_MODULE_CRC32)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/crc32.h
    ${CMAKE_CURRENT_LIST_DIR}/crc32.c
  )
endif ()

if (LIBCFUNK_MODULE_ERR)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/err.c
  )
endif ()

if (LIBCFUNK_MODULE_ERROR)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/error.c
  )
endif ()

if (LIBCFUNK_MODULE_FFS)
  if (NOT HAVE_FFS)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ffs.c)
  endif ()
  if (NOT HAVE_FFSL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ffsl.c)
  endif ()
  if (NOT HAVE_FFSL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ffsll.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_FILENAME)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/filename.c
    ${CMAKE_CURRENT_LIST_DIR}/filename.h
  )
endif ()

if (LIBCFUNK_MODULE_FLS)
  if (NOT HAVE_FLS)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/fls.c)
  endif ()
  if (NOT HAVE_FLSL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/flsl.c)
  endif ()
  if (NOT HAVE_FLSL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/flsll.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_GCD)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/gcd.c
    ${CMAKE_CURRENT_LIST_DIR}/gcd.h
  )
endif ()

if (LIBCFUNK_MODULE_GETENTROPY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getentropy.c
  )
endif ()

if (LIBCFUNK_MODULE_GETRANDOM)
  if (HAVE_WINDOWS_H AND HAVE_BCRYPT_H)
    target_link_libraries(cfunk PRIVATE bcrypt)
  endif ()
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/getrandom.c
  )
endif ()

if (LIBCFUNK_MODULE_GET_UMASK)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/get-umask.h
    ${CMAKE_CURRENT_LIST_DIR}/get-umask.c
  )
endif ()

if (LIBCFUNK_MODULE_INDEX)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/index.c
  )
endif ()

if (LIBCFUNK_MODULE_INT_OVERFLOW)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/int-overflow.h
  )
endif ()

if (LIBCFUNK_MODULE_LIST)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/list.c
    ${CMAKE_CURRENT_LIST_DIR}/list.h
  )
endif ()

if (LIBCFUNK_MODULE_PHYSICAL_MEMORY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/physical-memory.c
    ${CMAKE_CURRENT_LIST_DIR}/physical-memory.h
  )
endif ()

if (LIBCFUNK_MODULE_POPCOUNT)
  if (NOT HAVE_POPCOUNT)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/popcount.c)
  endif ()
  if (NOT HAVE_POPCOUNTL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/popcountl.c)
  endif ()
  if (NOT HAVE_POPCOUNTLL)
    target_sources(cfunk PRIVATE ${CMAKE_CURRENT_LIST_DIR}/popcountll.c)
  endif ()
endif ()

if (LIBCFUNK_MODULE_PROGRAM_NAME)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/program-name.c
    ${CMAKE_CURRENT_LIST_DIR}/program-name.h
  )
endif ()

if (LIBCFUNK_MODULE_RBTREE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/rbtree.c
    ${CMAKE_CURRENT_LIST_DIR}/rbtree.h
  )
endif ()

if (LIBCFUNK_MODULE_READ_FULL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/read-full.c
    ${CMAKE_CURRENT_LIST_DIR}/read-full.h
  )
endif ()

if (LIBCFUNK_MODULE_READ_NOINTR)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/read-nointr.c
    ${CMAKE_CURRENT_LIST_DIR}/read-nointr.h
  )
endif ()

if (LIBCFUNK_MODULE_RINDEX)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/rindex.c
  )
endif ()


if (LIBCFUNK_MODULE_SLIST)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/slist.c
    ${CMAKE_CURRENT_LIST_DIR}/slist.h
  )
endif ()

if (LIBCFUNK_MODULE_SPLAY_TREE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/splay-tree.c
    ${CMAKE_CURRENT_LIST_DIR}/splay-tree.h
  )
endif ()

if (LIBCFUNK_MODULE_WRITE_FULL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/write-full.c
    ${CMAKE_CURRENT_LIST_DIR}/write-full.h
  )
endif ()

if (LIBCFUNK_MODULE_WRITE_NOINTR)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/write-nointr.c
    ${CMAKE_CURRENT_LIST_DIR}/write-nointr.h
  )
endif ()

if (LIBCFUNK_MODULE_ERR_H)
  bool_to_int(HAVE_ERR_H "${HAVE_ERR_H}")
  bool_to_int(HAVE_ERR "${HAVE_ERR}")
  bool_to_int(HAVE_VERR "${HAVE_VERR}")
  bool_to_int(HAVE_ERRC "${HAVE_ERRC}")
  bool_to_int(HAVE_VERRC "${HAVE_VERRC}")
  bool_to_int(HAVE_ERRX "${HAVE_ERRX}")
  bool_to_int(HAVE_VERRX "${HAVE_VERRX}")
  bool_to_int(HAVE_WARN "${HAVE_WARN}")
  bool_to_int(HAVE_VWARN "${HAVE_VWARN}")
  bool_to_int(HAVE_WARNC "${HAVE_WARNC}")
  bool_to_int(HAVE_VWARNC "${HAVE_VWARNC}")
  bool_to_int(HAVE_WARNX "${HAVE_WARNX}")
  bool_to_int(HAVE_VWARNX "${HAVE_VWARNX}")
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/compat/err.h.in
    ${CMAKE_BINARY_DIR}/err.h
  )
endif ()

if (LIBCFUNK_MODULE_ERROR_H)
  bool_to_int(HAVE_ERROR_H "${HAVE_ERROR_H}")
  bool_to_int(HAVE_ERROR_MESSAGE_COUNT "${HAVE_ERROR_MESSAGE_COUNT}")
  bool_to_int(HAVE_ERROR_ONE_PER_LINE "${HAVE_ERROR_ONE_PER_LINE}")
  bool_to_int(HAVE_ERROR_PRINT_PROGNAME "${HAVE_ERROR_PRINT_PROGNAME}")
  bool_to_int(HAVE_ERROR "${HAVE_ERROR}")
  bool_to_int(HAVE_ERROR_AT_LINE "${HAVE_ERROR_AT_LINE}")
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/compat/error.h.in
    ${CMAKE_BINARY_DIR}/error.h
  )
endif ()

if (LIBCFUNK_MODULE_STRINGS_H)
  bool_to_int(LIBCFUNK_DECLARE_BCMP "${LIBCFUNK_MODULE_BCMP}")
  bool_to_int(LIBCFUNK_DECLARE_BCOPY "${LIBCFUNK_MODULE_BCMP}")
  bool_to_int(LIBCFUNK_DECLARE_BZERO "${LIBCFUNK_MODULE_BZERO}")
  bool_to_int(LIBCFUNK_DECLARE_FFS "${LIBCFUNK_MODULE_FFS}")
  bool_to_int(LIBCFUNK_DECLARE_FFSL "${LIBCFUNK_MODULE_FFS}")
  bool_to_int(LIBCFUNK_DECLARE_FFSLL "${LIBCFUNK_MODULE_FFS}")
  bool_to_int(LIBCFUNK_DECLARE_FLS "${LIBCFUNK_MODULE_FLS}")
  bool_to_int(LIBCFUNK_DECLARE_FLSL "${LIBCFUNK_MODULE_FLS}")
  bool_to_int(LIBCFUNK_DECLARE_FLSLL "${LIBCFUNK_MODULE_FLS}")
  bool_to_int(LIBCFUNK_DECLARE_INDEX "${LIBCFUNK_MODULE_INDEX}")
  bool_to_int(LIBCFUNK_DECLARE_POPCOUNT "${LIBCFUNK_MODULE_POPCOUNT}")
  bool_to_int(LIBCFUNK_DECLARE_POPCOUNTL "${LIBCFUNK_MODULE_POPCOUNT}")
  bool_to_int(LIBCFUNK_DECLARE_POPCOUNTLL "${LIBCFUNK_MODULE_POPCOUNT}")
  bool_to_int(LIBCFUNK_DECLARE_RINDEX "${LIBCFUNK_MODULE_RINDEX}")
  bool_to_int(HAVE_STRING_H "${HAVE_STRING_H}")
  bool_to_int(HAVE_BCMP "${HAVE_BCMP}")
  bool_to_int(HAVE_BCOPY "${HAVE_BCMP}")
  bool_to_int(HAVE_BZERO "${HAVE_BZERO}")
  bool_to_int(HAVE_FFS "${HAVE_FFS}")
  bool_to_int(HAVE_FFSL "${HAVE_FFSL}")
  bool_to_int(HAVE_FFSLL "${HAVE_FFSLL}")
  bool_to_int(HAVE_FLS "${HAVE_FLS}")
  bool_to_int(HAVE_FLSL "${HAVE_FLSL}")
  bool_to_int(HAVE_FLSLL "${HAVE_FLSLL}")
  bool_to_int(HAVE_INDEX "${HAVE_INDEX}")
  bool_to_int(HAVE_POPCOUNT "${HAVE_POPCOUNT}")
  bool_to_int(HAVE_POPCOUNTL "${HAVE_POPCOUNTL}")
  bool_to_int(HAVE_POPCOUNTLL "${HAVE_POPCOUNTLL}")
  bool_to_int(HAVE_RINDEX "${HAVE_RINDEX}")
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/compat/strings.h.in
    ${CMAKE_BINARY_DIR}/strings.h
  )
endif ()

if (LIBCFUNK_MODULE_SYS_RANDOM_H)
  bool_to_int(LIBCFUNK_DECLARE_GETRANDOM "${LIBCFUNK_MODULE_GETRANDOM}")
  bool_to_int(LIBCFUNK_DECLARE_GETENTROPY "${LIBCFUNK_MODULE_GETENTROPY}")
  bool_to_int(HAVE_SYS_RANDOM_H "${HAVE_SYS_RANDOM_H}")
  bool_to_int(HAVE_GETRANDOM "${HAVE_GETRANDOM}")
  bool_to_int(HAVE_GETENTROPY "${HAVE_GETENTROPY}")
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/compat/sys/random.h.in
    ${CMAKE_BINARY_DIR}/sys/random.h
  )
endif ()
