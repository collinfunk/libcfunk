
include_guard(GLOBAL)

libcfunk_check_include_file("sys/random.h" HAVE_SYS_RANDOM_H)
libcfunk_check_include_files("windows.h;bcrypt.h" HAVE_BCRYPT_H)

# Generate the "sys/random.h" header
set(LIBCFUNK_GENERATE_SYS_RANDOM_H TRUE)

set(LIBCFUNK_DECLARE_GETRANDOM 0)
set(LIBCFUNK_DECLARE_GETENTROPY 0)

if (NOT HAVE_SYS_RANDOM_H)
  if (HAVE_WINDOWS_H)
    if (HAVE_BCRYPT_H)
      target_link_libraries(${LIBCFUNK_LIBRARY_NAME} PUBLIC "bcrypt")
    else ()
      message (FATAL_ERROR "Unsupported windows version")
    endif ()
  endif ()
endif ()

