
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

if ($CACHE{LIBCFUNK_GENERATE_ALLOCA_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/alloca.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/alloca.h
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

if ($CACHE{LIBCFUNK_GENERATE_ERR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/err.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/err.h
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

if ($CACHE{LIBCFUNK_GENERATE_INTTYPES_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/inttypes.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/inttypes.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_LIMITS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/limits.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/limits.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_MALLOC_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/malloc.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/malloc.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_NETDB_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/netdb.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/netdb.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_NETINET_IN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/netinet/in.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/netinet/in.h
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

if ($CACHE{LIBCFUNK_GENERATE_SCHED_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sched.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sched.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SIGNAL_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/signal.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/signal.h
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

if ($CACHE{LIBCFUNK_GENERATE_STDINT_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/stdint.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/stdint.h
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

if ($CACHE{LIBCFUNK_GENERATE_SYS_ENDIAN_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/endian.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/endian.h
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

if ($CACHE{LIBCFUNK_GENERATE_SYS_RANDOM_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/sys/random.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/sys/random.h
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

if ($CACHE{LIBCFUNK_GENERATE_TERMIOS_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/termios.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/termios.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TIME_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/time.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UNISTD_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/unistd.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/unistd.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_WCHAR_H})
  substitute_header(
    $CACHE{LIBCFUNK_SOURCE_DIR}/compat/wchar.h.in
    $CACHE{LIBCFUNK_CONFIG_DIR}/wchar.h
  )
endif ()

configure_file(
  $CACHE{LIBCFUNK_SOURCE_DIR}/config.h.cmake
  $CACHE{LIBCFUNK_CONFIG_DIR}/config.h
)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_CONFIG_DIR}/config.h
)
