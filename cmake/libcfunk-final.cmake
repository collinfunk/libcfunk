
include_guard(GLOBAL)

configure_file(
  ${LIBCFUNK_SOURCE_DIR}/config.h.in
  ${LIBCFUNK_BUILD_DIR}/config.h
)

if (LIBCFUNK_GENERATE_SYS_RANDOM_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/random.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/sys/random.h
  )
endif ()

if (LIBCFUNK_GENERATE_STRING_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/string.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/string.h
  )
endif ()

if (LIBCFUNK_GENERATE_STRINGS_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/strings.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/strings.h
  )
endif ()

if (LIBCFUNK_GENERATE_STDINT_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdint.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/stdint.h
  )
endif ()

if (LIBCFUNK_GENERATE_STDLIB_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdlib.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/stdlib.h
  )
endif ()

if (LIBCFUNK_GENERATE_STDIO_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/stdio.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/stdio.h
  )
endif ()

if (LIBCFUNK_GENERATE_INTTYPES_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/inttypes.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/inttypes.h
  )
endif ()

if (LIBCFUNK_GENERATE_TIME_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/time.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/time.h
  )
endif ()

if (LIBCFUNK_GENERATE_SYS_TIME_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/sys/time.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/sys/time.h
  )
endif ()

if (LIBCFUNK_GENERATE_CTYPE_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/ctype.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/ctype.h
  )
endif ()

if (LIBCFUNK_GENERATE_UNISTD_H)
  configure_file(
    ${LIBCFUNK_SOURCE_DIR}/compat/unistd.h.in
    ${LIBCFUNK_BUILD_DIR}/compat/unistd.h
  )
endif ()

