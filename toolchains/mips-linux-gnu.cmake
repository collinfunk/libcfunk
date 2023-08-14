
set(CMAKE_SYSTEM_NAME "Linux")
set(CMAKE_SYSTEM_PROCESSOR "mips")

set(TRIPLE_TARGET "mips-linux-gnu")

set(CMAKE_C_COMPILER "${TRIPLE_TARGET}-gcc")
set(CMAKE_CXX_COMPILER "${TRIPLE_TARGET}-g++")

set(CMAKE_FIND_ROOT_PATH "/usr/mips-linux-gnu")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
