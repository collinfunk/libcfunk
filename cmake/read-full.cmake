
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/read-nointr.cmake)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/read-full.c
  ${LIBCFUNK_SOURCE_DIR}/read-full.h
)
