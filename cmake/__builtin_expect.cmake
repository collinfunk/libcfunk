
include_guard(GLOBAL)

check_include_file("builtins.h" HAVE_BUILTINS_H)

if (HAVE_BUILTINS_H)
  set(BUILTIN_EXPECT_INCLUDES "#include <builtins.h>")
endif ()

check_c_source_compiles("
${BUILTIN_EXPECT_INCLUDES}

int
main (int argc, char **argv)
{
  if (__builtin_expect (argc > 1, 0))
    return 0;
  else
    return 0;
}" HAVE___BUILTIN_EXPECT)

unset(BUILTIN_EXPECT_INCLUDES)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/__builtin_expect.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__builtin_expect.cmake)
endif ()

