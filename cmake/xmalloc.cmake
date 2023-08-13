
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/strdup.cmake)
include(${LIBCFUNK_MODULE_DIR}/strndup.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.h
  ${LIBCFUNK_SOURCE_DIR}/xmalloc.c
)

