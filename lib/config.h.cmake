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

#ifndef _POSIX_PTHREAD_SEMANTICS
#  define _POSIX_PTHREAD_SEMANTICS 1
#endif

#ifndef __STDC_WANT_LIB_EXT2__
#  define __STDC_WANT_LIB_EXT2__ 1
#endif

#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
#  define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif

#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
#  define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#endif

#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
#  define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#endif

#ifndef _FILE_OFFSET_BITS
#  define _FILE_OFFSET_BITS 64
#endif

#ifndef _LARGE_FILES
#  define _LARGE_FILES 1
#endif

#ifndef _LARGEFILE_SOURCE
#  define _LARGEFILE_SOURCE 1
#endif

#ifndef _TIME_BITS
#  define _TIME_BITS 64
#endif

#ifndef OPENSSL_SUPPRESS_DEPRECATED
#  define OPENSSL_SUPPRESS_DEPRECATED 1
#endif

#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

#ifndef __has_constexpr_builtin
#  define __has_constexpr_builtin(x) 0
#endif

#ifndef __has_feature
#  define __has_feature(x) 0
#endif

#ifndef __has_extension
#  define __has_extension __has_feature
#endif

#ifndef __has_cpp_attribute
#  define __has_cpp_attribute(x) 0
#endif

#ifndef __has_c_attribute
#  define __has_c_attribute(x) 0
#endif

#ifndef __has_attribute
#  define __has_attribute(x) 0
#endif

#ifndef __has_declspec_attribute
#  define __has_declspec_attribute(x) 0
#endif

#ifndef __is_identifier
#  define __is_identifier(x) 1
#endif

#ifndef __has_include
#  define __has_include(x) 0
#endif

#ifndef __has_include_next
#  define __has_include_next(x) 0
#endif

#ifndef __has_warning
#  define __has_warning(x) 0
#endif

#if !defined(__GNUC__) && !defined(__clang__)
#  define __attribute__(ignored)
#endif

#if !defined(__GNUC__) && !defined(__clang__)
#  define __extension__
#endif

#if defined(__GNUC__) && defined(__GNUC_MINOR__)                              \
    && defined(__GNUC_PATCHLEVEL__)
#  define GNUC_PREREQ(major, minor, patch)                                    \
    ((__GNUC__ > (major))                                                     \
     || ((__GNUC__ == (major))                                                \
         && ((__GNUC_MINOR__ > (minor))                                       \
             || ((__GNUC_MINOR__ == (minor))                                  \
                 && ((__GNUC_PATCHLEVEL__ >= (patch)))))))
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
#  define GNUC_PREREQ(major, minor, patch)                                    \
    ((__GNUC__ > (major))                                                     \
     || ((__GNUC__ == (major))                                                \
         && ((__GNUC_MINOR__ > (minor))                                       \
             || ((__GNUC_MINOR__ == (minor)) && ((patch) == 0)))))
#elif defined(__GNUC__)
#  define GNUC_PREREQ(major, minor, patch)                                    \
    ((__GNUC__ > (major))                                                     \
     || ((__GNUC__ == (major)) && ((minor) == 0) && ((patch) == 0)))
#else
#  define GNUC_PREREQ(major, minor, patch) (0)
#endif

#if defined(__clang_major__) && defined(__clang_minor__)                      \
    && defined(__clang_patchlevel__)
#  define CLANG_PREREQ(major, minor, patch)                                   \
    ((__clang_major__ > (major))                                              \
     || ((__clang_major__ == (major))                                         \
         && ((__clang_minor__ > (minor))                                      \
             || ((__clang_minor__ == (minor))                                 \
                 && ((__clang_patchlevel__ >= (patch)))))))
#elif defined(__clang_major__) && defined(__clang_minor__)
#  define CLANG_PREREQ(major, minor, patch)                                   \
    ((__clang_major__ > (major))                                              \
     || ((__clang_major__ == (major))                                         \
         && ((__clang_minor__ > (minor))                                      \
             || ((__clang_minor__ == (minor)) && ((patch) == 0)))))
#elif defined(__clang_major__)
#  define CLANG_PREREQ(major, minor, patch)                                   \
    ((__clang_major__ > (major))                                              \
     || ((__clang_major__ == (major)) && ((minor) == 0) && ((patch) == 0)))
#else
#  define CLANG_PREREQ(major, minor, patch) (0)
#endif

