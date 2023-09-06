
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/write-nointr.c
  ${LIBCFUNK_SOURCE_DIR}/write-nointr.h
)
