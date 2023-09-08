# Convert variables to 0/1's that are suitable for use in
# configuration files using the c preprocessor.
function (bool_to_int str_var bool_var)
  if (${bool_var})
    set(${str_var} "1" PARENT_SCOPE)
  else ()
    set(${str_var} "0" PARENT_SCOPE)
  endif ()
endfunction ()

# Generate a header which uses @VAR@ substitution.
function (substitute_header template_file output_file)
  cmake_path(GET output_file FILENAME basename)
  cmake_path(GET output_file PARENT_PATH dest_dir)
  file(MAKE_DIRECTORY "${dest_dir}")
  add_custom_command(
    OUTPUT "${output_file}"
    COMMAND "$CACHE{PERL_PROGRAM}"
    "$CACHE{LIBCFUNK_SCRIPT_DIR}/substitute-header.pl"
    "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    "${template_file}"
    "${output_file}"
    DEPENDS "${CMAKE_BINARY_DIR}/CMakeCache.txt"
    COMMENT "Generating `${output_file}'."
    VERBATIM
  )
  target_sources($CACHE{LIBCFUNK_LIBRARY_NAME} PRIVATE
    "${output_file}")
endfunction ()

add_custom_command(
  OUTPUT "$CACHE{LIBCFUNK_CONFIG_DIR}/config.h"
  COMMAND "$CACHE{PERL_PROGRAM}"
  "$CACHE{LIBCFUNK_SCRIPT_DIR}/cmake-autoheader.pl"
  "${CMAKE_BINARY_DIR}/CMakeCache.txt"
  "$CACHE{LIBCFUNK_CONFIG_DIR}/config.h"
  DEPENDS "${CMAKE_BINARY_DIR}/CMakeCache.txt"
  COMMENT "Generating `$CACHE{LIBCFUNK_CONFIG_DIR}/config.h'."
  VERBATIM
)

target_sources($CACHE{LIBCFUNK_LIBRARY_NAME} PRIVATE
  "$CACHE{LIBCFUNK_CONFIG_DIR}/config.h")

if ($CACHE{LIBCFUNK_GENERATE_ALLOCA_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/alloca.h.in
    ${LIBCFUNK_CONFIG_DIR}/alloca.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_CTYPE_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/ctype.h.in
    ${LIBCFUNK_CONFIG_DIR}/ctype.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERR_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/err.h.in
    ${LIBCFUNK_CONFIG_DIR}/err.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_ERROR_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/error.h.in
    ${LIBCFUNK_CONFIG_DIR}/error.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_INTTYPES_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/inttypes.h.in
    ${LIBCFUNK_CONFIG_DIR}/inttypes.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_MALLOC_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/malloc.h.in
    ${LIBCFUNK_CONFIG_DIR}/malloc.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDINT_H})

  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdint.h.in
    ${LIBCFUNK_CONFIG_DIR}/stdint.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDIO_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdio.h.in
    ${LIBCFUNK_CONFIG_DIR}/stdio.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STDLIB_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdlib.h.in
    ${LIBCFUNK_CONFIG_DIR}/stdlib.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRING_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/string.h.in
    ${LIBCFUNK_CONFIG_DIR}/string.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_STRINGS_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/strings.h.in
    ${LIBCFUNK_CONFIG_DIR}/strings.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_RANDOM_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/random.h.in
    ${LIBCFUNK_CONFIG_DIR}/sys/random.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_SYS_TIME_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/time.h.in
    ${LIBCFUNK_CONFIG_DIR}/sys/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_TIME_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/time.h.in
    ${LIBCFUNK_CONFIG_DIR}/time.h
  )
endif ()

if ($CACHE{LIBCFUNK_GENERATE_UNISTD_H})
  substitute_header(
    ${LIBCFUNK_SOURCE_DIR}/compat/unistd.h.in
    ${LIBCFUNK_CONFIG_DIR}/unistd.h
  )
endif ()
