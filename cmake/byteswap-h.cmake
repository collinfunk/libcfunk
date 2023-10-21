
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Check for <byteswap.h>
check_include_file("byteswap.h" HAVE_BYTESWAP_H)

check_include_file("libkern/OSByteOrder.h" HAVE_LIBKERN_OSBYTEORDER_H)
check_include_file("sys/endian.h" HAVE_SYS_ENDIAN_H)
check_include_file("stdlib.h" HAVE_STDLIB_H)
check_include_file("sys/byteorder.h" HAVE_SYS_BYTEORDER_H)

# Make sure we have bswap_16, bswap_32, and bswap_64.
if (HAVE_BYTESWAP_H)
  check_symbol_exists("bswap_16" "byteswap.h" HAVE_BSWAP_16)
  check_symbol_exists("bswap_32" "byteswap.h" HAVE_BSWAP_32)
  check_symbol_exists("bswap_64" "byteswap.h" HAVE_BSWAP_64)
else ()
  set(HAVE_BSWAP_16 "" CACHE INTERNAL "")
  set(HAVE_BSWAP_32 "" CACHE INTERNAL "")
  set(HAVE_BSWAP_64 "" CACHE INTERNAL "")
endif ()

if (HAVE_LIBKERN_OSBYTEORDER_H)
  check_symbol_exists("OSSwapInt16" "libkern/OSByteOrder.h" HAVE_OSSWAPINT16)
  check_symbol_exists("OSSwapInt32" "libkern/OSByteOrder.h" HAVE_OSSWAPINT32)
  check_symbol_exists("OSSwapInt64" "libkern/OSByteOrder.h" HAVE_OSSWAPINT64)
else ()
  set(HAVE_OSSWAPINT16 "" CACHE INTERNAL "")
  set(HAVE_OSSWAPINT32 "" CACHE INTERNAL "")
  set(HAVE_OSSWAPINT64 "" CACHE INTERNAL "")
endif ()

if (HAVE_SYS_ENDIAN_H)
  check_symbol_exists("bswap16" "sys/endian.h" HAVE_BSWAP16)
  check_symbol_exists("bswap32" "sys/endian.h" HAVE_BSWAP32)
  check_symbol_exists("bswap64" "sys/endian.h" HAVE_BSWAP64)
  check_symbol_exists("swap16" "sys/endian.h" HAVE_SWAP16)
  check_symbol_exists("swap32" "sys/endian.h" HAVE_SWAP32)
  check_symbol_exists("swap64" "sys/endian.h" HAVE_SWAP64)
else ()
  set(HAVE_BSWAP16 "" CACHE INTERNAL "")
  set(HAVE_BSWAP32 "" CACHE INTERNAL "")
  set(HAVE_BSWAP64 "" CACHE INTERNAL "")
  set(HAVE_SWAP16 "" CACHE INTERNAL "")
  set(HAVE_SWAP32 "" CACHE INTERNAL "")
  set(HAVE_SWAP64 "" CACHE INTERNAL "")
endif ()

if (HAVE_STDLIB_H)
  check_symbol_exists("_byteswap_ushort" "stdlib.h" HAVE__BYTESWAP_USHORT)
  check_symbol_exists("_byteswap_ulong" "stdlib.h" HAVE__BYTESWAP_ULONG)
  check_symbol_exists("_byteswap_uint64" "stdlib.h" HAVE__BYTESWAP_UINT64)
else ()
  set(HAVE__BYTESWAP_USHORT "" CACHE INTERNAL "")
  set(HAVE__BYTESWAP_ULONG "" CACHE INTERNAL "")
  set(HAVE__BYTESWAP_UINT64 "" CACHE INTERNAL "")
endif ()

# Only generate <byteswap.h> if it is needed.
if (HAVE_BYTESWAP_H AND HAVE_BSWAP_16 AND HAVE_BSWAP_32 AND HAVE_BSWAP_64)
  set(LIBCFUNK_GENERATE_BYTESWAP_H "0" CACHE INTERNAL "")
else ()
  set(LIBCFUNK_GENERATE_BYTESWAP_H "1" CACHE INTERNAL "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-byteswap-h.cmake)
endif ()