#cmakedefine01 HAVE_A64L
#cmakedefine01 HAVE_ABS
#cmakedefine01 HAVE__ACCESS
#cmakedefine01 HAVE_ACCESS
#cmakedefine01 HAVE_ACTION
#cmakedefine01 HAVE_AFUNIX_H
#cmakedefine01 HAVE_ALIGNED_ALLOC
#cmakedefine01 HAVE_ALLOCA_H
#cmakedefine01 HAVE_ALPHASORT
#cmakedefine01 HAVE___ARGC
#cmakedefine01 HAVE___ARGV
#cmakedefine01 HAVE_ARGZ_ADD
#cmakedefine01 HAVE_ARGZ_APPEND
#cmakedefine01 HAVE_ARGZ_COUNT
#cmakedefine01 HAVE_ARGZ_CREATE
#cmakedefine01 HAVE_ARGZ_EXTRACT
#cmakedefine01 HAVE_ARGZ_H
#cmakedefine01 HAVE_ARGZ_NEXT
#cmakedefine01 HAVE_ARGZ_STRINGIFY
#cmakedefine01 HAVE_AR_H
#cmakedefine01 HAVE_ARPA_INET_H
#cmakedefine01 HAVE_ASPRINTF
#cmakedefine01 HAVE_ASSERT_H
#cmakedefine01 HAVE_ATEXIT
#cmakedefine01 HAVE_ATOF
#cmakedefine01 HAVE_ATOI
#cmakedefine01 HAVE_ATOL
#cmakedefine01 HAVE_ATOLL
#cmakedefine01 HAVE_BCMP
#cmakedefine01 HAVE_BCOPY
#cmakedefine01 HAVE_BCRYPT_H
#cmakedefine01 HAVE_BLKCNT_T
#cmakedefine01 HAVE_BLKSIZE_T
#cmakedefine01 HAVE__BOOL
#cmakedefine01 HAVE_BSEARCH
#cmakedefine01 HAVE_BSWAP_16
#cmakedefine01 HAVE_BSWAP16
#cmakedefine01 HAVE_BSWAP_32
#cmakedefine01 HAVE_BSWAP32
#cmakedefine01 HAVE_BSWAP_64
#cmakedefine01 HAVE_BSWAP64
#cmakedefine01 HAVE_BTOWC
#cmakedefine01 HAVE___BUILTIN_EXPECT
#cmakedefine01 HAVE_BUILTINS_H
#cmakedefine01 HAVE_BYTESWAP_H
#cmakedefine01 HAVE__BYTESWAP_UINT64
#cmakedefine01 HAVE__BYTESWAP_ULONG
#cmakedefine01 HAVE__BYTESWAP_USHORT
#cmakedefine01 HAVE_BZERO
#cmakedefine01 HAVE_C11__ALIGNAS
#cmakedefine01 HAVE_C11__ALIGNOF
#cmakedefine01 HAVE_C11__NORETURN
#cmakedefine01 HAVE_C11_STATIC_ASSERT
#cmakedefine01 HAVE_C11__THREAD_LOCAL
#cmakedefine01 HAVE_C23_ALIGNAS
#cmakedefine01 HAVE_C23_ALIGNOF
#cmakedefine01 HAVE_C23_BOOL
#cmakedefine01 HAVE_C23_NULLPTR
#cmakedefine01 HAVE_C23_STATIC_ASSERT
#cmakedefine01 HAVE_C23_THREAD_LOCAL
#cmakedefine01 HAVE_C99_BOOL
#cmakedefine01 HAVE_C99__EXIT
#cmakedefine01 HAVE_C99__FUNC__
#cmakedefine01 HAVE_CALLOC
#cmakedefine01 HAVE_CALL_ONCE
#cmakedefine01 HAVE_CC_T
#cmakedefine01 HAVE_CEIL
#cmakedefine01 HAVE_CEILF
#cmakedefine01 HAVE_CEILL
#cmakedefine01 HAVE_CHAR16_T
#cmakedefine01 HAVE_CHAR32_T
#cmakedefine01 HAVE_CHAR8_T
#cmakedefine01 HAVE__CHDIR
#cmakedefine01 HAVE_CHDIR
#cmakedefine01 HAVE__CHMOD
#cmakedefine01 HAVE_CHMOD
#cmakedefine01 HAVE_CHOWN
#cmakedefine01 HAVE_CLEARERR
#cmakedefine01 HAVE_CLEARERR_UNLOCKED
#cmakedefine01 HAVE_CLOCK
#cmakedefine01 HAVE_CLOCK_GETRES
#cmakedefine01 HAVE_CLOCKGETRES
#cmakedefine01 HAVE_CLOCK_GETTIME
#cmakedefine01 HAVE_CLOCK_GETTIME_IN_LIBC
#cmakedefine01 HAVE_CLOCK_GETTIME_IN_LIBPOSIX4
#cmakedefine01 HAVE_CLOCK_GETTIME_IN_LIBRT
#cmakedefine01 HAVE_CLOCKID_T
#cmakedefine01 HAVE_CLOCK_T
#cmakedefine01 HAVE__CLOSE
#cmakedefine01 HAVE_CLOSE
#cmakedefine01 HAVE_CLOSEDIR
#cmakedefine01 HAVE_CND_BROADCAST
#cmakedefine01 HAVE_CND_DESTROY
#cmakedefine01 HAVE_CND_INIT
#cmakedefine01 HAVE_CND_SIGNAL
#cmakedefine01 HAVE_CND_T
#cmakedefine01 HAVE_CND_TIMEDWAIT
#cmakedefine01 HAVE_CND_WAIT
#cmakedefine01 HAVE_COPY_FILE_RANGE
#cmakedefine01 HAVE_COPYSIGN
#cmakedefine01 HAVE_COPYSIGNF
#cmakedefine01 HAVE_COPYSIGNL
#cmakedefine01 HAVE_CPIO_H
#cmakedefine01 HAVE_CREAT
#cmakedefine01 HAVE_CRTDBG_H
#cmakedefine01 HAVE_CRT_EXTERNS_H
#cmakedefine01 HAVE__CRTSETREPORTMODE
#cmakedefine01 HAVE_CTYPE_H
#cmakedefine01 HAVE_DAEMON
#cmakedefine01 HAVE___DECLSPEC_THREAD
#cmakedefine01 HAVE_DEV_PTC
#cmakedefine01 HAVE_DEV_PTM
#cmakedefine01 HAVE_DEV_PTMX
#cmakedefine01 HAVE_DEV_T
#cmakedefine01 HAVE_DIFFTIME
#cmakedefine01 HAVE_DIR
#cmakedefine01 HAVE_DIR_DD_FD
#cmakedefine01 HAVE_DIR_D_FD
#cmakedefine01 HAVE_DIRECT_H
#cmakedefine01 HAVE_DIRENT_H
#cmakedefine01 HAVE_DIR_FD
#cmakedefine01 HAVE_DIRFD
#cmakedefine01 HAVE_DIV
#cmakedefine01 HAVE_DIV_T
#cmakedefine01 HAVE_DPRINTF
#cmakedefine01 HAVE__DUP
#cmakedefine01 HAVE_DUP
#cmakedefine01 HAVE__DUP2
#cmakedefine01 HAVE_DUP2
#cmakedefine01 HAVE_DYSIZE
#cmakedefine01 HAVE_EACCESS
#cmakedefine01 HAVE_ENDIAN_H
#cmakedefine01 HAVE_ENDUSERSHELL
#cmakedefine01 HAVE_ENTRY
#cmakedefine01 HAVE_ENVIRON
#cmakedefine01 HAVE_ERR
#cmakedefine01 HAVE_ERRC
#cmakedefine01 HAVE_ERR_H
#cmakedefine01 HAVE_ERRNO_H
#cmakedefine01 HAVE_ERROR
#cmakedefine01 HAVE_ERROR_AT_LINE
#cmakedefine01 HAVE_ERROR_H
#cmakedefine01 HAVE_ERROR_MESSAGE_COUNT
#cmakedefine01 HAVE_ERROR_ONE_PER_LINE
#cmakedefine01 HAVE_ERROR_PRINT_PROGNAME
#cmakedefine01 HAVE_ERROR_T
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
#cmakedefine01 HAVE_FABS
#cmakedefine01 HAVE_FABSF
#cmakedefine01 HAVE_FABSL
#cmakedefine01 HAVE_FACCESSAT
#cmakedefine01 HAVE___FBUFSIZE
#cmakedefine01 HAVE_FCHDIR
#cmakedefine01 HAVE_FCHMOD
#cmakedefine01 HAVE_FCHMODAT
#cmakedefine01 HAVE_FCHOWN
#cmakedefine01 HAVE_FCHOWNAT
#cmakedefine01 HAVE_FCLOSE
#cmakedefine01 HAVE_FCNTL
#cmakedefine01 HAVE_FCNTL_H
#cmakedefine01 HAVE_FDATASYNC
#cmakedefine01 HAVE_FDATASYNC_IN_LIBC
#cmakedefine01 HAVE_FDATASYNC_IN_LIBPOSIX4
#cmakedefine01 HAVE_FDATASYNC_IN_LIBRT
#cmakedefine01 HAVE_FDOPEN
#cmakedefine01 HAVE_FDOPENDIR
#cmakedefine01 HAVE_FEATURES_H
#cmakedefine01 HAVE_FENV_H
#cmakedefine01 HAVE_FENV_T
#cmakedefine01 HAVE_FEOF
#cmakedefine01 HAVE_FEOF_UNLOCKED
#cmakedefine01 HAVE_FERROR
#cmakedefine01 HAVE_FERROR_UNLOCKED
#cmakedefine01 HAVE_FEXCEPT_T
#cmakedefine01 HAVE_FFLUSH
#cmakedefine01 HAVE__FFLUSH_NOLOCK
#cmakedefine01 HAVE_FFLUSH_UNLOCKED
#cmakedefine01 HAVE_FFS
#cmakedefine01 HAVE_FFSL
#cmakedefine01 HAVE_FFSLL
#cmakedefine01 HAVE__FGETC_NOLOCK
#cmakedefine01 HAVE_FGETC_UNLOCKED
#cmakedefine01 HAVE_FGETPOS
#cmakedefine01 HAVE_FGETS_UNLOCKED
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
#cmakedefine01 HAVE_FILENO_UNLOCKED
#cmakedefine01 HAVE_FILE__P
#cmakedefine01 HAVE_FILE__PTR
#cmakedefine01 HAVE___FLBF
#cmakedefine01 HAVE_FLOAT_H
#cmakedefine01 HAVE_FLOCK
#cmakedefine01 HAVE_FLOCKFILE
#cmakedefine01 HAVE_FLOOR
#cmakedefine01 HAVE_FLOORF
#cmakedefine01 HAVE_FLOORL
#cmakedefine01 HAVE_FLS
#cmakedefine01 HAVE_FLSL
#cmakedefine01 HAVE_FLSLL
#cmakedefine01 HAVE_FMTMSG_H
#cmakedefine01 HAVE_FNMATCH
#cmakedefine01 HAVE_FNMATCH_H
#cmakedefine01 HAVE_FOPEN
#cmakedefine01 HAVE_FORK
#cmakedefine01 HAVE_FORK_IN_LIBC
#cmakedefine01 HAVE_FORK_IN_LIBPOSIX4
#cmakedefine01 HAVE_FORK_IN_LIBRT
#cmakedefine01 HAVE_FORKPTY
#cmakedefine01 HAVE_FORKPTY_IN_LIBC
#cmakedefine01 HAVE_FORKPTY_IN_LIBUTIL
#cmakedefine01 HAVE___FPENDING
#cmakedefine01 HAVE_FPRINTF
#cmakedefine01 HAVE___FPURGE
#cmakedefine01 HAVE_FPUTC_UNLOCKED
#cmakedefine01 HAVE_FPUTS_UNLOCKED
#cmakedefine01 HAVE_FREAD
#cmakedefine01 HAVE___FREADABLE
#cmakedefine01 HAVE___FREADING
#cmakedefine01 HAVE__FREAD_NOLOCK
#cmakedefine01 HAVE_FREAD_UNLOCKED
#cmakedefine01 HAVE_FREE
#cmakedefine01 HAVE_FREEADDRINFO
#cmakedefine01 HAVE_FREOPEN
#cmakedefine01 HAVE_FSBLKCNT_T
#cmakedefine01 HAVE_FSEEK
#cmakedefine01 HAVE__FSEEKI64
#cmakedefine01 HAVE_FSEEKO
#cmakedefine01 HAVE___FSETERR
#cmakedefine01 HAVE_FSETPOS
#cmakedefine01 HAVE_FSFILCNT_T
#cmakedefine01 HAVE__FSTAT
#cmakedefine01 HAVE_FSTAT
#cmakedefine01 HAVE_FSTATAT
#cmakedefine01 HAVE_FSYNC
#cmakedefine01 HAVE_FTELL
#cmakedefine01 HAVE__FTELLI64
#cmakedefine01 HAVE_FTELLO
#cmakedefine01 HAVE_FTIME
#cmakedefine01 HAVE_FTRUNCATE
#cmakedefine01 HAVE_FTRYLOCKFILE
#cmakedefine01 HAVE_FTW_H
#cmakedefine01 HAVE_FUNLOCKFILE
#cmakedefine01 HAVE_FUTIMENS
#cmakedefine01 HAVE___FWRITABLE
#cmakedefine01 HAVE_FWRITE
#cmakedefine01 HAVE__FWRITE_NOLOCK
#cmakedefine01 HAVE_FWRITE_UNLOCKED
#cmakedefine01 HAVE___FWRITING
#cmakedefine01 HAVE_GAI_STRERROR
#cmakedefine01 HAVE_GAI_STRERRORA
#cmakedefine01 HAVE_GETADDRINFO
#cmakedefine01 HAVE__GETCHAR_NOLOCK
#cmakedefine01 HAVE_GETCHAR_UNLOCKED
#cmakedefine01 HAVE__GETC_NOLOCK
#cmakedefine01 HAVE_GETC_UNLOCKED
#cmakedefine01 HAVE_GET_CURRENT_DIR_NAME
#cmakedefine01 HAVE__GETCWD
#cmakedefine01 HAVE_GETCWD
#cmakedefine01 HAVE_GETDELIM
#cmakedefine01 HAVE_GETDTABLESIZE
#cmakedefine01 HAVE_GETEGID
#cmakedefine01 HAVE_GETENTROPY
#cmakedefine01 HAVE_GETENV
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
#cmakedefine01 HAVE_GETNAMEINFO
#cmakedefine01 HAVE_GETOPT
#cmakedefine01 HAVE_GETOPT_H
#cmakedefine01 HAVE_GETOPT_LONG
#cmakedefine01 HAVE_GETOPT_LONG_ONLY
#cmakedefine01 HAVE_GETPAGESIZE
#cmakedefine01 HAVE_GETPASS
#cmakedefine01 HAVE_GETPID
#cmakedefine01 HAVE_GETPPID
#cmakedefine01 HAVE_GETPROGNAME
#cmakedefine01 HAVE_GETRANDOM
#cmakedefine01 HAVE_GETRLIMIT
#cmakedefine01 HAVE_GETRUSAGE
#cmakedefine01 HAVE_GETSUBOPT
#cmakedefine01 HAVE_GETTIMEOFDAY
#cmakedefine01 HAVE_GETUID
#cmakedefine01 HAVE_GETUSERHSELL
#cmakedefine01 HAVE_GETUSERSHELL
#cmakedefine01 HAVE_GID_T
#cmakedefine01 HAVE_GLOB
#cmakedefine01 HAVE_GLOBFREE
#cmakedefine01 HAVE_GLOB_H
#cmakedefine01 HAVE_GLOB_PATTERN_P
#cmakedefine01 HAVE_GLOB_T
#cmakedefine01 HAVE_GMTIME_R
#cmakedefine01 HAVE_GNUC___THREAD
#cmakedefine01 HAVE_GROUP_MEMBER
#cmakedefine01 HAVE_GRP_H
#cmakedefine01 HAVE_HAVE_DIRECT_H
#cmakedefine01 HAVE_ICONV_H
#cmakedefine01 HAVE_ICONV_T
#cmakedefine01 HAVE_ID_T
#cmakedefine01 HAVE_IDTYPE_T
#cmakedefine01 HAVE_IF_FREENAMEINDEX
#cmakedefine01 HAVE_IF_INDEXTONAME
#cmakedefine01 HAVE_IF_NAMEINDEX
#cmakedefine01 HAVE_IF_NAMETOINDEX
#cmakedefine01 HAVE_IMAXABS
#cmakedefine01 HAVE_IMAXDIV
#cmakedefine01 HAVE_IMAXDIV_T
#cmakedefine01 HAVE_IN_ADDR_T
#cmakedefine01 HAVE_INCLUDE_NEXT
#cmakedefine01 HAVE_INDEX
#cmakedefine01 HAVE_INET_ADDR
#cmakedefine01 HAVE_INET_ATON
#cmakedefine01 HAVE_INET_NTOA
#cmakedefine01 HAVE_INET_NTOP
#cmakedefine01 HAVE_INET_PTON
#cmakedefine01 HAVE_INO_T
#cmakedefine01 HAVE_IN_PORT_T
#cmakedefine01 HAVE_INSQUE
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
#cmakedefine01 HAVE_INTRIN_H
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
#cmakedefine01 HAVE_ISWALNUM
#cmakedefine01 HAVE_ISWALPHA
#cmakedefine01 HAVE_ISWBLANK
#cmakedefine01 HAVE_ISWCNTRL
#cmakedefine01 HAVE_ISWCTYPE
#cmakedefine01 HAVE_ISWDIGIT
#cmakedefine01 HAVE_ISWGRAPH
#cmakedefine01 HAVE_ISWLOWER
#cmakedefine01 HAVE_ISWPRINT
#cmakedefine01 HAVE_ISWPUNCT
#cmakedefine01 HAVE_ISWSPACE
#cmakedefine01 HAVE_ISWUPPER
#cmakedefine01 HAVE_ISWXDIGIT
#cmakedefine01 HAVE_ISXDIGIT
#cmakedefine01 HAVE_KILL
#cmakedefine01 HAVE_L64A
#cmakedefine01 HAVE_L64A_R
#cmakedefine01 HAVE_LABS
#cmakedefine01 HAVE_LANGINFO_H
#cmakedefine01 HAVE_LCHMOD
#cmakedefine01 HAVE_LCHOWN
#cmakedefine01 HAVE_LDIV
#cmakedefine01 HAVE_LDIV_T
#cmakedefine01 HAVE_LIBC_PTHREAD
#cmakedefine01 HAVE_LIBGEN_H
#cmakedefine01 HAVE_LIBKERN_OSBYTEORDER_H
#cmakedefine01 HAVE_LIBUTIL
#cmakedefine01 HAVE_LIBUTIL_H
#cmakedefine01 HAVE_LIMITS_H
#cmakedefine01 HAVE_LINK
#cmakedefine01 HAVE_LINKAT
#cmakedefine01 HAVE_LLABS
#cmakedefine01 HAVE_LLDIV
#cmakedefine01 HAVE_LLDIV_T
#cmakedefine01 HAVE_LOCALECONV
#cmakedefine01 HAVE_LOCALE_H
#cmakedefine01 HAVE_LOCALTIME_R
#cmakedefine01 HAVE__LOCK_FILE
#cmakedefine01 HAVE_LOGIN_TTY
#cmakedefine01 HAVE_LOGIN_TTY_IN_LIBC
#cmakedefine01 HAVE_LOGIN_TTY_IN_LIBUTIL
#cmakedefine01 HAVE__LSEEK
#cmakedefine01 HAVE_LSEEK
#cmakedefine01 HAVE__LSEEKI64
#cmakedefine01 HAVE_LSTAT
#cmakedefine01 HAVE_MALLOC
#cmakedefine01 HAVE_MALLOC_H
#cmakedefine01 HAVE_MATH_H
#cmakedefine01 HAVE_MAX_ALIGN_T
#cmakedefine01 HAVE_MBLEN
#cmakedefine01 HAVE_MBRLEN
#cmakedefine01 HAVE_MBRTOWC
#cmakedefine01 HAVE_MBSINIT
#cmakedefine01 HAVE_MBSNRTOWCS
#cmakedefine01 HAVE_MBSRTOWCS
#cmakedefine01 HAVE_MBSTATE_T
#cmakedefine01 HAVE_MBSTOWCS
#cmakedefine01 HAVE_MBTOWC
#cmakedefine01 HAVE_MEMALIGN
#cmakedefine01 HAVE_MEMCHR
#cmakedefine01 HAVE_MEMCMP
#cmakedefine01 HAVE_MEMCPY
#cmakedefine01 HAVE_MEMMOVE
#cmakedefine01 HAVE_MEMPCPY
#cmakedefine01 HAVE_MEMRCHR
#cmakedefine01 HAVE_MEMSET
#cmakedefine01 HAVE_MEMSET_EXPLICIT
#cmakedefine01 HAVE_MEMSET_S
#cmakedefine01 HAVE__MKDIR
#cmakedefine01 HAVE_MKDIR
#cmakedefine01 HAVE_MKDIRAT
#cmakedefine01 HAVE_MKDTEMP
#cmakedefine01 HAVE_MKFIFO
#cmakedefine01 HAVE_MKFIFOAT
#cmakedefine01 HAVE_MKNOD
#cmakedefine01 HAVE_MKNODAT
#cmakedefine01 HAVE_MKOSTEMP
#cmakedefine01 HAVE_MKOSTEMPS
#cmakedefine01 HAVE_MKSTEMP
#cmakedefine01 HAVE_MKSTEMPS
#cmakedefine01 HAVE_MKTIME
#cmakedefine01 HAVE_MODE_T
#cmakedefine01 HAVE_MONETARY_H
#cmakedefine01 HAVE_MTX_DESTROY
#cmakedefine01 HAVE_MTX_INIT
#cmakedefine01 HAVE_MTX_LOCK
#cmakedefine01 HAVE_MTX_T
#cmakedefine01 HAVE_MTX_TIMEDLOCK
#cmakedefine01 HAVE_MTX_TRYLOCK
#cmakedefine01 HAVE_MTX_UNLOCK
#cmakedefine01 HAVE_NANOSLEEP
#cmakedefine01 HAVE_NANOSLEEP_IN_LIBC
#cmakedefine01 HAVE_NANOSLEEP_IN_LIBPOSIX4
#cmakedefine01 HAVE_NANOSLEEP_IN_LIBRT
#cmakedefine01 HAVE_NETDB_H
#cmakedefine01 HAVE_NET_IF_H
#cmakedefine01 HAVE_NETINET_IN_H
#cmakedefine01 HAVE_NFDS_T
#cmakedefine01 HAVE_NLINK_T
#cmakedefine01 HAVE_NL_ITEM
#cmakedefine01 HAVE_NL_LANGINFO
#cmakedefine01 HAVE_NL_LANGINFO_CODESET
#cmakedefine01 HAVE_NL_TYPES_H
#cmakedefine01 HAVE__NSGETENVIRON
#cmakedefine01 HAVE_OFF_T
#cmakedefine01 HAVE_ONCE_FLAG
#cmakedefine01 HAVE_ON_EXIT
#cmakedefine01 HAVE__OPEN
#cmakedefine01 HAVE_OPEN
#cmakedefine01 HAVE_OPENAT
#cmakedefine01 HAVE_OPENDIR
#cmakedefine01 HAVE_OPENPTY
#cmakedefine01 HAVE_OPENPTY_IN_LIBC
#cmakedefine01 HAVE_OPENPTY_IN_LIBUTIL
#cmakedefine01 HAVE_OPENSSL_MD4_H
#cmakedefine01 HAVE_OPENSSL_MD5_H
#cmakedefine01 HAVE_OPENSSL_RC4_H
#cmakedefine01 HAVE_OPENSSL_SHA_H
#cmakedefine01 HAVE_OPTARG
#cmakedefine01 HAVE_OPTERR
#cmakedefine01 HAVE_OPTIND
#cmakedefine01 HAVE_OPTOPT
#cmakedefine01 HAVE_OSSWAPINT16
#cmakedefine01 HAVE_OSSWAPINT32
#cmakedefine01 HAVE_OSSWAPINT64
#cmakedefine01 HAVE__PCLOSE
#cmakedefine01 HAVE_PCLOSE
#cmakedefine01 HAVE_PERROR
#cmakedefine01 HAVE_PID_T
#cmakedefine01 HAVE__PIPE
#cmakedefine01 HAVE_PIPE
#cmakedefine01 HAVE_POLL
#cmakedefine01 HAVE_POLL_H
#cmakedefine01 HAVE_POPCOUNT
#cmakedefine01 HAVE_POPCOUNTL
#cmakedefine01 HAVE_POPCOUNTLL
#cmakedefine01 HAVE__POPEN
#cmakedefine01 HAVE_POPEN
#cmakedefine01 HAVE_POSIX_FADVISE
#cmakedefine01 HAVE_POSIX_FALLOCATE
#cmakedefine01 HAVE_POSIX_MEMALIGN
#cmakedefine01 HAVE_POSIX_OPENPT
#cmakedefine01 HAVE_POSIX_SPAWN
#cmakedefine01 HAVE_POSIX_SPAWNATTR_DESTROY
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETFLAGS
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETPGROUP
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETSCHEDPARAM
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETSCHEDPOLICY
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETSIGDEFAULT
#cmakedefine01 HAVE_POSIX_SPAWNATTR_GETSIGMASK
#cmakedefine01 HAVE_POSIX_SPAWNATTR_INIT
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETFLAGS
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETPGROUP
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETSCHEDPARAM
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETSCHEDPOLICY
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETSIGDEFAULT
#cmakedefine01 HAVE_POSIX_SPAWNATTR_SETSIGMASK
#cmakedefine01 HAVE_POSIX_SPAWNATTR_T
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDOPEN
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_DESTROY
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_INIT
#cmakedefine01 HAVE_POSIX_SPAWN_FILE_ACTIONS_T
#cmakedefine01 HAVE_POSIX_SPAWNP
#cmakedefine01 HAVE_PREAD
#cmakedefine01 HAVE_PROCESS_H
#cmakedefine01 HAVE___PROGNAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_NAME
#cmakedefine01 HAVE_PROGRAM_INVOCATION_SHORT_NAME
#cmakedefine01 HAVE_PSELECT
#cmakedefine01 HAVE_PTHREAD_ARG
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
#cmakedefine01 HAVE_PTHREAD_SIGMASK
#cmakedefine01 HAVE_PTHREAD_SPINLOCK_T
#cmakedefine01 HAVE_PTHREAD_T
#cmakedefine01 HAVE_PTRDIFF_T
#cmakedefine01 HAVE_PTSNAME
#cmakedefine01 HAVE_PTSNAME_R
#cmakedefine01 HAVE_PTY_H
#cmakedefine01 HAVE__PUTCHAR_NOLOCK
#cmakedefine01 HAVE_PUTCHAR_UNLOCKED
#cmakedefine01 HAVE__PUTC_NOLOCK
#cmakedefine01 HAVE_PUTC_UNLOCKED
#cmakedefine01 HAVE_PUTENV
#cmakedefine01 HAVE_PWD_H
#cmakedefine01 HAVE_PWRITE
#cmakedefine01 HAVE_QSORT
#cmakedefine01 HAVE_QSORT_R
#cmakedefine01 HAVE_RAISE
#cmakedefine01 HAVE_RAND
#cmakedefine01 HAVE_RANDOM
#cmakedefine01 HAVE_RANDOM_R
#cmakedefine01 HAVE_RAWMEMCHR
#cmakedefine01 HAVE__READ
#cmakedefine01 HAVE_READ
#cmakedefine01 HAVE_READDIR
#cmakedefine01 HAVE_READDIR_R
#cmakedefine01 HAVE_READLINK
#cmakedefine01 HAVE_READLINKAT
#cmakedefine01 HAVE_REALLOC
#cmakedefine01 HAVE_REALLOCARRAY
#cmakedefine01 HAVE_REALLOCF
#cmakedefine01 HAVE_REALPATH
#cmakedefine01 HAVE__REMOVE
#cmakedefine01 HAVE_REMOVE
#cmakedefine01 HAVE_REMQUE
#cmakedefine01 HAVE_RENAME
#cmakedefine01 HAVE_RENAMEAT
#cmakedefine01 HAVE_REVOKE
#cmakedefine01 HAVE_REWIND
#cmakedefine01 HAVE_REWINDDIR
#cmakedefine01 HAVE_RINDEX
#cmakedefine01 HAVE_RLIM_T
#cmakedefine01 HAVE__RMDIR
#cmakedefine01 HAVE_RMDIR
#cmakedefine01 HAVE_SA_FAMILY_T
#cmakedefine01 HAVE_SCANDIR
#cmakedefine01 HAVE_SCHED_GETAFFINITY
#cmakedefine01 HAVE_SCHED_H
#cmakedefine01 HAVE_SCHED_YIELD
#cmakedefine01 HAVE_SCHED_YIELD_IN_LIBC
#cmakedefine01 HAVE_SCHED_YIELD_IN_LIBPOSIX4
#cmakedefine01 HAVE_SCHED_YIELD_IN_LIBRT
#cmakedefine01 HAVE_SEARCH_H
#cmakedefine01 HAVE_SECURE_GETENV
#cmakedefine01 HAVE_SECUREZEROMEMORY
#cmakedefine01 HAVE_SEEKDIR
#cmakedefine01 HAVE_SELECT
#cmakedefine01 HAVE_SEMAPHORE_H
#cmakedefine01 HAVE_SETBUF
#cmakedefine01 HAVE_SETENV
#cmakedefine01 HAVE_SETHOSTNAME
#cmakedefine01 HAVE__SET_INVALID_PARAMETER_HANDLER
#cmakedefine01 HAVE_SETLOCALE
#cmakedefine01 HAVE__SETMODE
#cmakedefine01 HAVE_SETMODE
#cmakedefine01 HAVE_SETPROGNAME
#cmakedefine01 HAVE_SETRLIMIT
#cmakedefine01 HAVE_SETSID
#cmakedefine01 HAVE_SETUSERSHELL
#cmakedefine01 HAVE_SETVBUF
#cmakedefine01 HAVE_SIG2STR
#cmakedefine01 HAVE_SIGABBREV_NP
#cmakedefine01 HAVE_SIGACTION
#cmakedefine01 HAVE_SIGADDSET
#cmakedefine01 HAVE_SIG_ATOMIC_T
#cmakedefine01 HAVE_SIGDELSET
#cmakedefine01 HAVE_SIGDESCR_NP
#cmakedefine01 HAVE_SIGEMPTYSET
#cmakedefine01 HAVE_SIGFILLSET
#cmakedefine01 HAVE_SIGHANDLER_T
#cmakedefine01 HAVE_SIGINFO_T
#cmakedefine01 HAVE_SIGISMEMBER
#cmakedefine01 HAVE_SIGNAL
#cmakedefine01 HAVE_SIGNAL_H
#cmakedefine01 HAVE_SIGPROCMASK
#cmakedefine01 HAVE_SIGSET_T
#cmakedefine01 HAVE_SIG_T
#cmakedefine01 HAVE_SIZE_T
#cmakedefine01 HAVE_SLEEP
#cmakedefine01 HAVE_SNPRINTF
#cmakedefine01 HAVE_SOCKETLEN_T
#cmakedefine01 HAVE_SPAWN_H
#cmakedefine01 HAVE_SPEED_T
#cmakedefine01 HAVE_SPRINTF
#cmakedefine01 HAVE_SSIZE_T
#cmakedefine01 HAVE_STACK_T
#cmakedefine01 HAVE__STAT
#cmakedefine01 HAVE_STAT
#cmakedefine01 HAVE_STDALIGN_H
#cmakedefine01 HAVE_STDARG_H
#cmakedefine01 HAVE_STDATOMIC_H
#cmakedefine01 HAVE_STDBIT_H
#cmakedefine01 HAVE_STDBOOL_H
#cmakedefine01 HAVE_STDCKDINT_H
#cmakedefine01 HAVE_STDDEF_H
#cmakedefine01 HAVE_STDINT_H
#cmakedefine01 HAVE_STDIO_EXT_H
#cmakedefine01 HAVE_STDIO_H
#cmakedefine01 HAVE_STDLIB_H
#cmakedefine01 HAVE_STDNORETURN_H
#cmakedefine01 HAVE_STPCPY
#cmakedefine01 HAVE_STPNCPY
#cmakedefine01 HAVE_STR2SIG
#cmakedefine01 HAVE_STRCASECMP
#cmakedefine01 HAVE_STRCAT
#cmakedefine01 HAVE_STRCHR
#cmakedefine01 HAVE_STRCHRNUL
#cmakedefine01 HAVE_STRCMP
#cmakedefine01 HAVE_STRCPY
#cmakedefine01 HAVE_STRCSPN
#cmakedefine01 HAVE_STRDUP
#cmakedefine01 HAVE_STRERRORDESC_NP
#cmakedefine01 HAVE_STRERRORNAME_NP
#cmakedefine01 HAVE_STRERROR_R
#cmakedefine01 HAVE_STRERROR_S
#cmakedefine01 HAVE_STRFTIME
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
#cmakedefine01 HAVE_STROPTS_H
#cmakedefine01 HAVE_STRPBRK
#cmakedefine01 HAVE_STRPTIME
#cmakedefine01 HAVE_STRRCHR
#cmakedefine01 HAVE_STRSEP
#cmakedefine01 HAVE_STRSIGNAL
#cmakedefine01 HAVE_STRSPN
#cmakedefine01 HAVE_STRSTR
#cmakedefine01 HAVE_STRTOD
#cmakedefine01 HAVE_STRTOF
#cmakedefine01 HAVE_STRTOIMAX
#cmakedefine01 HAVE_STRTOK
#cmakedefine01 HAVE_STRTOK_R
#cmakedefine01 HAVE_STRTOL
#cmakedefine01 HAVE_STRTOLD
#cmakedefine01 HAVE_STRTOLL
#cmakedefine01 HAVE_STRTOUL
#cmakedefine01 HAVE_STRTOULL
#cmakedefine01 HAVE_STRTOUMAX
#cmakedefine01 HAVE_STRUCT_ADDRINFO
#cmakedefine01 HAVE_STRUCT_AR_HDR
#cmakedefine01 HAVE_STRUCT_CMSGHDR
#cmakedefine01 HAVE_STRUCT_DIRENT
#cmakedefine01 HAVE_STRUCT_ENTRY
#cmakedefine01 HAVE_STRUCT_FLOCK
#cmakedefine01 HAVE_STRUCT_FLOCK_L_LEN
#cmakedefine01 HAVE_STRUCT_FLOCK_L_PID
#cmakedefine01 HAVE_STRUCT_FLOCK_L_START
#cmakedefine01 HAVE_STRUCT_FLOCK_L_TYPE
#cmakedefine01 HAVE_STRUCT_FLOCK_L_WHENCE
#cmakedefine01 HAVE_STRUCT_FTW
#cmakedefine01 HAVE_STRUCT_GROUP
#cmakedefine01 HAVE_STRUCT_HOSTENT
#cmakedefine01 HAVE_STRUCT_IF_NAMEINDEX
#cmakedefine01 HAVE_STRUCT_IN6_ADDR
#cmakedefine01 HAVE_STRUCT_IN_ADDR
#cmakedefine01 HAVE_STRUCT_IOVEC
#cmakedefine01 HAVE_STRUCT_ITIMERSPEC
#cmakedefine01 HAVE_STRUCT_ITIMERVAL
#cmakedefine01 HAVE_STRUCT_LCONV
#cmakedefine01 HAVE_STRUCT_LINGER
#cmakedefine01 HAVE_STRUCT_NETENT
#cmakedefine01 HAVE_STRUCT_OPTION
#cmakedefine01 HAVE_STRUCT_PASSWD
#cmakedefine01 HAVE_STRUCT_POLLFD
#cmakedefine01 HAVE_STRUCT_PROTOENT
#cmakedefine01 HAVE_STRUCT_PTMGET
#cmakedefine01 HAVE_STRUCT_QELEM
#cmakedefine01 HAVE_STRUCT_RANDOM_DATA
#cmakedefine01 HAVE_STRUCT_RLIMIT
#cmakedefine01 HAVE_STRUCT_RUSAGE
#cmakedefine01 HAVE_STRUCT_SCHED_PARAM
#cmakedefine01 HAVE_STRUCT_SERVENT
#cmakedefine01 HAVE_STRUCT_SIGACTION
#cmakedefine01 HAVE_STRUCT_SIGEVENT
#cmakedefine01 HAVE_STRUCT_SOCKADDR
#cmakedefine01 HAVE_STRUCT_SOCKADDR_IN
#cmakedefine01 HAVE_STRUCT_SOCKADDR_IN6
#cmakedefine01 HAVE_STRUCT_SOCKADDR_STORAGE
#cmakedefine01 HAVE_STRUCT_SOCKADDR_UN
#cmakedefine01 HAVE_STRUCT_STAT
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
#cmakedefine01 HAVE_STRUCT_STATVFS
#cmakedefine01 HAVE_STRUCT_TERMIOS
#cmakedefine01 HAVE_STRUCT_TIMEB
#cmakedefine01 HAVE_STRUCT_TIMESPEC
#cmakedefine01 HAVE_STRUCT_TIMEVAL
#cmakedefine01 HAVE_STRUCT_TM
#cmakedefine01 HAVE_STRUCT_TMS
#cmakedefine01 HAVE_STRUCT__UTIMBUF
#cmakedefine01 HAVE_STRUCT_UTIMBUF
#cmakedefine01 HAVE_STRUCT_UTMPX
#cmakedefine01 HAVE_STRUCT_UTSNAME
#cmakedefine01 HAVE_STRUCT_WINSIZE
#cmakedefine01 HAVE_STRVERSCMP
#cmakedefine01 HAVE_SUSECONDS_T
#cmakedefine01 HAVE_SWAB
#cmakedefine01 HAVE_SWAP16
#cmakedefine01 HAVE_SWAP32
#cmakedefine01 HAVE_SWAP64
#cmakedefine01 HAVE_SYMLINK
#cmakedefine01 HAVE_SYMLINKAT
#cmakedefine01 HAVE_SYS_BYTEORDER_H
#cmakedefine01 HAVE_SYSCONF
#cmakedefine01 HAVE_SYS_ENDIAN_H
#cmakedefine01 HAVE_SYSEXITS_H
#cmakedefine01 HAVE_SYS_FILE_H
#cmakedefine01 HAVE_SYSINFOAPI_H
#cmakedefine01 HAVE_SYS_IOCTL_H
#cmakedefine01 HAVE_SYS_LOADAVG_H
#cmakedefine01 HAVE_SYS_MMAN_H
#cmakedefine01 HAVE_SYS_MSG_H
#cmakedefine01 HAVE_SYS_PARAM_H
#cmakedefine01 HAVE_SYS_RANDOM_H
#cmakedefine01 HAVE_SYS_RESOURCE_H
#cmakedefine01 HAVE_SYS_SELECT_H
#cmakedefine01 HAVE_SYS_SEM_H
#cmakedefine01 HAVE_SYS_SHM_H
#cmakedefine01 HAVE_SYS_SOCKET_H
#cmakedefine01 HAVE_SYS_STAT_H
#cmakedefine01 HAVE_SYS_STATVFS_H
#cmakedefine01 HAVE_SYS_SYSCTL_H
#cmakedefine01 HAVE_SYS_TIMEB_H
#cmakedefine01 HAVE_SYS_TIME_H
#cmakedefine01 HAVE_SYS_TIMES_H
#cmakedefine01 HAVE_SYS_TTY_H
#cmakedefine01 HAVE_SYS_TYPES_H
#cmakedefine01 HAVE_SYS_UIO_H
#cmakedefine01 HAVE_SYS_UN_H
#cmakedefine01 HAVE_SYS_UN_H_PATH
#cmakedefine01 HAVE_SYS_UTIME_H
#cmakedefine01 HAVE_SYS_UTSNAME_H
#cmakedefine01 HAVE_SYS_WAIT_H
#cmakedefine01 HAVE_TAR_H
#cmakedefine01 HAVE_TCFLAG_T
#cmakedefine01 HAVE_TCGETSID
#cmakedefine01 HAVE_TELLDIR
#cmakedefine01 HAVE_TEMPNAM
#cmakedefine01 HAVE_TERMIOS_H
#cmakedefine01 HAVE_TGMATH_H
#cmakedefine01 HAVE_THRD_CREATE
#cmakedefine01 HAVE_THRD_CURRENT
#cmakedefine01 HAVE_THRD_DETACH
#cmakedefine01 HAVE_THRD_EQUAL
#cmakedefine01 HAVE_THRD_EXIT
#cmakedefine01 HAVE_THRD_JOIN
#cmakedefine01 HAVE_THRD_SLEEP
#cmakedefine01 HAVE_THRD_START_T
#cmakedefine01 HAVE_THRD_T
#cmakedefine01 HAVE_THRD_YIELD
#cmakedefine01 HAVE_THREADS_H
#cmakedefine01 HAVE_TIME
#cmakedefine01 HAVE_TIME_H
#cmakedefine01 HAVE_TIMER_T
#cmakedefine01 HAVE_TIMES
#cmakedefine01 HAVE_TIMESPEC_GET
#cmakedefine01 HAVE_TIMESPEC_GETRES
#cmakedefine01 HAVE_TIME_T
#cmakedefine01 HAVE_TIMINGSAFE_BCMP
#cmakedefine01 HAVE_TMPFILE
#cmakedefine01 HAVE_TMPNAM
#cmakedefine01 HAVE_TMPNAM_R
#cmakedefine01 HAVE_TOASCII
#cmakedefine01 HAVE_TOLOWER
#cmakedefine01 HAVE_TOUPPER
#cmakedefine01 HAVE_TOWLOWER
#cmakedefine01 HAVE_TOWUPPER
#cmakedefine01 HAVE_TRUNCATE
#cmakedefine01 HAVE_TSS_CREATE
#cmakedefine01 HAVE_TSS_DELETE
#cmakedefine01 HAVE_TSS_DTOR_T
#cmakedefine01 HAVE_TSS_GET
#cmakedefine01 HAVE_TSS_SET
#cmakedefine01 HAVE_TSS_T
#cmakedefine01 HAVE_TTYNAME
#cmakedefine01 HAVE_TTYNAME_R
#cmakedefine01 HAVE___TYPEOF__
#cmakedefine01 HAVE_TYPEOF
#cmakedefine01 HAVE__TZSET
#cmakedefine01 HAVE_TZSET
#cmakedefine01 HAVE_UCHAR_H
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
#cmakedefine01 HAVE_ULIMIT
#cmakedefine01 HAVE_ULIMIT_H
#cmakedefine01 HAVE_UNAME
#cmakedefine01 HAVE_UNION_SIGVAL
#cmakedefine01 HAVE_UNISTD_H
#cmakedefine01 HAVE_UNIXIO_H
#cmakedefine01 HAVE__UNLINK
#cmakedefine01 HAVE_UNLINK
#cmakedefine01 HAVE_UNLINKAT
#cmakedefine01 HAVE__UNLOCK_FILE
#cmakedefine01 HAVE_UNLOCKPT
#cmakedefine01 HAVE_UNSETENV
#cmakedefine01 HAVE_USECONDS_T
#cmakedefine01 HAVE_USLEEP
#cmakedefine01 HAVE_UTIL_H
#cmakedefine01 HAVE_UTIME
#cmakedefine01 HAVE_UTIME_H
#cmakedefine01 HAVE_UTIMENSAT
#cmakedefine01 HAVE_UTMP_H
#cmakedefine01 HAVE_UTMPX_H
#cmakedefine01 HAVE_VA_LIST
#cmakedefine01 HAVE_VASPRINTF
#cmakedefine01 HAVE_VDPRINTF
#cmakedefine01 HAVE_VERR
#cmakedefine01 HAVE_VERRC
#cmakedefine01 HAVE_VERRX
#cmakedefine01 HAVE_VERSIONSORT
#cmakedefine01 HAVE_VFORK
#cmakedefine01 HAVE_VFPRINTF
#cmakedefine01 HAVE_VISIT
#cmakedefine01 HAVE_VPRINTF
#cmakedefine01 HAVE_VSNPRINTF
#cmakedefine01 HAVE_VSPRINTF
#cmakedefine01 HAVE_VWARN
#cmakedefine01 HAVE_VWARNC
#cmakedefine01 HAVE_VWARNX
#cmakedefine01 HAVE_WAITPID
#cmakedefine01 HAVE_WARN
#cmakedefine01 HAVE_WARNC
#cmakedefine01 HAVE_WARNX
#cmakedefine01 HAVE_WCHAR_H
#cmakedefine01 HAVE_WCHAR_T
#cmakedefine01 HAVE_WCPCPY
#cmakedefine01 HAVE_WCPNCPY
#cmakedefine01 HAVE_WCRTOMB
#cmakedefine01 HAVE_WCSCASECMP
#cmakedefine01 HAVE_WCSCAT
#cmakedefine01 HAVE_WCSCHR
#cmakedefine01 HAVE_WCSCMP
#cmakedefine01 HAVE_WCSCPY
#cmakedefine01 HAVE_WCSCSPN
#cmakedefine01 HAVE_WCSDUP
#cmakedefine01 HAVE_WCSLEN
#cmakedefine01 HAVE_WCSNCASECMP
#cmakedefine01 HAVE_WCSNCAT
#cmakedefine01 HAVE_WCSNCMP
#cmakedefine01 HAVE_WCSNCPY
#cmakedefine01 HAVE_WCSNLEN
#cmakedefine01 HAVE_WCSPBRK
#cmakedefine01 HAVE_WCSRTOMBS
#cmakedefine01 HAVE_WCSSPN
#cmakedefine01 HAVE_WCSTOK
#cmakedefine01 HAVE_WCSTOMBS
#cmakedefine01 HAVE_WCSWIDTH
#cmakedefine01 HAVE_WCTOMB
#cmakedefine01 HAVE_WCTYPE
#cmakedefine01 HAVE_WCTYPE_H
#cmakedefine01 HAVE_WCTYPE_T
#cmakedefine01 HAVE_WCWIDTH
#cmakedefine01 HAVE_WINDOWS_H
#cmakedefine01 HAVE_WINNLS_H
#cmakedefine01 HAVE_WINSOCK2_H
#cmakedefine01 HAVE_WINT_T
#cmakedefine01 HAVE_WMEMCHR
#cmakedefine01 HAVE_WMEMCMP
#cmakedefine01 HAVE_WMEMCPY
#cmakedefine01 HAVE_WMEMMOVE
#cmakedefine01 HAVE_WMEMPCPY
#cmakedefine01 HAVE_WMEMSET
#cmakedefine01 HAVE_WORDEXP_H
#cmakedefine01 HAVE_WORDEXP_T
#cmakedefine01 HAVE__WRITE
#cmakedefine01 HAVE_WRITE
#cmakedefine01 HAVE_WS2TCPIP_H
#cmakedefine01 HAVE_XLOCALE_H
#cmakedefine01 HAVE___XPG_STRERROR_R

