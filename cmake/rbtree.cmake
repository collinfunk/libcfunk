
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/rbtree.c
  ${LIBCFUNK_SOURCE_DIR}/rbtree.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-rbtree.cmake)
endif ()
