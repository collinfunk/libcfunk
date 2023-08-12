
include_guard(GLOBAL)

# Includes to check for system information.
include(CheckSymbolExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckTypeSize)
include(CheckCSourceCompiles)

include(${LIBCFUNK_MODULE_DIR}/include-next.cmake)

# Required by system header templates.
if (NOT HAVE_INCLUDE_NEXT_DIRECTIVE)
  message (FATAL_ERROR "Your compiler does not support #include_next.")
endif ()

# Define this so we can check for glibc extensions.
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")
endif ()

