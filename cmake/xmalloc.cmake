
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/reallocarray.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.c
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.h
)