#cmakedefine01 CALLOC_0_0_RETURNS_NONNULL
#cmakedefine01 FORKPTY_HAS_CONST_PROTOTYPE
#cmakedefine01 FREE_NULL_IS_NOP
#cmakedefine01 GAI_STRERROR_RETURNS_CONST_CHAR
#cmakedefine01 GETCWD_NULL_0_ALLOCATES_MEMORY
#cmakedefine01 IOCTL_HAS_POSIX_PROTOTYPE
#cmakedefine01 MALLOC_0_RETURNS_NONNULL
#cmakedefine01 OPENPTY_HAS_CONST_PROTOTYPE
#cmakedefine01 REALLOC_NULL_0_RETURNS_NONNULL
#cmakedefine01 UNSETENV_HAS_POSIX_PROTOTYPE
#cmakedefine01 WCSTOK_HAS_POSIX_PROTOTYPE

#cmakedefine01 LIBCFUNK_REPLACE_A64L
#cmakedefine01 LIBCFUNK_REPLACE_ABS
#cmakedefine01 LIBCFUNK_REPLACE_ACCEPT
#cmakedefine01 LIBCFUNK_REPLACE_ALPHASORT
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_ADD
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_APPEND
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_COUNT
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_CREATE
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_EXTRACT
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_NEXT
#cmakedefine01 LIBCFUNK_REPLACE_ARGZ_STRINGIFY
#cmakedefine01 LIBCFUNK_REPLACE_ASPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_ATOF
#cmakedefine01 LIBCFUNK_REPLACE_ATOI
#cmakedefine01 LIBCFUNK_REPLACE_ATOL
#cmakedefine01 LIBCFUNK_REPLACE_ATOLL
#cmakedefine01 LIBCFUNK_REPLACE_BCMP
#cmakedefine01 LIBCFUNK_REPLACE_BCOPY
#cmakedefine01 LIBCFUNK_REPLACE_BIND
#cmakedefine01 LIBCFUNK_REPLACE_BSEARCH
#cmakedefine01 LIBCFUNK_REPLACE_BZERO
#cmakedefine01 LIBCFUNK_REPLACE_CALLOC
#cmakedefine01 LIBCFUNK_REPLACE_CEIL
#cmakedefine01 LIBCFUNK_REPLACE_CEILF
#cmakedefine01 LIBCFUNK_REPLACE_CEILL
#cmakedefine01 LIBCFUNK_REPLACE_CHDIR
#cmakedefine01 LIBCFUNK_REPLACE_CLOSEDIR
#cmakedefine01 LIBCFUNK_REPLACE_CONNECT
#cmakedefine01 LIBCFUNK_REPLACE_COPYSIGN
#cmakedefine01 LIBCFUNK_REPLACE_COPYSIGNF
#cmakedefine01 LIBCFUNK_REPLACE_COPYSIGNL
#cmakedefine01 LIBCFUNK_REPLACE_DIR
#cmakedefine01 LIBCFUNK_REPLACE_DIRFD
#cmakedefine01 LIBCFUNK_REPLACE_DIV
#cmakedefine01 LIBCFUNK_REPLACE_DPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_DUP
#cmakedefine01 LIBCFUNK_REPLACE_DUP2
#cmakedefine01 LIBCFUNK_REPLACE_FABS
#cmakedefine01 LIBCFUNK_REPLACE_FABSF
#cmakedefine01 LIBCFUNK_REPLACE_FABSL
#cmakedefine01 LIBCFUNK_REPLACE_FDATASYNC
#cmakedefine01 LIBCFUNK_REPLACE_FDOPENDIR
#cmakedefine01 LIBCFUNK_REPLACE_FFS
#cmakedefine01 LIBCFUNK_REPLACE_FFSL
#cmakedefine01 LIBCFUNK_REPLACE_FFSLL
#cmakedefine01 LIBCFUNK_REPLACE_FILENO
#cmakedefine01 LIBCFUNK_REPLACE_FLOCK
#cmakedefine01 LIBCFUNK_REPLACE_FLOOR
#cmakedefine01 LIBCFUNK_REPLACE_FLOORF
#cmakedefine01 LIBCFUNK_REPLACE_FLOORL
#cmakedefine01 LIBCFUNK_REPLACE_FLS
#cmakedefine01 LIBCFUNK_REPLACE_FLSL
#cmakedefine01 LIBCFUNK_REPLACE_FLSLL
#cmakedefine01 LIBCFUNK_REPLACE_FNMATCH
#cmakedefine01 LIBCFUNK_REPLACE_FORKPTY
#cmakedefine01 LIBCFUNK_REPLACE_FPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_FREE
#cmakedefine01 LIBCFUNK_REPLACE_FSEEK
#cmakedefine01 LIBCFUNK_REPLACE_FSEEKO
#cmakedefine01 LIBCFUNK_REPLACE_FTELL
#cmakedefine01 LIBCFUNK_REPLACE_FTELLO
#cmakedefine01 LIBCFUNK_REPLACE_FTRUNCATE
#cmakedefine01 LIBCFUNK_REPLACE_GAI_STRERROR
#cmakedefine01 LIBCFUNK_REPLACE_GET_CURRENT_DIR_NAME
#cmakedefine01 LIBCFUNK_REPLACE_GETCWD
#cmakedefine01 LIBCFUNK_REPLACE_GETDELIM
#cmakedefine01 LIBCFUNK_REPLACE_GETDTABLESIZE
#cmakedefine01 LIBCFUNK_REPLACE_GETENTROPY
#cmakedefine01 LIBCFUNK_REPLACE_GETENV
#cmakedefine01 LIBCFUNK_REPLACE_GETHOSTNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETLINE
#cmakedefine01 LIBCFUNK_REPLACE_GETOPT
#cmakedefine01 LIBCFUNK_REPLACE_GETOPT_LONG
#cmakedefine01 LIBCFUNK_REPLACE_GETOPT_LONG_ONLY
#cmakedefine01 LIBCFUNK_REPLACE_GETPAGESIZE
#cmakedefine01 LIBCFUNK_REPLACE_GETPEERNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETPID
#cmakedefine01 LIBCFUNK_REPLACE_GETPPID
#cmakedefine01 LIBCFUNK_REPLACE_GETPROGNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETRANDOM
#cmakedefine01 LIBCFUNK_REPLACE_GETSOCKNAME
#cmakedefine01 LIBCFUNK_REPLACE_GETSOCKOPT
#cmakedefine01 LIBCFUNK_REPLACE_GETTIMEOFDAY
#cmakedefine01 LIBCFUNK_REPLACE_GLOB
#cmakedefine01 LIBCFUNK_REPLACE_GLOBFREE
#cmakedefine01 LIBCFUNK_REPLACE_GLOB_PATTERN_P
#cmakedefine01 LIBCFUNK_REPLACE_IMAXABS
#cmakedefine01 LIBCFUNK_REPLACE_IMAXDIV
#cmakedefine01 LIBCFUNK_REPLACE_INDEX
#cmakedefine01 LIBCFUNK_REPLACE_INET_ADDR
#cmakedefine01 LIBCFUNK_REPLACE_INET_ATON
#cmakedefine01 LIBCFUNK_REPLACE_INET_NTOA
#cmakedefine01 LIBCFUNK_REPLACE_INET_NTOP
#cmakedefine01 LIBCFUNK_REPLACE_INET_PTON
#cmakedefine01 LIBCFUNK_REPLACE_INSQUE
#cmakedefine01 LIBCFUNK_REPLACE_IOCTL
#cmakedefine01 LIBCFUNK_REPLACE_ISATTY
#cmakedefine01 LIBCFUNK_REPLACE_L64A
#cmakedefine01 LIBCFUNK_REPLACE_L64A_R
#cmakedefine01 LIBCFUNK_REPLACE_LABS
#cmakedefine01 LIBCFUNK_REPLACE_LDIV
#cmakedefine01 LIBCFUNK_REPLACE_LISTEN
#cmakedefine01 LIBCFUNK_REPLACE_LLABS
#cmakedefine01 LIBCFUNK_REPLACE_LLDIV
#cmakedefine01 LIBCFUNK_REPLACE_LOGIN_TTY
#cmakedefine01 LIBCFUNK_REPLACE_LSEEK
#cmakedefine01 LIBCFUNK_REPLACE_MALLOC
#cmakedefine01 LIBCFUNK_REPLACE_MEMCPY
#cmakedefine01 LIBCFUNK_REPLACE_MEMSET
#cmakedefine01 LIBCFUNK_REPLACE_MKDIR
#cmakedefine01 LIBCFUNK_REPLACE_OPENDIR
#cmakedefine01 LIBCFUNK_REPLACE_OPENPTY
#cmakedefine01 LIBCFUNK_REPLACE_PCLOSE
#cmakedefine01 LIBCFUNK_REPLACE_POPCOUNT
#cmakedefine01 LIBCFUNK_REPLACE_POPCOUNTL
#cmakedefine01 LIBCFUNK_REPLACE_POPCOUNTLL
#cmakedefine01 LIBCFUNK_REPLACE_POPEN
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_DESTROY
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETFLAGS
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETPGROUP
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETSCHEDPARAM
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETSCHEDPOLICY
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETSIGDEFAULT
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_GETSIGMASK
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_INIT
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETFLAGS
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETPGROUP
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETSCHEDPARAM
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETSCHEDPOLICY
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETSIGDEFAULT
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_SETSIGMASK
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNATTR_T
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_ADDOPEN
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_DESTROY
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_INIT
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWN_FILE_ACTIONS_T
#cmakedefine01 LIBCFUNK_REPLACE_POSIX_SPAWNP
#cmakedefine01 LIBCFUNK_REPLACE_PSELECT
#cmakedefine01 LIBCFUNK_REPLACE_PUTENV
#cmakedefine01 LIBCFUNK_REPLACE_QSORT
#cmakedefine01 LIBCFUNK_REPLACE_QSORT_R
#cmakedefine01 LIBCFUNK_REPLACE_RAND
#cmakedefine01 LIBCFUNK_REPLACE_RANDOM
#cmakedefine01 LIBCFUNK_REPLACE_RANDOM_R
#cmakedefine01 LIBCFUNK_REPLACE_READDIR
#cmakedefine01 LIBCFUNK_REPLACE_READDIR_R
#cmakedefine01 LIBCFUNK_REPLACE_REALLOC
#cmakedefine01 LIBCFUNK_REPLACE_RECV
#cmakedefine01 LIBCFUNK_REPLACE_RECVFROM
#cmakedefine01 LIBCFUNK_REPLACE_REMOVE
#cmakedefine01 LIBCFUNK_REPLACE_REMQUE
#cmakedefine01 LIBCFUNK_REPLACE_REWIND
#cmakedefine01 LIBCFUNK_REPLACE_REWINDDIR
#cmakedefine01 LIBCFUNK_REPLACE_RINDEX
#cmakedefine01 LIBCFUNK_REPLACE_RMDIR
#cmakedefine01 LIBCFUNK_REPLACE_SCANDIR
#cmakedefine01 LIBCFUNK_REPLACE_SEEKDIR
#cmakedefine01 LIBCFUNK_REPLACE_SELECT
#cmakedefine01 LIBCFUNK_REPLACE_SEND
#cmakedefine01 LIBCFUNK_REPLACE_SENDTO
#cmakedefine01 LIBCFUNK_REPLACE_SETENV
#cmakedefine01 LIBCFUNK_REPLACE_SETSOCKOPT
#cmakedefine01 LIBCFUNK_REPLACE_SHUTDOWN
#cmakedefine01 LIBCFUNK_REPLACE_SNPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_SOCKET
#cmakedefine01 LIBCFUNK_REPLACE_SPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_STPCPY
#cmakedefine01 LIBCFUNK_REPLACE_STPNCPY
#cmakedefine01 LIBCFUNK_REPLACE_STRCASECMP
#cmakedefine01 LIBCFUNK_REPLACE_STRCAT
#cmakedefine01 LIBCFUNK_REPLACE_STRCHR
#cmakedefine01 LIBCFUNK_REPLACE_STRCPY
#cmakedefine01 LIBCFUNK_REPLACE_STRCSPN
#cmakedefine01 LIBCFUNK_REPLACE_STRDUP
#cmakedefine01 LIBCFUNK_REPLACE_STRERROR_R
#cmakedefine01 LIBCFUNK_REPLACE_STRLEN
#cmakedefine01 LIBCFUNK_REPLACE_STRNCASECMP
#cmakedefine01 LIBCFUNK_REPLACE_STRPBRK
#cmakedefine01 LIBCFUNK_REPLACE_STRRCHR
#cmakedefine01 LIBCFUNK_REPLACE_STRSEP
#cmakedefine01 LIBCFUNK_REPLACE_STRSPN
#cmakedefine01 LIBCFUNK_REPLACE_STRSTR
#cmakedefine01 LIBCFUNK_REPLACE_STRTOIMAX
#cmakedefine01 LIBCFUNK_REPLACE_STRTOK
#cmakedefine01 LIBCFUNK_REPLACE_STRTOK_R
#cmakedefine01 LIBCFUNK_REPLACE_STRTOL
#cmakedefine01 LIBCFUNK_REPLACE_STRTOLL
#cmakedefine01 LIBCFUNK_REPLACE_STRTOUL
#cmakedefine01 LIBCFUNK_REPLACE_STRTOULL
#cmakedefine01 LIBCFUNK_REPLACE_STRTOUMAX
#cmakedefine01 LIBCFUNK_REPLACE_STRUCT_DIRENT
#cmakedefine01 LIBCFUNK_REPLACE_STRVERSCMP
#cmakedefine01 LIBCFUNK_REPLACE_SWAB
#cmakedefine01 LIBCFUNK_REPLACE_TELLDIR
#cmakedefine01 LIBCFUNK_REPLACE_TIMESPEC_GET
#cmakedefine01 LIBCFUNK_REPLACE_ULIMIT
#cmakedefine01 LIBCFUNK_REPLACE_UNSETENV
#cmakedefine01 LIBCFUNK_REPLACE_VASPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_VDPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_VERSIONSORT
#cmakedefine01 LIBCFUNK_REPLACE_VFPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_VPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_VSNPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_VSPRINTF
#cmakedefine01 LIBCFUNK_REPLACE_WCSCSPN
#cmakedefine01 LIBCFUNK_REPLACE_WCSPBRK
#cmakedefine01 LIBCFUNK_REPLACE_WCSSPN
#cmakedefine01 LIBCFUNK_REPLACE_WCSTOK
#cmakedefine01 LIBCFUNK_REPLACE_WMEMSET

