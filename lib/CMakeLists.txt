
add_library(cfunk)

target_include_directories(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/
)

target_sources(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.h
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.c
)
