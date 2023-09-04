
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(libcfunk LANGUAGES C)

include(CheckVariableExists)
include(CheckFunctionExists)
include(CheckStructHasMember)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(CheckCSourceCompiles)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
endif ()

# Options
option(BUILD_SHARED_LIBS "Build shared libraries." OFF)
option(BUILD_TESTS "Build test executables." ON)

# Macro to check for headers. Helps deal with some headers that depend
# on others.
set(CHECKED_HEADERS "")
macro (libcfunk_check_header header var)
  check_include_files("${CHECKED_HEADERS};${header}" ${var})
  if (${var})
    set(CHECKED_HEADERS "${CHECKED_HEADERS};${header}")
    set(${var} 1)
  else ()
    set(${var} 0)
  endif ()
endmacro ()

# Check these headers first so most types are defined.
libcfunk_check_header("sys/types.h" HAVE_SYS_TYPES_H)
libcfunk_check_header("stddef.h" HAVE_STDDEF_H)
libcfunk_check_header("stdint.h" HAVE_STDINT_H)
libcfunk_check_header("inttypes.h" HAVE_INTTYPES_H)

# Headers
libcfunk_check_header("aio.h" HAVE_AIO_H)
libcfunk_check_header("arpa/inet.h" HAVE_ARPA_INET_H)
libcfunk_check_header("assert.h" HAVE_ASSERT_H)
libcfunk_check_header("complex.h" HAVE_COMPLEX_H)
libcfunk_check_header("cpio.h" HAVE_CPIO_H)
libcfunk_check_header("ctype.h" HAVE_CTYPE_H)
libcfunk_check_header("dirent.h" HAVE_DIRENT_H)
libcfunk_check_header("dlfcn.h" HAVE_DLFCN_H)
libcfunk_check_header("err.h" HAVE_ERR_H)
libcfunk_check_header("errno.h" HAVE_ERRNO_H)
libcfunk_check_header("error.h" HAVE_ERROR_H)
libcfunk_check_header("fcntl.h" HAVE_FCNTL_H)
libcfunk_check_header("fenv.h" HAVE_FENV_H)
libcfunk_check_header("float.h" HAVE_FLOAT_H)
libcfunk_check_header("fmtmsg.h" HAVE_FMTMSG_H)
libcfunk_check_header("fnmatch.h" HAVE_FNMATCH_H)
libcfunk_check_header("ftw.h" HAVE_FTW_H)
libcfunk_check_header("glob.h" HAVE_GLOB_H)
libcfunk_check_header("grp.h" HAVE_GRP_H)
libcfunk_check_header("iconv.h" HAVE_ICONV_H)
libcfunk_check_header("iso646.h" HAVE_ISO646_H)
libcfunk_check_header("langinfo.h" HAVE_LANGINFO_H)
libcfunk_check_header("libgen.h" HAVE_LIBGEN_H)
libcfunk_check_header("limits.h" HAVE_LIMITS_H)
libcfunk_check_header("locale.h" HAVE_LOCALE_H)
libcfunk_check_header("math.h" HAVE_MATH_H)
libcfunk_check_header("monetary.h" HAVE_MONETARY_H)
libcfunk_check_header("mqueue.h" HAVE_MQUEUE_H)
libcfunk_check_header("ndbm.h" HAVE_NDBM_H)
libcfunk_check_header("netdb.h" HAVE_NETDB_H)
libcfunk_check_header("net/if.h" HAVE_NET_IF_H)
libcfunk_check_header("netinet/in.h" HAVE_NETINET_IN_H)
libcfunk_check_header("netinet/tcp.h" HAVE_NETINET_TCP_H)
libcfunk_check_header("nl_types.h" HAVE_NL_TYPES_H)
libcfunk_check_header("poll.h" HAVE_POLL_H)
libcfunk_check_header("pthread.h" HAVE_PTHREAD_H)
libcfunk_check_header("pwd.h" HAVE_PWD_H)
libcfunk_check_header("regex.h" HAVE_REGEX_H)
libcfunk_check_header("sched.h" HAVE_SCHED_H)
libcfunk_check_header("search.h" HAVE_SEARCH_H)
libcfunk_check_header("semaphore.h" HAVE_SEMAPHORE_H)
libcfunk_check_header("setjmp.h" HAVE_SETJMP_H)
libcfunk_check_header("signal.h" HAVE_SIGNAL_H)
libcfunk_check_header("spawn.h" HAVE_SPAWN_H)
libcfunk_check_header("stdarg.h" HAVE_STDARG_H)
libcfunk_check_header("stdbool.h" HAVE_STDBOOL_H)
libcfunk_check_header("stdio.h" HAVE_STDIO_H)
libcfunk_check_header("stdlib.h" HAVE_STDLIB_H)
libcfunk_check_header("string.h" HAVE_STRING_H)
libcfunk_check_header("strings.h" HAVE_STRINGS_H)
libcfunk_check_header("stropts.h" HAVE_STROPTS_H)
libcfunk_check_header("sys/cdefs.h" HAVE_SYS_CDEFS_H)
libcfunk_check_header("sys/ioctl.h" HAVE_SYS_IOCTL_H)
libcfunk_check_header("sys/sysctl.h" HAVE_SYS_SYSCTL_H)
libcfunk_check_header("sys/ipc.h" HAVE_SYS_IPC_H)
libcfunk_check_header("syslog.h" HAVE_SYSLOG_H)
libcfunk_check_header("sys/mman.h" HAVE_SYS_MMAN_H)
libcfunk_check_header("sys/msg.h" HAVE_SYS_MSG_H)
libcfunk_check_header("sys/param.h" HAVE_SYS_PARAM_H)
libcfunk_check_header("sys/resource.h" HAVE_SYS_RESOURCE_H)
libcfunk_check_header("sys/select.h" HAVE_SYS_SELECT_H)
libcfunk_check_header("sys/sem.h" HAVE_SYS_SEM_H)
libcfunk_check_header("sys/shm.h" HAVE_SYS_SHM_H)
libcfunk_check_header("sys/socket.h" HAVE_SYS_SOCKET_H)
libcfunk_check_header("sys/stat.h" HAVE_SYS_STAT_H)
libcfunk_check_header("sys/statvfs.h" HAVE_SYS_STATVFS_H)
libcfunk_check_header("sys/time.h" HAVE_SYS_TIME_H)
libcfunk_check_header("sys/times.h" HAVE_SYS_TIMES_H)
libcfunk_check_header("sys/uio.h" HAVE_SYS_UIO_H)
libcfunk_check_header("sys/un.h" HAVE_SYS_UN_H)
libcfunk_check_header("sys/utsname.h" HAVE_SYS_UTSNAME_H)
libcfunk_check_header("sys/wait.h" HAVE_SYS_WAIT_H)
libcfunk_check_header("tar.h" HAVE_TAR_H)
libcfunk_check_header("termios.h" HAVE_TERMIOS_H)
libcfunk_check_header("tgmath.h" HAVE_TGMATH_H)
libcfunk_check_header("time.h" HAVE_TIME_H)
libcfunk_check_header("trace.h" HAVE_TRACE_H)
libcfunk_check_header("ulimit.h" HAVE_ULIMIT_H)
libcfunk_check_header("unistd.h" HAVE_UNISTD_H)
libcfunk_check_header("utime.h" HAVE_UTIME_H)
libcfunk_check_header("utmpx.h" HAVE_UTMPX_H)
libcfunk_check_header("wchar.h" HAVE_WCHAR_H)
libcfunk_check_header("wctype.h" HAVE_WCTYPE_H)
libcfunk_check_header("wordexp.h" HAVE_WORDEXP_H)

