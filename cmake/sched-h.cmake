
include_guard(GLOBAL)

# Generate <sched.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SCHED_H "1" CACHE INTERNAL "")

check_include_file("sched.h" HAVE_SCHED_H)

set(LIBCFUNK_DECLARE_SCHED_YIELD "0" CACHE INTERNAL "")
