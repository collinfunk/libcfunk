
add_executable(test-bstree)
add_executable(test-bswap)
add_executable(test-circular-shift)
add_executable(test-hash-map)
add_executable(test-list)
add_executable(test-read-write-full)
add_executable(test-slist)

target_link_libraries(test-bstree PRIVATE cfunk)
target_link_libraries(test-bswap PRIVATE cfunk)
target_link_libraries(test-circular-shift PRIVATE cfunk)
target_link_libraries(test-hash-map PRIVATE cfunk)
target_link_libraries(test-list PRIVATE cfunk)
target_link_libraries(test-read-write-full PRIVATE cfunk)
target_link_libraries(test-slist PRIVATE cfunk)

target_sources(test-bstree PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bstree.c
)

target_sources(test-bswap PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bswap.c
)

target_sources(test-circular-shift PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-circular-shift.c
)

target_sources(test-hash-map PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-hash-map.c
)

target_sources(test-list PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-list.c
)

target_sources(test-read-write-full PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-read-write-full.c
)

target_sources(test-slist PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-slist.c
)
