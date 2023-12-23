
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <dirent.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_DIRENT_H "1" CACHE STRING "")

check_include_file("dirent.h" HAVE_DIRENT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SYS_TYPES_H OR HAVE_DIRENT_H)
  set(DIR_SOURCE_HEADER "")
  if (HAVE_SYS_TYPES_H)
    string(APPEND DIR_SOURCE_HEADER "#include <sys/types.h>\n")
  endif ()
  if (HAVE_DIRENT_H)
    list(APPEND CMAKE_EXTRA_INCLUDE_FILES "dirent.h")
    list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
    string(APPEND DIR_SOURCE_HEADER "#include <dirent.h>\n")
  endif ()
  # Check for 'struct dirent' and 'DIR' which may be an opaque type.
  check_type_size("struct dirent" STRUCT_DIRENT)
  check_c_source_compiles("
  ${DIR_SOURCE_HEADER}
  #ifndef NULL
  #  define NULL ((void *) 0)
  #endif
  int
  main (void)
  {
    DIR *dirstream = NULL;
    return dirstream != NULL ? 0 : 0;
  }" HAVE_DIR)
  unset(DIR_SOURCE_HEADER)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dirent-h.cmake)
endif ()

