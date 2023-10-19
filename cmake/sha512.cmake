
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/circular-shift.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/bswap.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/openssl.cmake)

check_include_file("openssl/sha.h" HAVE_OPENSSL_SHA_H)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/sha512.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/sha512.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sha384.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sha512.cmake)
endif ()
