
include_guard(GLOBAL)

# Create a configure file substituting missing variables with 0.
function (substitute_header template_file output_file)
  if (NOT EXISTS "${template_file}")
    message(FATAL_ERROR "Template file `${template_file}' does not exist.")
  endif ()
  file(READ "${template_file}" TEMPLATE_CONTENTS)
  string(REGEX MATCHALL "@[A-Za-z1-9_]+@" VARIABLE_LIST "${TEMPLATE_CONTENTS}")
  if (NOT VARIABLE_LIST)
    configure_file("${template_file}" "${output_file}")
    return ()
  endif ()
  string(REPLACE "@" "" VARIABLE_LIST "${VARIABLE_LIST}")
  foreach (VARIABLE ${VARIABLE_LIST})
    if ("${${VARIABLE}}" STREQUAL "" OR "${${VARIABLE}}" STREQUAL "FALSE")
      set("${VARIABLE}" "0")
    elseif ("${${VARIABLE}}" STREQUAL "TRUE")
      set("${VARIABLE}" "1")
    endif ()
  endforeach ()
  configure_file("${template_file}" "${output_file}")
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    "${output_file}"
  )
endfunction ()

# Make sure that the library always has atleast one C source so that
# configuration does not fail. This is needed if a project only uses
# a header, for example.
get_target_property(LIBCFUNK_SOURCES $CACHE{LIBCFUNK_LIBRARY_NAME} SOURCES)
string(REGEX MATCH "[A-Za-z0-9_/-]+\\.c" LIBCFUNK_HAS_SOURCES "${LIBCFUNK_SOURCES}")
if (NOT LIBCFUNK_HAS_SOURCES)
  target_sources($CACHE{LIBCFUNK_LIBRARY_NAME} PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/dummy.c
  )
endif ()
unset(LIBCFUNK_SOURCES)
unset(LIBCFUNK_HAS_SOURCES)

# Below are conditionals to generate optional headers. Keep sorted.

if ($CACHE{LIBCFUNK_GENERATE_ALLOCA_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/alloca.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/alloca.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ARGZ_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/argz.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/argz.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_AR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/ar.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/ar.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ARPA_INET_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/arpa/inet.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/arpa/inet.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ASSERT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/assert.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/assert.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_BYTESWAP_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/byteswap.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/byteswap.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_CPIO_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/cpio.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/cpio.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_CTYPE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/ctype.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/ctype.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_DIRENT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/dirent.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/dirent.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ENDIAN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/endian.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/endian.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/err.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/err.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERRNO_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/errno.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/errno.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERROR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/error.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/error.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FCNTL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/fcntl.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/fcntl.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FENV_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/fenv.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/fenv.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FLOAT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/float.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/float.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FMTMSG_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/fmtmsg.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/fmtmsg.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FNMATCH_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/fnmatch.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/fnmatch.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_FTW_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/ftw.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/ftw.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_GETOPT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/getopt.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/getopt.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_GLOB_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/glob.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/glob.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_GRP_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/grp.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/grp.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ICONV_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/iconv.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/iconv.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_INTTYPES_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/inttypes.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/inttypes.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_LANGINFO_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/langinfo.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/langinfo.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_LIBGEN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/libgen.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/libgen.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_LIMITS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/limits.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/limits.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_LOCALE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/locale.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/locale.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_MALLOC_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/malloc.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/malloc.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_MATH_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/math.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/math.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_MONETARY_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/monetary.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/monetary.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_NETDB_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/netdb.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/netdb.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_NET_IF_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/net/if.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/net/if.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_NETINET_IN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/netinet/in.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/netinet/in.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_POLL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/poll.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/poll.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_PTHREAD_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/pthread.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/pthread.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_PTY_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/pty.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/pty.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_PWD_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/pwd.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/pwd.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SCHED_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sched.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sched.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SEARCH_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/search.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/search.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SEMAPHORE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/semaphore.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/semaphore.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SPAWN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/spawn.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/spawn.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SIGNAL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/signal.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/signal.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDARG_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdarg.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdarg.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDATOMIC_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdatomic.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdatomic.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDBIT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdbit.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdbit.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDBOOL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdbool.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdbool.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDCKDINT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdckdint.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdckdint.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDDEF_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stddef.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stddef.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDINT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdint.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdint.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDIO_EXT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdio_ext.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdio_ext.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDIO_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdio.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdio.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDLIB_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdlib.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdlib.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDALIGN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdalign.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdalign.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDNORETURN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdnoreturn.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdnoreturn.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRING_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/string.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/string.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRINGS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/strings.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/strings.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYSEXITS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sysexits.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sysexits.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_FILE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/file.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/file.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_IOCTL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/ioctl.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/ioctl.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_MMAN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/mman.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/mman.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_MSG_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/msg.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/msg.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_RANDOM_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/random.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/random.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_RESOURCE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/resource.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/resource.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_SELECT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/select.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/select.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_SEM_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/sem.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/sem.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_SHM_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/shm.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/shm.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_SOCKET_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/socket.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/socket.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_STAT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/stat.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/stat.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_STATVFS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/statvfs.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/statvfs.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TIMEB_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/timeb.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/timeb.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TIME_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/time.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TIMES_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/times.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/times.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TYPES_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/types.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/types.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_UIO_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/uio.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/uio.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_UN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/un.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/un.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_UTSNAME_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/utsname.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/utsname.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_WAIT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/wait.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/wait.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TAR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/tar.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/tar.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TERMIOS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/termios.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/termios.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_THREADS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/threads.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/threads.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TIME_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/time.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UCHAR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/uchar.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/uchar.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ULIMIT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/ulimit.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/ulimit.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UNISTD_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/unistd.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/unistd.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UTIME_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/utime.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/utime.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UTMP_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/utmp.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/utmp.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UTMPX_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/utmpx.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/utmpx.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_WCHAR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/wchar.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/wchar.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_WCTYPE_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/wctype.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/wctype.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_WORDEXP_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/wordexp.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/wordexp.h
  )
endif ()

configure_file(
  $CACHE{LIBCFUNK_SOURCE_DIR}/config.h.cmake
  $CACHE{LIBCFUNK_CONFIG_DIR}/config.h
)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_CONFIG_DIR}/config.h
)
