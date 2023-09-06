
# Convert variables to 0/1's that are suitable for use in
# configuration files using the c preprocessor.
function (bool_to_int str_var bool_var)
  if (${bool_var})
    set(${str_var} "1" PARENT_SCOPE)
  else ()
    set(${str_var} "0" PARENT_SCOPE)
  endif ()
endfunction ()

configure_file(
  ${LIBCFUNK_SOURCE_DIR}/config.h.cmake
  ${LIBCFUNK_BUILD_DIR}/config.h
)

if ($CACHE{LIBCFUNK_GENERATE_CTYPE_H})
  bool_to_int(HAVE_CTYPE_H "$CACHE{HAVE_CTYPE_H}")
  bool_to_int(HAVE_ISALNUM "$CACHE{HAVE_ISALNUM}")
  bool_to_int(HAVE_ISALPHA "$CACHE{HAVE_ISALPHA}")
  bool_to_int(HAVE_ISASCII "$CACHE{HAVE_ISASCII}")
  bool_to_int(HAVE_ISBLANK "$CACHE{HAVE_ISBLANK}")
  bool_to_int(HAVE_ISCNTRL "$CACHE{HAVE_ISCNTRL}")
  bool_to_int(HAVE_ISDIGIT "$CACHE{HAVE_ISDIGIT}")
  bool_to_int(HAVE_ISGRAPH "$CACHE{HAVE_ISGRAPH}")
  bool_to_int(HAVE_ISLOWER "$CACHE{HAVE_ISLOWER}")
  bool_to_int(HAVE_ISPRINT "$CACHE{HAVE_ISPRINT}")
  bool_to_int(HAVE_ISPUNCT "$CACHE{HAVE_ISPUNCT}")
  bool_to_int(HAVE_ISSPACE "$CACHE{HAVE_ISSPACE}")
  bool_to_int(HAVE_ISUPPER "$CACHE{HAVE_ISUPPER}")
  bool_to_int(HAVE_ISXDIGIT "$CACHE{HAVE_ISXDIGIT}")
  bool_to_int(HAVE_TOASCII "$CACHE{HAVE_TOASCII}")
  bool_to_int(HAVE_TOLOWER "$CACHE{HAVE_TOLOWER}")
  bool_to_int(HAVE_TOUPPER "$CACHE{HAVE_TOUPPER}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/ctype.h.in
    ${LIBCFUNK_BUILD_DIR}/ctype.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERR_H})
  bool_to_int(HAVE_ERR_H "$CACHE{HAVE_ERR_H}")
  bool_to_int(HAVE_ERR_H "$CACHE{HAVE_ERR_H}")
  bool_to_int(HAVE_ERR "$CACHE{HAVE_ERR}")
  bool_to_int(HAVE_VERR "$CACHE{HAVE_VERR}")
  bool_to_int(HAVE_ERRC "$CACHE{HAVE_ERRC}")
  bool_to_int(HAVE_VERRC "$CACHE{HAVE_VERRC}")
  bool_to_int(HAVE_ERRX "$CACHE{HAVE_ERRX}")
  bool_to_int(HAVE_VERRX "$CACHE{HAVE_VERRX}")
  bool_to_int(HAVE_WARN "$CACHE{HAVE_WARN}")
  bool_to_int(HAVE_VWARN "$CACHE{HAVE_VWARN}")
  bool_to_int(HAVE_WARNC "$CACHE{HAVE_WARNC}")
  bool_to_int(HAVE_VWARNC "$CACHE{HAVE_VWARNC}")
  bool_to_int(HAVE_WARNX "$CACHE{HAVE_WARNX}")
  bool_to_int(HAVE_VWARNX "$CACHE{HAVE_VWARNX}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/err.h.in
    ${LIBCFUNK_BUILD_DIR}/err.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERROR_H})
  bool_to_int(HAVE_ERROR_H "$CACHE{HAVE_ERROR_H}")
  bool_to_int(HAVE_ERROR_MESSAGE_COUNT "$CACHE{HAVE_ERROR_MESSAGE_COUNT}")
  bool_to_int(HAVE_ERROR_ONE_PER_LINE "$CACHE{HAVE_ERROR_ONE_PER_LINE}")
  bool_to_int(HAVE_ERROR_PRINT_PROGNAME "$CACHE{HAVE_ERROR_PRINT_PROGNAME}")
  bool_to_int(HAVE_ERROR "$CACHE{HAVE_ERROR}")
  bool_to_int(HAVE_ERROR_AT_LINE "$CACHE{HAVE_ERROR_AT_LINE}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/error.h.in
    ${LIBCFUNK_BUILD_DIR}/error.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_INTTYPES_H})
  bool_to_int(HAVE_INTTYPES_H "$CACHE{HAVE_INTTYPES_H}")
  bool_to_int(HAVE_STRTOIMAX "$CACHE{HAVE_STRTOIMAX_H}")
  bool_to_int(HAVE_STRTOUMAX "$CACHE{HAVE_STRTOUMAX_H}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/inttypes.h.in
    ${LIBCFUNK_BUILD_DIR}/inttypes.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDINT_H})
  bool_to_int(HAVE_STDINT_H "$CACHE{HAVE_STDINT_H}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdint.h.in
    ${LIBCFUNK_BUILD_DIR}/stdint.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDIO_H})
  bool_to_int(HAVE_STDIO_H "$CACHE{HAVE_STDIO_H}")
  bool_to_int(HAVE_FLOCKFILE "$CACHE{HAVE_FLOCKFILE}")
  bool_to_int(HAVE_FUNLOCKFILE "$CACHE{HAVE_FUNLOCKFILE}")
  bool_to_int(HAVE__GETCHAR_NOLOCK "$CACHE{HAVE__GETCHAR_NOLOCK}")
  bool_to_int(HAVE_GETCHAR_UNLOCKED "$CACHE{HAVE_GETCHAR_UNLOCKED}")
  bool_to_int(HAVE__GETC_NOLOCK "$CACHE{HAVE__GETC_NOLOCK}")
  bool_to_int(HAVE_GETC_UNLOCKED "$CACHE{HAVE_GETC_UNLOCKED}")
  bool_to_int(HAVE_GETDELIM "$CACHE{HAVE_GETDELIM}")
  bool_to_int(HAVE_GETLINE "$CACHE{HAVE_GETLINE}")
  bool_to_int(HAVE__LOCK_FILE "$CACHE{HAVE__LOCK_FILE}")
  bool_to_int(HAVE__PUTCHAR_NOLOCK "$CACHE{HAVE__PUTCHAR_NOLOCK}")
  bool_to_int(HAVE_PUTCHAR_UNLOCKED "$CACHE{HAVE_PUTCHAR_UNLOCKED}")
  bool_to_int(HAVE__PUTC_NOLOCK "$CACHE{HAVE__PUTC_NOLOCK}")
  bool_to_int(HAVE_PUTC_UNLOCKED "$CACHE{HAVE_PUTC_UNLOCKED}")
  bool_to_int(HAVE__UNLOCK_FILE "$CACHE{HAVE__UNLOCK_FILE}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdio.h.in
    ${LIBCFUNK_BUILD_DIR}/stdio.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDLIB_H})
  bool_to_int(HAVE_STDLIB_H "$CACHE{HAVE_STDLIB_H}")
  bool_to_int(HAVE_BSEARCH "$CACHE{HAVE_BSEARCH}")
  bool_to_int(HAVE_MKDTEMP "$CACHE{HAVE_MKDTEMP}")
  bool_to_int(HAVE_MKSTEMP "$CACHE{HAVE_MKSTEMP}")
  bool_to_int(HAVE_REALLOCARRAY "$CACHE{HAVE_REALLOCARRAY}")
  bool_to_int(HAVE_SECURE_GETENV "$CACHE{HAVE_SECURE_GETENV}")
  bool_to_int(HAVE_STRTOL "$CACHE{HAVE_STRTOL}")
  bool_to_int(HAVE_STRTOLL "$CACHE{HAVE_STRTOLL}")
  bool_to_int(HAVE_STRTOUL "$CACHE{HAVE_STRTOUL}")
  bool_to_int(HAVE_STRTOULL "$CACHE{HAVE_STRTOULL}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdlib.h.in
    ${LIBCFUNK_BUILD_DIR}/stdlib.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRING_H})
  bool_to_int(HAVE_STRING_H "$CACHE{HAVE_STRING_H}")
  bool_to_int(HAVE_EXPLICIT_BZERO "$CACHE{HAVE_EXPLICIT_BZERO}")
  bool_to_int(HAVE_MEMCHR "$CACHE{HAVE_MEMCHR}")
  bool_to_int(HAVE_MEMCMP "$CACHE{HAVE_MEMCMP}")
  bool_to_int(HAVE_MEMCPY "$CACHE{HAVE_MEMCPY}")
  bool_to_int(HAVE_MEMMOVE "$CACHE{HAVE_MEMMOVE}")
  bool_to_int(HAVE_MEMRCHR "$CACHE{HAVE_MEMRCHR}")
  bool_to_int(HAVE_MEMSET "$CACHE{HAVE_MEMSET}")
  bool_to_int(HAVE_RAWMEMCHR "$CACHE{HAVE_RAWMEMCHR}")
  bool_to_int(HAVE_STPCPY "$CACHE{HAVE_STPCPY}")
  bool_to_int(HAVE_STRCAT "$CACHE{HAVE_STRCAT}")
  bool_to_int(HAVE_STRCHR "$CACHE{HAVE_STRCHR}")
  bool_to_int(HAVE_STRCHRNUL "$CACHE{HAVE_STRCHRNUL}")
  bool_to_int(HAVE_STRCMP "$CACHE{HAVE_STRCMP}")
  bool_to_int(HAVE_STRCSPN "$CACHE{HAVE_STRCSPN}")
  bool_to_int(HAVE_STRDUP "$CACHE{HAVE_STRDUP}")
  bool_to_int(HAVE_STRLEN "$CACHE{HAVE_STRLEN}")
  bool_to_int(HAVE_STRMODE "$CACHE{HAVE_STRMODE}")
  bool_to_int(HAVE_STRNCAT "$CACHE{HAVE_STRNCAT}")
  bool_to_int(HAVE_STRNCMP "$CACHE{HAVE_STRNCMP}")
  bool_to_int(HAVE_STRNCPY "$CACHE{HAVE_STRNCPY}")
  bool_to_int(HAVE_STRNDUP "$CACHE{HAVE_STRNDUP}")
  bool_to_int(HAVE_STRNLEN "$CACHE{HAVE_STRNLEN}")
  bool_to_int(HAVE_STRPBRK "$CACHE{HAVE_STRPBRK}")
  bool_to_int(HAVE_STRRCHR "$CACHE{HAVE_STRRCHR}")
  bool_to_int(HAVE_STRSEP "$CACHE{HAVE_STRSEP}")
  bool_to_int(HAVE_STRSPN "$CACHE{HAVE_STRSPN}")
  bool_to_int(HAVE_TIMINGSAFE_BCMP "$CACHE{HAVE_TIMINGSAFE_BCMP}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/string.h.in
    ${LIBCFUNK_BUILD_DIR}/string.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRINGS_H})
  bool_to_int(HAVE_STRINGS_H "$CACHE{HAVE_STRINGS_H}")
  bool_to_int(HAVE_BCMP "$CACHE{HAVE_BCMP}")
  bool_to_int(HAVE_BCOPY "$CACHE{HAVE_BCOPY}")
  bool_to_int(HAVE_BZERO "$CACHE{HAVE_BZERO}")
  bool_to_int(HAVE_FFS "$CACHE{HAVE_FFS}")
  bool_to_int(HAVE_FFSL "$CACHE{HAVE_FFSL}")
  bool_to_int(HAVE_FFSLL "$CACHE{HAVE_FFSLL}")
  bool_to_int(HAVE_FLS "$CACHE{HAVE_FLS}")
  bool_to_int(HAVE_FLSL "$CACHE{HAVE_FLSL}")
  bool_to_int(HAVE_FLSLL "$CACHE{HAVE_FLSLL}")
  bool_to_int(HAVE_INDEX "$CACHE{HAVE_INDEX}")
  bool_to_int(HAVE_POPCOUNT "$CACHE{HAVE_POPCOUNT}")
  bool_to_int(HAVE_POPCOUNTL "$CACHE{HAVE_POPCOUNTL}")
  bool_to_int(HAVE_POPCOUNTLL "$CACHE{HAVE_POPCOUNTLL}")
  bool_to_int(HAVE_RINDEX "$CACHE{HAVE_RINDEX}")
  bool_to_int(HAVE_STRCASECMP "$CACHE{HAVE_STRCASECMP}")
  bool_to_int(HAVE_STRNCASECMP "$CACHE{HAVE_STRNCASECMP}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/strings.h.in
    ${LIBCFUNK_BUILD_DIR}/strings.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_RANDOM_H})
  bool_to_int(HAVE_SYS_RANDOM_H "$CACHE{HAVE_SYS_RANDOM_H}")
  bool_to_int(HAVE_GETENTROPY "$CACHE{HAVE_GETENTROPY}")
  bool_to_int(HAVE_GETRANDOM "$CACHE{HAVE_GETRANDOM}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/random.h.in
    ${LIBCFUNK_BUILD_DIR}/sys/random.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TIME_H})
  bool_to_int(HAVE_SYS_TIME_H "$CACHE{HAVE_SYS_TIME_H}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/time.h.in
    ${LIBCFUNK_BUILD_DIR}/sys/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TIME_H})
  bool_to_int(HAVE_TIME_H "$CACHE{HAVE_TIME_H}")
  bool_to_int(HAVE_DYSIZE "$CACHE{HAVE_DYSIZE}")
  bool_to_int(HAVE_TIMESPEC_GET "$CACHE{HAVE_TIMESPEC_GET}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/time.h.in
    ${LIBCFUNK_BUILD_DIR}/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UNISTD_H})
  bool_to_int(HAVE_UNISTD_H "$CACHE{HAVE_UNISTD_H}")
  bool_to_int(HAVE_ENDUSERSHELL "$CACHE{HAVE_ENDUSERSHELL}")
  bool_to_int(HAVE_GETCWD "$CACHE{HAVE_GETCWD}")
  bool_to_int(HAVE_GETPAGESIZE "$CACHE{HAVE_GETPAGESIZE}")
  bool_to_int(HAVE_GETUSERSHELL "$CACHE{HAVE_GETUSERSHELL}")
  bool_to_int(HAVE_SETUSERSHELL "$CACHE{HAVE_SETUSERSHELL}")
  bool_to_int(HAVE_SWAB "$CACHE{HAVE_SWAB}")
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/unistd.h.in
    ${LIBCFUNK_BUILD_DIR}/unistd.h
  )
endif ()