/* Build paths and file names which may be needed for tests. */
#cmakedefine LIBCFUNK_LIBRARY_NAME "@LIBCFUNK_LIBRARY_NAME@"
#cmakedefine LIBCFUNK_SOURCE_DIR "@LIBCFUNK_SOURCE_DIR@"
#cmakedefine LIBCFUNK_TEST_SOURCE_DIR "@LIBCFUNK_TEST_SOURCE_DIR@"
#cmakedefine LIBCFUNK_BUILD_DIR "@LIBCFUNK_BUILD_DIR@"
#cmakedefine LIBCFUNK_TEST_BUILD_DIR "@LIBCFUNK_TEST_BUILD_DIR@"
#cmakedefine LIBCFUNK_MODULE_DIR "@LIBCFUNK_MODULE_DIR@"
#cmakedefine LIBCFUNK_CONFIG_DIR "@LIBCFUNK_CONFIG_DIR@"

/* Make sure '__func__' can be used as a string. */
#if !HAVE_C99__FUNC__
#  define __func__ "Function name"
#endif

/* Make sure 'bool', 'true', and 'false' can be used as if the compiler
   was C23. */
#if !HAVE_C23_BOOL
#  include <stdbool.h>
#  ifndef true
#    define true 1
#  elif true != 1
#    undef true
#    define true 1
#  endif
#  ifndef false
#    define false 0
#  elif false != 0
#    undef false
#    define false 0
#  endif
#endif

/* Make sure 'static_assert' could be used as if the compiler was C23. */
#if !HAVE_C23_STATIC_ASSERT
#  if HAVE_ASSERT_H
#    include <assert.h>
#  endif
#  if !defined(static_assert) && HAVE_C11_STATIC_ASSERT
#    define static_assert _Static_assert
#  endif
#else
#  if !HAVE_C11_STATIC_ASSERT && !defined(_Static_assert)
#    define _Static_assert static_assert
#  endif
#endif

/* Make sure '_Noreturn' could be used as if the compiler was C23. */
#if !HAVE_C11__NORETURN
#  if defined(__GNUC__) || defined(__clang__)
#    define _Noreturn __attribute__ ((__noreturn__))
#  else
#    define _Noreturn
#  endif
#endif

/* Make sure that 'nullptr' can be used as if the compiler was C23. */
#if !HAVE_C23_NULLPTR && !defined(nullptr)
#  define nullptr ((void *) 0)
#endif

#endif /* CONFIG_H */
