/* -*- mode: c; -*- */

#ifndef CONFIG_H
#define CONFIG_H

/* Size of signed integer types. */
@SIZEOF_SHORT_CODE@
@SIZEOF_INT_CODE@
@SIZEOF_LONG_CODE@
@SIZEOF_LONG_LONG_CODE@

/* Size of unsigned integer types. */
@SIZEOF_UNSIGNED_SHORT_CODE@
@SIZEOF_UNSIGNED_INT_CODE@
@SIZEOF_UNSIGNED_LONG_CODE@
@SIZEOF_UNSIGNED_LONG_LONG_CODE@

/* Fixed width signed integer types. */
#cmakedefine01 HAVE_INT8_T
#cmakedefine01 HAVE_INT16_T
#cmakedefine01 HAVE_INT32_T
#cmakedefine01 HAVE_INT64_T

/* Fixed width unsigned integer types. */
#cmakedefine01 HAVE_UINT8_T
#cmakedefine01 HAVE_UINT16_T
#cmakedefine01 HAVE_UINT32_T
#cmakedefine01 HAVE_UINT64_T

/* Maximum width integer types. */
#cmakedefine01 HAVE_INTMAX_T
#cmakedefine01 HAVE_UINTMAX_T

/* Integer types capable containing pointers. */
#cmakedefine01 HAVE_INTPTR_T
#cmakedefine01 HAVE_UINTPTR_T

/* Integer type used for pointer arithmetic. */
#cmakedefine01 HAVE_PTRDIFF_T

/* Checked first for types */
#cmakedefine01 HAVE_SYS_TYPES_H
#cmakedefine01 HAVE_STDDEF_H
#cmakedefine01 HAVE_STDINT_H
#cmakedefine01 HAVE_INTTYPES_H

/* Headers */
#cmakedefine01 HAVE_AIO_H
#cmakedefine01 HAVE_ARPA_INET_H
#cmakedefine01 HAVE_ASSERT_H
#cmakedefine01 HAVE_COMPLEX_H
#cmakedefine01 HAVE_CPIO_H
#cmakedefine01 HAVE_CTYPE_H
#cmakedefine01 HAVE_DIRENT_H
#cmakedefine01 HAVE_DLFCN_H
#cmakedefine01 HAVE_ERR_H
#cmakedefine01 HAVE_ERRNO_H
#cmakedefine01 HAVE_ERROR_H
#cmakedefine01 HAVE_FCNTL_H
#cmakedefine01 HAVE_FENV_H
#cmakedefine01 HAVE_FLOAT_H
#cmakedefine01 HAVE_FMTMSG_H
#cmakedefine01 HAVE_FNMATCH_H
#cmakedefine01 HAVE_FTW_H
#cmakedefine01 HAVE_GLOB_H
#cmakedefine01 HAVE_GRP_H
#cmakedefine01 HAVE_ICONV_H
#cmakedefine01 HAVE_ISO646_H
#cmakedefine01 HAVE_LANGINFO_H
#cmakedefine01 HAVE_LIBGEN_H
#cmakedefine01 HAVE_LIMITS_H
#cmakedefine01 HAVE_LOCALE_H
#cmakedefine01 HAVE_MATH_H
#cmakedefine01 HAVE_MONETARY_H
#cmakedefine01 HAVE_MQUEUE_H
#cmakedefine01 HAVE_NDBM_H
#cmakedefine01 HAVE_NETDB_H
#cmakedefine01 HAVE_NET_IF_H
#cmakedefine01 HAVE_NETINET_IN_H
#cmakedefine01 HAVE_NETINET_TCP_H
#cmakedefine01 HAVE_NL_TYPES_H
#cmakedefine01 HAVE_POLL_H
#cmakedefine01 HAVE_PTHREAD_H
#cmakedefine01 HAVE_PWD_H
#cmakedefine01 HAVE_REGEX_H
#cmakedefine01 HAVE_SCHED_H
#cmakedefine01 HAVE_SEARCH_H
#cmakedefine01 HAVE_SEMAPHORE_H
#cmakedefine01 HAVE_SETJMP_H
#cmakedefine01 HAVE_SIGNAL_H
#cmakedefine01 HAVE_SPAWN_H
#cmakedefine01 HAVE_STDARG_H
#cmakedefine01 HAVE_STDBOOL_H
#cmakedefine01 HAVE_STDIO_H
#cmakedefine01 HAVE_STDLIB_H
#cmakedefine01 HAVE_STRING_H
#cmakedefine01 HAVE_STRINGS_H
#cmakedefine01 HAVE_STROPTS_H
#cmakedefine01 HAVE_SYS_CDEFS_H
#cmakedefine01 HAVE_SYS_IOCTL_H
#cmakedefine01 HAVE_SYS_SYSCTL_H
#cmakedefine01 HAVE_SYS_IPC_H
#cmakedefine01 HAVE_SYSLOG_H
#cmakedefine01 HAVE_SYS_MMAN_H
#cmakedefine01 HAVE_SYS_MSG_H
#cmakedefine01 HAVE_SYS_PARAM_H
#cmakedefine01 HAVE_SYS_RESOURCE_H
#cmakedefine01 HAVE_SYS_SELECT_H
#cmakedefine01 HAVE_SYS_SEM_H
#cmakedefine01 HAVE_SYS_SHM_H
#cmakedefine01 HAVE_SYS_SOCKET_H
#cmakedefine01 HAVE_SYS_STAT_H
#cmakedefine01 HAVE_SYS_STATVFS_H
#cmakedefine01 HAVE_SYS_TIME_H
#cmakedefine01 HAVE_SYS_TIMES_H
#cmakedefine01 HAVE_SYS_UIO_H
#cmakedefine01 HAVE_SYS_UN_H
#cmakedefine01 HAVE_SYS_UTSNAME_H
#cmakedefine01 HAVE_SYS_WAIT_H
#cmakedefine01 HAVE_TAR_H
#cmakedefine01 HAVE_TERMIOS_H
#cmakedefine01 HAVE_TGMATH_H
#cmakedefine01 HAVE_TIME_H
#cmakedefine01 HAVE_TRACE_H
#cmakedefine01 HAVE_ULIMIT_H
#cmakedefine01 HAVE_UNISTD_H
#cmakedefine01 HAVE_UTIME_H
#cmakedefine01 HAVE_UTMPX_H
#cmakedefine01 HAVE_WCHAR_H
#cmakedefine01 HAVE_WCTYPE_H
#cmakedefine01 HAVE_WORDEXP_H

