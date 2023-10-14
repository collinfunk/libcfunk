/* -*- mode: c; -*- */

#ifndef CONFIG_H
#define CONFIG_H

/* TODO: Move these. */
#ifndef _ALL_SOURCE
#  define _ALL_SOURCE 1
#endif

#ifndef _DARWIN_C_SOURCE
#  define _DARWIN_C_SOURCE 1
#endif

#ifndef _GNU_SOURCE
#  define _GNU_SOURCE 1
#endif

#ifndef _NETBSD_SOURCE
#  define _NETBSD_SOURCE 1
#endif

#ifndef __STDC_WANT_LIB_EXT2__
#  define __STDC_WANT_LIB_EXT2__ 1
#endif

#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
#  define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif

#cmakedefine01 HAVE_ABS
#cmakedefine01 HAVE_ALLOCA_H
#cmakedefine01 HAVE_ALPHASORT
#cmakedefine01 HAVE___ARGC
#cmakedefine01 HAVE___ARGV
#cmakedefine01 HAVE_ARPA_INET_H
#cmakedefine01 HAVE_ASSERT_H
#cmakedefine01 HAVE_ATEXIT
#cmakedefine01 HAVE_ATOI
#cmakedefine01 HAVE_ATOL
#cmakedefine01 HAVE_ATOLL
#cmakedefine01 HAVE_BCMP
#cmakedefine01 HAVE_BCOPY
#cmakedefine01 HAVE_BCRYPT_H
#cmakedefine01 HAVE_BSEARCH
#cmakedefine01 HAVE_BZERO
#cmakedefine01 HAVE_C11__ALIGNAS
#cmakedefine01 HAVE_C11__ALIGNOF
#cmakedefine01 HAVE_C11__NORETURN
#cmakedefine01 HAVE_C11_STATIC_ASSERT
#cmakedefine01 HAVE_C23_ALIGNAS
#cmakedefine01 HAVE_C23_ALIGNOF
#cmakedefine01 HAVE_C23_BOOL
#cmakedefine01 HAVE_C23_NULLPTR
#cmakedefine01 HAVE_C23_STATIC_ASSERT
#cmakedefine01 HAVE_C99_BOOL
#cmakedefine01 HAVE_C99__EXIT
#cmakedefine01 HAVE_CALLOC
#cmakedefine01 HAVE_CHMOD
#cmakedefine01 HAVE_CHOWN
#cmakedefine01 HAVE_CLOCK_GETRES
#cmakedefine01 HAVE_CLOCKGETRES
#cmakedefine01 HAVE_CLOCK_GETTIME
#cmakedefine01 HAVE_COPY_FILE_RANGE
#cmakedefine01 HAVE_CREAT
#cmakedefine01 HAVE_CRTDBG_H
#cmakedefine01 HAVE_CRT_EXTERNS_H
#cmakedefine01 HAVE__CRTSETREPORTMODE
#cmakedefine01 HAVE_CTYPE_H
#cmakedefine01 HAVE_DAEMON
#cmakedefine01 HAVE_DEV_PTC
#cmakedefine01 HAVE_DEV_PTM
#cmakedefine01 HAVE_DEV_PTMX
#cmakedefine01 HAVE_DEV_T
#cmakedefine01 HAVE_DIRECT_H
#cmakedefine01 HAVE_DIRENT_H
#cmakedefine01 HAVE_DUP2
#cmakedefine01 HAVE_DYSIZE
#cmakedefine01 HAVE_EACCESS
#cmakedefine01 HAVE_ENDIAN_H
#cmakedefine01 HAVE_ENDUSERSHELL
#cmakedefine01 HAVE_ENVIRON
#cmakedefine01 HAVE_ERR
#cmakedefine01 HAVE_ERRC
#cmakedefine01 HAVE_ERR_H
#cmakedefine01 HAVE_ERROR
#cmakedefine01 HAVE_ERROR_AT_LINE
#cmakedefine01 HAVE_ERROR_H
#cmakedefine01 HAVE_ERROR_MESSAGE_COUNT
#cmakedefine01 HAVE_ERROR_ONE_PER_LINE
#cmakedefine01 HAVE_ERROR_PRINT_PROGNAME
#cmakedefine01 HAVE_ERRX
#cmakedefine01 HAVE_EUIDACCESS
#cmakedefine01 HAVE_EXECL
#cmakedefine01 HAVE_EXECLE
#cmakedefine01 HAVE_EXECLP
#cmakedefine01 HAVE_EXECV
#cmakedefine01 HAVE_EXECVE
#cmakedefine01 HAVE_EXECVP
#cmakedefine01 HAVE_EXECVPE
#cmakedefine01 HAVE__EXIT
#cmakedefine01 HAVE_EXPLICIT_BZERO
#cmakedefine01 HAVE_FACCESSAT
#cmakedefine01 HAVE___FBUFSIZE
#cmakedefine01 HAVE_FCNTL_H
#cmakedefine01 HAVE_FDATASYNC
#cmakedefine01 HAVE_FFS
#cmakedefine01 HAVE_FFSL
#cmakedefine01 HAVE_FFSLL
#cmakedefine01 HAVE_FILE__BASE
#cmakedefine01 HAVE_FILE__BF
#cmakedefine01 HAVE_FILE__BF__BASE
#cmakedefine01 HAVE_FILE__BF__SIZE
#cmakedefine01 HAVE_FILE__BUFSIZ
#cmakedefine01 HAVE_FILE__CNT
#cmakedefine01 HAVE_FILE__FLAG
#cmakedefine01 HAVE_FILE__FLAGS
#cmakedefine01 HAVE_FILE__IO_BUF_BASE
#cmakedefine01 HAVE_FILE__IO_BUF_END
#cmakedefine01 HAVE_FILE__IO_WRITE_BASE
#cmakedefine01 HAVE_FILE__IO_WRITE_PTR
#cmakedefine01 HAVE__FILENO
#cmakedefine01 HAVE_FILENO
#cmakedefine01 HAVE_FILE__P
#cmakedefine01 HAVE_FILE__PTR
#cmakedefine01 HAVE___FLBF
#cmakedefine01 HAVE_FLOCK
#cmakedefine01 HAVE_FLOCKFILE
#cmakedefine01 HAVE_FLS
#cmakedefine01 HAVE_FLSL
#cmakedefine01 HAVE_FLSLL
#cmakedefine01 HAVE_FORK
#cmakedefine01 HAVE___FPENDING
#cmakedefine01 HAVE___FPURGE
#cmakedefine01 HAVE___FREADABLE
#cmakedefine01 HAVE___FREADING
#cmakedefine01 HAVE_FREE
#cmakedefine01 HAVE_FSEEK
#cmakedefine01 HAVE__FSEEKI64
#cmakedefine01 HAVE_FSEEKO
#cmakedefine01 HAVE___FSETERR
#cmakedefine01 HAVE_FSYNC
#cmakedefine01 HAVE_FTELL
#cmakedefine01 HAVE__FTELLI64
#cmakedefine01 HAVE_FTELLO
#cmakedefine01 HAVE_FUNLOCKFILE
#cmakedefine01 HAVE___FWRITABLE
#cmakedefine01 HAVE___FWRITING
#cmakedefine01 HAVE_GAI_STRERROR
#cmakedefine01 HAVE_GAI_STRERRORA
#cmakedefine01 HAVE__GETCHAR_NOLOCK
#cmakedefine01 HAVE_GETCHAR_UNLOCKED
#cmakedefine01 HAVE__GETC_NOLOCK
#cmakedefine01 HAVE_GETC_UNLOCKED
#cmakedefine01 HAVE__GETCWD
#cmakedefine01 HAVE_GETCWD
#cmakedefine01 HAVE_GETDELIM
#cmakedefine01 HAVE_GETDTABLESIZE
#cmakedefine01 HAVE_GETEGID
#cmakedefine01 HAVE_GETENTROPY
#cmakedefine01 HAVE_GETEUID
#cmakedefine01 HAVE_GETEXECNAME
#cmakedefine01 HAVE_GETGID
#cmakedefine01 HAVE_GETGROUPS
#cmakedefine01 HAVE_GETHOSTNAME
#cmakedefine01 HAVE_GETLINE
#cmakedefine01 HAVE_GETLOADAVG
#cmakedefine01 HAVE_GETLOGIN
#cmakedefine01 HAVE_GETLOGIN_R
#cmakedefine01 HAVE__GETMAXSTDIO
#cmakedefine01 HAVE_GETPAGESIZE
#cmakedefine01 HAVE_GETPROGNAME
#cmakedefine01 HAVE_GETRANDOM
#cmakedefine01 HAVE_GETRLIMIT
#cmakedefine01 HAVE_GETTIMEOFDAY
#cmakedefine01 HAVE_GETUID
#cmakedefine01 HAVE_GETUSERHSELL
#cmakedefine01 HAVE_GETUSERSHELL
#cmakedefine01 HAVE_GID_T
#cmakedefine01 HAVE_GMTIME_R
#cmakedefine01 HAVE_GROUP_MEMBER
#cmakedefine01 HAVE_IMAXABS
#cmakedefine01 HAVE_INCLUDE_NEXT
#cmakedefine01 HAVE_INDEX
#cmakedefine01 HAVE_INT16_T
#cmakedefine01 HAVE_INT32_T
#cmakedefine01 HAVE___INT64_T
#cmakedefine01 HAVE_INT64_T
#cmakedefine01 HAVE_INT8_T
#cmakedefine01 HAVE_INT_FAST16_T
#cmakedefine01 HAVE_INT_FAST32_T
#cmakedefine01 HAVE_INT_FAST64_T
#cmakedefine01 HAVE_INT_FAST8_T
#cmakedefine01 HAVE_INT_LEAST16_T
#cmakedefine01 HAVE_INT_LEAST32_T
#cmakedefine01 HAVE_INT_LEAST64_T
#cmakedefine01 HAVE_INT_LEAST8_T
#cmakedefine01 HAVE_INTMAX_T
#cmakedefine01 HAVE_INTPTR_T
#cmakedefine01 HAVE_INTTYPES_H
#cmakedefine01 HAVE_IOCTL
#cmakedefine01 HAVE_IO_H
#cmakedefine01 HAVE_ISALNUM
#cmakedefine01 HAVE_ISALPHA
#cmakedefine01 HAVE_ISAPIPE
#cmakedefine01 HAVE_ISASCII
#cmakedefine01 HAVE__ISATTY
#cmakedefine01 HAVE_ISATTY
#cmakedefine01 HAVE_ISBLANK
#cmakedefine01 HAVE_ISCNTRL
#cmakedefine01 HAVE_ISDIGIT
#cmakedefine01 HAVE_ISGRAPH
#cmakedefine01 HAVE_ISLOWER
#cmakedefine01 HAVE_ISPRINT
#cmakedefine01 HAVE_ISPUNCT
#cmakedefine01 HAVE_ISSETUGID
#cmakedefine01 HAVE_ISSPACE
#cmakedefine01 HAVE_ISUPPER
#cmakedefine01 HAVE_ISXDIGIT
#cmakedefine01 HAVE_LABS
#cmakedefine01 HAVE_LIMITS_H
#cmakedefine01 HAVE_LLABS
#cmakedefine01 HAVE_LOCALE_H
#cmakedefine01 HAVE_LOCALTIME_R
#cmakedefine01 HAVE__LOCK_FILE
#cmakedefine01 HAVE_MALLOC
#cmakedefine01 HAVE_MALLOC_H
#cmakedefine01 HAVE_MEMCHR
#cmakedefine01 HAVE_MEMCMP
#cmakedefine01 HAVE_MEMCPY
#cmakedefine01 HAVE_MEMMOVE
#cmakedefine01 HAVE_MEMRCHR
#cmakedefine01 HAVE_MEMSET
#cmakedefine01 HAVE_MEMSET_EXPLICIT
#cmakedefine01 HAVE_MEMSET_S
#cmakedefine01 HAVE__MKDIR
#cmakedefine01 HAVE_MKDIR
#cmakedefine01 HAVE_MKDTEMP
#cmakedefine01 HAVE_MKFIFO
#cmakedefine01 HAVE_MKNOD
#cmakedefine01 HAVE_MKSTEMP
#cmakedefine01 HAVE_NANOSLEEP
#cmakedefine01 HAVE_NETDB_H
#cmakedefine01 HAVE_NETINET_IN_H
#cmakedefine01 HAVE__NSGETENVIRON
#cmakedefine01 HAVE_OFF_T
#cmakedefine01 HAVE_ON_EXIT
#cmakedefine01 HAVE__PIPE
#cmakedefine01 HAVE_PIPE
#cmakedefine01 HAVE_POPCOUNT
#cmakedefine01 HAVE_POPCOUNTL
#cmakedefine01 HAVE_POPCOUNTLL
#cmakedefine01 HAVE_POSIX_OPENPT
#cmakedefine01 HAVE___PROGNAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_NAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_SHORT_NAME
#cmakedefine01 HAVE_PTHREAD_ATTR_T
#cmakedefine01 HAVE_PTHREAD_BARRIERATTR_T
#cmakedefine01 HAVE_PTHREAD_BARRIER_T
#cmakedefine01 HAVE_PTHREAD_CONDATTR_T
#cmakedefine01 HAVE_PTHREAD_COND_T
#cmakedefine01 HAVE_PTHREAD_H
#cmakedefine01 HAVE_PTHREAD_KEY_T
#cmakedefine01 HAVE_PTHREAD_MUTEXATTR_T
#cmakedefine01 HAVE_PTHREAD_MUTEX_T
#cmakedefine01 HAVE_PTHREAD_ONCE_T
#cmakedefine01 HAVE_PTHREAD_RWLOCKATTR_T
#cmakedefine01 HAVE_PTHREAD_RWLOCK_T
#cmakedefine01 HAVE_PTHREAD_SPINLOCK_T
#cmakedefine01 HAVE_PTHREAD_T
#cmakedefine01 HAVE_PTSNAME
#cmakedefine01 HAVE_PTY_H
#cmakedefine01 HAVE__PUTCHAR_NOLOCK
#cmakedefine01 HAVE_PUTCHAR_UNLOCKED
#cmakedefine01 HAVE__PUTC_NOLOCK
#cmakedefine01 HAVE_PUTC_UNLOCKED
#cmakedefine01 HAVE_RAWMEMCHR
#cmakedefine01 HAVE_REALLOC
#cmakedefine01 HAVE_REALLOCARRAY
#cmakedefine01 HAVE_REALLOCF
#cmakedefine01 HAVE_REVOKE
#cmakedefine01 HAVE_RINDEX
#cmakedefine01 HAVE_SCHED_GETAFFINITY
#cmakedefine01 HAVE_SCHED_H
#cmakedefine01 HAVE_SCHED_YIELD
#cmakedefine01 HAVE_SECURE_GETENV
#cmakedefine01 HAVE_SECUREZEROMEMORY
#cmakedefine01 HAVE_SETHOSTNAME
#cmakedefine01 HAVE__SET_INVALID_PARAMETER_HANDLER
#cmakedefine01 HAVE__SETMODE
#cmakedefine01 HAVE_SETMODE
#cmakedefine01 HAVE_SETPROGNAME
#cmakedefine01 HAVE_SETSID
#cmakedefine01 HAVE_SETUSERSHELL
#cmakedefine01 HAVE_SIG2STR
#cmakedefine01 HAVE_SIGABBREV_NP
#cmakedefine01 HAVE_SIG_ATOMIC_T
#cmakedefine01 HAVE_SIGDESCR_NP
#cmakedefine01 HAVE_SIGINFO_T
#cmakedefine01 HAVE_SIGNAL_H
#cmakedefine01 HAVE_SIGSET_T
#cmakedefine01 HAVE_SLEEP
#cmakedefine01 HAVE_STACK_T
#cmakedefine01 HAVE_STDBOOL_H
#cmakedefine01 HAVE_STDCKDINT_H
#cmakedefine01 HAVE_STDDEF_H
#cmakedefine01 HAVE_STDINT_H
#cmakedefine01 HAVE_STDIO_EXT_H
#cmakedefine01 HAVE_STDIO_H
#cmakedefine01 HAVE_STDLIB_H
#cmakedefine01 HAVE_STPCPY
#cmakedefine01 HAVE_STR2SIG
#cmakedefine01 HAVE_STRCASECMP
#cmakedefine01 HAVE_STRCAT
#cmakedefine01 HAVE_STRCHR
#cmakedefine01 HAVE_STRCHRNUL
#cmakedefine01 HAVE_STRCMP
#cmakedefine01 HAVE_STRCSPN
#cmakedefine01 HAVE_STRDUP
#cmakedefine01 HAVE_STRERRORDESC_NP
#cmakedefine01 HAVE_STRERRORNAME_NP
#cmakedefine01 HAVE_STRERROR_R
#cmakedefine01 HAVE_STRERROR_S
#cmakedefine01 HAVE_STRING_H
#cmakedefine01 HAVE_STRINGS_H
#cmakedefine01 HAVE_STRLEN
#cmakedefine01 HAVE_STRMODE
#cmakedefine01 HAVE_STRNCASECMP
#cmakedefine01 HAVE_STRNCAT
#cmakedefine01 HAVE_STRNCMP
#cmakedefine01 HAVE_STRNCPY
#cmakedefine01 HAVE_STRNDUP
#cmakedefine01 HAVE_STRNLEN
#cmakedefine01 HAVE_STRPBRK
#cmakedefine01 HAVE_STRRCHR
#cmakedefine01 HAVE_STRSEP
#cmakedefine01 HAVE_STRSPN
#cmakedefine01 HAVE_STRSTR
#cmakedefine01 HAVE_STRTOIMAX
#cmakedefine01 HAVE_STRTOL
#cmakedefine01 HAVE_STRTOLL
#cmakedefine01 HAVE_STRTOUL
#cmakedefine01 HAVE_STRTOULL
#cmakedefine01 HAVE_STRTOUMAX
#cmakedefine01 HAVE_STRUCT_FLOCK
#cmakedefine01 HAVE_STRUCT_FLOCK_L_LEN
#cmakedefine01 HAVE_STRUCT_FLOCK_L_PID
#cmakedefine01 HAVE_STRUCT_FLOCK_L_START
#cmakedefine01 HAVE_STRUCT_FLOCK_L_TYPE
#cmakedefine01 HAVE_STRUCT_FLOCK_L_WHENCE
#cmakedefine01 HAVE_STRUCT_ITIMERSPEC
#cmakedefine01 HAVE_STRUCT_LCONV
#cmakedefine01 HAVE_STRUCT_PTMGET
#cmakedefine01 HAVE_STRUCT_SIGACTION
#cmakedefine01 HAVE_STRUCT_SIGEVENT
#cmakedefine01 HAVE_STRUCT_STAT_ST_ATIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_ATIMESPEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_BLKSIZE
#cmakedefine01 HAVE_STRUCT_STAT_ST_BLOCKS
#cmakedefine01 HAVE_STRUCT_STAT_ST_CTIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_CTIMESPEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_MTIM
#cmakedefine01 HAVE_STRUCT_STAT_ST_MTIMESPEC
#cmakedefine01 HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC
#cmakedefine01 HAVE_STRUCT_TERMIOS
#cmakedefine01 HAVE_STRUCT_TIMESPEC
#cmakedefine01 HAVE_STRUCT_TMS
#cmakedefine01 HAVE_STRUCT__UTIMBUF
#cmakedefine01 HAVE_STRUCT_UTIMBUF
#cmakedefine01 HAVE_STRUCT_UTSNAME
#cmakedefine01 HAVE_STRUCT_WINSIZE
#cmakedefine01 HAVE_STRVERSCMP
#cmakedefine01 HAVE_SWAB
#cmakedefine01 HAVE_SYSCONF
#cmakedefine01 HAVE_SYS_ENDIAN_H
#cmakedefine01 HAVE_SYSEXITS_H
#cmakedefine01 HAVE_SYS_FILE_H
#cmakedefine01 HAVE_SYSINFOAPI_H
#cmakedefine01 HAVE_SYS_IOCTL_H
#cmakedefine01 HAVE_SYS_LOADAVG_H
#cmakedefine01 HAVE_SYS_PARAM_H
#cmakedefine01 HAVE_SYS_RANDOM_H
#cmakedefine01 HAVE_SYS_RESOURCE_H
#cmakedefine01 HAVE_SYS_SOCKET_H
#cmakedefine01 HAVE_SYS_STAT_H
#cmakedefine01 HAVE_SYS_SYSCTL_H
#cmakedefine01 HAVE_SYS_TIME_H
#cmakedefine01 HAVE_SYS_TIMES_H
#cmakedefine01 HAVE_SYS_TTY_H
#cmakedefine01 HAVE_SYS_TYPES_H
#cmakedefine01 HAVE_SYS_UTIME_H
#cmakedefine01 HAVE_SYS_UTSNAME_H
#cmakedefine01 HAVE_SYS_WAIT_H
#cmakedefine01 HAVE_TCGETSID
#cmakedefine01 HAVE_TERMIOS_H
#cmakedefine01 HAVE_TIME_H
#cmakedefine01 HAVE_TIMES
#cmakedefine01 HAVE_TIMESPEC_GET
#cmakedefine01 HAVE_TIMESPEC_GETRES
#cmakedefine01 HAVE_TIMINGSAFE_BCMP
#cmakedefine01 HAVE_TOASCII
#cmakedefine01 HAVE_TOLOWER
#cmakedefine01 HAVE_TOUPPER
#cmakedefine01 HAVE_TTYNAME
#cmakedefine01 HAVE_TTYNAME_R
#cmakedefine01 HAVE___TYPEOF__
#cmakedefine01 HAVE_TYPEOF
#cmakedefine01 HAVE_UID_T
#cmakedefine01 HAVE_UINT16_T
#cmakedefine01 HAVE_UINT32_T
#cmakedefine01 HAVE_UINT64_T
#cmakedefine01 HAVE_UINT8_T
#cmakedefine01 HAVE_UINT_FAST16_T
#cmakedefine01 HAVE_UINT_FAST32_T
#cmakedefine01 HAVE_UINT_FAST64_T
#cmakedefine01 HAVE_UINT_FAST8_T
#cmakedefine01 HAVE_UINT_LEAST16_T
#cmakedefine01 HAVE_UINT_LEAST32_T
#cmakedefine01 HAVE_UINT_LEAST64_T
#cmakedefine01 HAVE_UINT_LEAST8_T
#cmakedefine01 HAVE_UINTMAX_T
#cmakedefine01 HAVE_UINTPTR_T
#cmakedefine01 HAVE_UNAME
#cmakedefine01 HAVE_UNION_SIGVAL
#cmakedefine01 HAVE_UNISTD_H
#cmakedefine01 HAVE_UNIXIO_H
#cmakedefine01 HAVE__UNLOCK_FILE
#cmakedefine01 HAVE_UNLOCKPT
#cmakedefine01 HAVE_UTIME_H
#cmakedefine01 HAVE_VERR
#cmakedefine01 HAVE_VERRC
#cmakedefine01 HAVE_VERRX
#cmakedefine01 HAVE_VERSIONSORT
#cmakedefine01 HAVE_VWARN
#cmakedefine01 HAVE_VWARNC
#cmakedefine01 HAVE_VWARNX
#cmakedefine01 HAVE_WAITPID
#cmakedefine01 HAVE_WARN
#cmakedefine01 HAVE_WARNC
#cmakedefine01 HAVE_WARNX
#cmakedefine01 HAVE_WCHAR_H
#cmakedefine01 HAVE_WCPCPY
#cmakedefine01 HAVE_WCSCAT
#cmakedefine01 HAVE_WCSCHR
#cmakedefine01 HAVE_WCSCMP
#cmakedefine01 HAVE_WCSCPY
#cmakedefine01 HAVE_WCSDUP
#cmakedefine01 HAVE_WCSLEN
#cmakedefine01 HAVE_WCSNLEN
#cmakedefine01 HAVE_WINDOWS_H
#cmakedefine01 HAVE_WINSOCK2_H
#cmakedefine01 HAVE_WMEMCHR
#cmakedefine01 HAVE_WMEMCMP
#cmakedefine01 HAVE_WMEMCPY
#cmakedefine01 HAVE_WMEMMOVE
#cmakedefine01 HAVE_WMEMSET
#cmakedefine01 HAVE_WS2TCPIP_H
#cmakedefine01 HAVE___XPG_STRERROR_R

