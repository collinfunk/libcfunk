
add_library(cfunk)

target_include_directories(cfunk PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/
)

target_sources(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/bstree.h
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.h
  ${CMAKE_CURRENT_LIST_DIR}/list.h
  ${CMAKE_CURRENT_LIST_DIR}/slist.h
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.h
  ${CMAKE_CURRENT_LIST_DIR}/bstree.c
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.c
  ${CMAKE_CURRENT_LIST_DIR}/list.c
  ${CMAKE_CURRENT_LIST_DIR}/slist.c
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.c
)