# Check headers that depend on windows.h
libcfunk_check_header("windows.h" HAVE_WINDOWS_H)
libcfunk_check_header("bcrypt.h" HAVE_BCRYPT_H)
libcfunk_check_header("sysinfoapi.h" HAVE_SYSINFOAPI_H)

# Functions
check_function_exists("clock_gettime" HAVE_CLOCK_GETTIME)
check_function_exists("clock_settime" HAVE_CLOCK_SETTIME)
check_function_exists("errc" HAVE_ERRC)
check_function_exists("err" HAVE_ERR)
check_function_exists("error_at_line" HAVE_ERROR_AT_LINE)
check_function_exists("error" HAVE_ERROR)
check_function_exists("errx" HAVE_ERRX)
check_function_exists("explicit_bzero" HAVE_EXPLICIT_BZERO)
check_function_exists("getegid" HAVE_GETEGID)
check_function_exists("getenv" HAVE_GETENV)
check_function_exists("geteuid" HAVE_GETEUID)
check_function_exists("getexecname" HAVE_GETEXECNAME)
check_function_exists("getgid" HAVE_GETGID)
check_function_exists("getprogname" HAVE_GETPROGNAME)
check_function_exists("gettimeofday" HAVE_GETTIMEOFDAY)
check_function_exists("getuid" HAVE_GETUID)
check_function_exists("issetugid" HAVE_ISSETUGID)
check_function_exists("reallocarray" HAVE_REALLOCARRAY)
check_function_exists("secure_getenv" HAVE_SECURE_GETENV)
check_function_exists("setprogname" HAVE_SETPROGNAME)
check_function_exists("settimeofday" HAVE_SETTIMEOFDAY)
check_function_exists("verrc" HAVE_VERRC)
check_function_exists("verr" HAVE_VERR)
check_function_exists("verrx" HAVE_VERRX)
check_function_exists("vwarnc" HAVE_VWARNC)
check_function_exists("vwarn" HAVE_VWANR)
check_function_exists("vwarnx" HAVE_VWARNX)
check_function_exists("warnc" HAVE_WARNC)
check_function_exists("warn" HAVE_WARN)
check_function_exists("warnx" HAVE_WARNX)