#cmakedefine01 CALLOC_0_0_RETURNS_NONNULL
#cmakedefine01 FREE_NULL_IS_NOP
#cmakedefine01 GETCWD_NULL_0_ALLOCATES_MEMORY
#cmakedefine01 MALLOC_0_RETURNS_NONNULL
#cmakedefine01 REALLOC_NULL_0_RETURNS_NONNULL
#cmakedefine01 GAI_STRERROR_RETURNS_CONST_CHAR

#cmakedefine01 LIBCFUNK_REPLACE_ACCEPT
#cmakedefine01 LIBCFUNK_REPLACE_BIND
#cmakedefine01 LIBCFUNK_REPLACE_CALLOC
#cmakedefine01 LIBCFUNK_REPLACE_CONNECT
#cmakedefine01 LIBCFUNK_REPLACE_FREE
#cmakedefine01 LIBCFUNK_REPLACE_GAI_STRERROR
#cmakedefine01 LIBCFUNK_REPLACE_GETCWD
#cmakedefine01 LIBCFUNK_REPLACE_GETHOSTNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETPEERNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETSOCKNAME
#cmakedefine01 LIBCFUNK_REPLACE_LISTEN
#cmakedefine01 LIBCFUNK_REPLACE_MALLOC
#cmakedefine01 LIBCFUNK_REPLACE_REALLOC
#cmakedefine01 LIBCFUNK_REPLACE_RECV
#cmakedefine01 LIBCFUNK_REPLACE_RECVFROM
#cmakedefine01 LIBCFUNK_REPLACE_SEND
#cmakedefine01 LIBCFUNK_REPLACE_SENDTO
#cmakedefine01 LIBCFUNK_REPLACE_SETSOCKOPT
#cmakedefine01 LIBCFUNK_REPLACE_SOCKET

#endif /* CONFIG_H */
