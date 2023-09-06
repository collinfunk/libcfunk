
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/write-nointr.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/write-full.c
  ${LIBCFUNK_SOURCE_DIR}/write-full.h
)