# Variables
check_variable_exists("__argc" HAVE___ARGC)
check_variable_exists("__argv" HAVE___ARGV)
check_variable_exists("error_message_count" HAVE_ERROR_MESSAGE_COUNT)
check_variable_exists("error_one_per_line" HAVE_ERROR_ONE_PER_LINE)
check_variable_exists("error_print_progname" HAVE_ERROR_PRINT_PROGNAME)
check_variable_exists("__progname" HAVE___PROGNAME)
check_variable_exists("program_invocation_name" HAVE_PROGRAM_INVOCATION_NAME)
check_variable_exists("program_invocation_short_name" HAVE_PROGRAM_INVOCATION_SHORT_NAME)

# Signed integer types.
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

# Unsigned integer types.
check_type_size("unsigned short" SIZEOF_UNSIGNED_SHORT)
check_type_size("unsigned int" SIZEOF_UNSIGNED_INT)
check_type_size("unsigned long" SIZEOF_UNSIGNED_LONG)
check_type_size("unsigned long long" SIZEOF_UNSIGNED_LONG_LONG)

# Fixed width signed integer types.
check_type_size("int8_t" INT8_T)
check_type_size("int16_t" INT16_T)
check_type_size("int32_t" INT32_T)
check_type_size("int64_t" INT64_T)

# Fixed width unsigned integer types.
check_type_size("uint8_t" UINT8_T)
check_type_size("uint16_t" UINT16_T)
check_type_size("uint32_t" UINT32_T)
check_type_size("uint64_t" UINT64_T)

# Maximum width integer types.
check_type_size("intmax_t" INTMAX_T)
check_type_size("uintmax_t" UINTMAX_T)

# Integer types capable containing pointers.
check_type_size("intptr_t" INTPTR_T)
check_type_size("uintptr_t" UINTPTR_T)

# Integer type used for pointer arithmetic.
check_type_size("ptrdiff_t" PTRDIFF_T)

# Check for time members in struct stat.
check_struct_has_member("struct stat" st_atim "sys/types.h;sys/time.h;time.h;sys/stat.h" HAVE_STRUCT_STAT_ST_ATIM)
check_struct_has_member("struct stat" st_mtim "sys/types.h;sys/time.h;time.h;sys/stat.h" HAVE_STRUCT_STAT_ST_CTIM)
check_struct_has_member("struct stat" st_ctim "sys/types.h;sys/time.h;time.h;sys/stat.h" HAVE_STRUCT_STAT_ST_MTIM)
check_c_source_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_atim = tspec;
  st.st_atim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC)
check_c_source_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_ctim = tspec;
  st.st_ctim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC)
check_c_source_compiles("
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

int
main (int argc, char **argv)
{
  struct stat st;
  struct timespec tspec;
  long int nanoseconds;
  st.st_mtim = tspec;
  st.st_mtim.tv_nsec = nanoseconds;
  return 0;
}" HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_BINARY_DIR}/config.h)

add_subdirectory(lib)

if (BUILD_TESTS)
  add_subdirectory(tests)
endif ()