/* Headers the depend on windows.h */
#cmakedefine01 HAVE_WINDOWS_H
#cmakedefine01 HAVE_BCRYPT_H
#cmakedefine01 HAVE_SYSINFOAPI_H

/* Functions */
#cmakedefine01 HAVE_CLOCK_GETTIME
#cmakedefine01 HAVE_CLOCK_SETTIME
#cmakedefine01 HAVE_ERRC
#cmakedefine01 HAVE_ERR
#cmakedefine01 HAVE_ERROR_AT_LINE
#cmakedefine01 HAVE_ERROR
#cmakedefine01 HAVE_ERRX
#cmakedefine01 HAVE_EXPLICIT_BZERO
#cmakedefine01 HAVE_GETEGID
#cmakedefine01 HAVE_GETENV
#cmakedefine01 HAVE_GETEUID
#cmakedefine01 HAVE_GETEXECNAME
#cmakedefine01 HAVE_GETGID
#cmakedefine01 HAVE_GETPROGNAME
#cmakedefine01 HAVE_GETTIMEOFDAY
#cmakedefine01 HAVE_GETUID
#cmakedefine01 HAVE_ISSETUGID
#cmakedefine01 HAVE_REALLOCARRAY
#cmakedefine01 HAVE_SECURE_GETENV
#cmakedefine01 HAVE_SETPROGNAME
#cmakedefine01 HAVE_SETTIMEOFDAY
#cmakedefine01 HAVE_VERRC
#cmakedefine01 HAVE_VERR
#cmakedefine01 HAVE_VERRX
#cmakedefine01 HAVE_VWARNC
#cmakedefine01 HAVE_VWANR
#cmakedefine01 HAVE_VWARNX
#cmakedefine01 HAVE_WARNC
#cmakedefine01 HAVE_WARN
#cmakedefine01 HAVE_WARNX

/* Variables */
#cmakedefine01 HAVE___ARGC
#cmakedefine01 HAVE___ARGV
#cmakedefine01 HAVE_ERROR_MESSAGE_COUNT
#cmakedefine01 HAVE_ERROR_ONE_PER_LINE
#cmakedefine01 HAVE_ERROR_PRINT_PROGNAME
#cmakedefine01 HAVE___PROGNAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_NAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_SHORT_NAME

/* Check for the time members in struct stat. */
#cmakedefine01 HAVE_STRUCT_STAT_ST_ATIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_CTIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_MTIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC

#endif /* CONFIG_H */
