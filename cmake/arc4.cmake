
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/openssl.cmake)

check_include_file("openssl/rc4.h" HAVE_OPENSSL_RC4_H)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/arc4.c
  $CACHE{LIBCFUNK_SOURCE_DIR}/arc4.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-arc4.cmake)
endif ()

