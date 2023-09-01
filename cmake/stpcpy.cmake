
include_guard(GLOBAL)

include(${LIBCFUNK_MODULE_DIR}/string.cmake)

libcfunk_check_symbol_exists(stpcpy "string.h" HAVE_STPCPY)

set(LIBCFUNK_DECLARE_STPCPY 1)

if (NOT HAVE_STPCPY)
    libcfunk_add_sources("stpcpy.c")
endif ()

