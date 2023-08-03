
add_executable(test-bstree)
add_executable(test-bswap)
add_executable(test-list)
add_executable(test-slist)

target_link_libraries(test-bstree PRIVATE cfunk)
target_link_libraries(test-bswap PRIVATE cfunk)
target_link_libraries(test-list PRIVATE cfunk)
target_link_libraries(test-slist PRIVATE cfunk)

target_sources(test-bstree PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bstree.c
)

target_sources(test-bswap PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bswap.c
)

target_sources(test-list PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-list.c
)

target_sources(test-slist PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-slist.c
)
