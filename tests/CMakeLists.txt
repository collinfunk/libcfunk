
add_executable(test-list)
add_executable(test-slist)

target_link_libraries(test-list PRIVATE cfunk)
target_link_libraries(test-slist PRIVATE cfunk)

target_sources(test-list PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-list.c
)

target_sources(test-slist PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-slist.c
)
