
include_guard(GLOBAL)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/attributes.h
)

if (LIBCFUNK_ENABLE_TESTS)
endif ()

