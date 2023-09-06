
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/base32.c
  ${LIBCFUNK_SOURCE_DIR}/base32.h
)
