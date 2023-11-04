
include_guard(GLOBAL)

include(FindOpenSSL)

if (OPENSSL_FOUND)
  target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC OpenSSL::Crypto)
else ()
  # If we aren't using OpenSSL setting these here will make
  # check_include_file not run later.
  set(HAVE_OPENSSL_RC4_H "" CACHE STRING "")
  set(HAVE_OPENSSL_MD4_H "" CACHE STRING "")
  set(HAVE_OPENSSL_MD5_H "" CACHE STRING "")
  set(HAVE_OPENSSL_SHA_H "" CACHE STRING "")
endif ()
