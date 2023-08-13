
include_guard(GLOBAL)

target_sources(${LIBCFUNK_LIBRARY_NAME} PRIVATE
  ${LIBCFUNK_SOURCE_DIR}/bstree.h
  ${LIBCFUNK_SOURCE_DIR}/bstree.c
)

if (LIBCFUNK_BUILD_TESTS)
  include(${LIBCFUNK_MODULE_DIR}/test-bstree.cmake)
endif ()
