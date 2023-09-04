
add_library(cfunk)

target_include_directories("cfunk" PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_BINARY_DIR})

target_sources(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/bstree.c
  ${CMAKE_CURRENT_LIST_DIR}/bstree.h
  ${CMAKE_CURRENT_LIST_DIR}/cpu-count.c
  ${CMAKE_CURRENT_LIST_DIR}/cpu-count.h
  ${CMAKE_CURRENT_LIST_DIR}/filename.c
  ${CMAKE_CURRENT_LIST_DIR}/filename.h
  ${CMAKE_CURRENT_LIST_DIR}/list.c
  ${CMAKE_CURRENT_LIST_DIR}/list.h
  ${CMAKE_CURRENT_LIST_DIR}/physical-memory.c
  ${CMAKE_CURRENT_LIST_DIR}/physical-memory.h
  ${CMAKE_CURRENT_LIST_DIR}/program-name.c
  ${CMAKE_CURRENT_LIST_DIR}/program-name.h
  ${CMAKE_CURRENT_LIST_DIR}/rbtree.c
  ${CMAKE_CURRENT_LIST_DIR}/rbtree.h
  ${CMAKE_CURRENT_LIST_DIR}/slist.c
  ${CMAKE_CURRENT_LIST_DIR}/slist.h
  ${CMAKE_CURRENT_LIST_DIR}/splay-tree.c
  ${CMAKE_CURRENT_LIST_DIR}/splay-tree.h
)
