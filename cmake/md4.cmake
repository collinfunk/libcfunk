
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/explicit-bzero.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/circular-shift.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/bswap.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/openssl.cmake)

check_include_file("openssl/md4.h" HAVE_OPENSSL_MD4_H)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/md4.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/md4.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-md4.cmake)
endif ()

