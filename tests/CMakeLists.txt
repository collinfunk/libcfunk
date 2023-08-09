
add_executable(test-bstree)
add_executable(test-bswap)
add_executable(test-circular-shift)
add_executable(test-ffs)
add_executable(test-fls)
add_executable(test-getdelim)
add_executable(test-hash-map)
add_executable(test-list)
add_executable(test-md4)
add_executable(test-md5)
add_executable(test-popcount)
add_executable(test-rbtree)
add_executable(test-read-write-full)
add_executable(test-sha224)
add_executable(test-sha256)
add_executable(test-slist)
add_executable(test-splay-tree)
add_executable(test-strmode)

target_link_libraries(test-bstree PRIVATE cfunk)
target_link_libraries(test-bswap PRIVATE cfunk)
target_link_libraries(test-circular-shift PRIVATE cfunk)
target_link_libraries(test-ffs PRIVATE cfunk)
target_link_libraries(test-fls PRIVATE cfunk)
target_link_libraries(test-getdelim PRIVATE cfunk)
target_link_libraries(test-hash-map PRIVATE cfunk)
target_link_libraries(test-list PRIVATE cfunk)
target_link_libraries(test-md4 PRIVATE cfunk)
target_link_libraries(test-md5 PRIVATE cfunk)
target_link_libraries(test-popcount PRIVATE cfunk)
target_link_libraries(test-rbtree PRIVATE cfunk)
target_link_libraries(test-read-write-full PRIVATE cfunk)
target_link_libraries(test-sha224 PRIVATE cfunk) 
target_link_libraries(test-sha256 PRIVATE cfunk)
target_link_libraries(test-slist PRIVATE cfunk)
target_link_libraries(test-splay-tree PRIVATE cfunk)
target_link_libraries(test-strmode PRIVATE cfunk)

target_sources(test-bstree PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bstree.c
)

target_sources(test-bswap PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-bswap.c
)

target_sources(test-circular-shift PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-circular-shift.c
)

target_sources(test-fls PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-fls.c
)

target_sources(test-ffs PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-ffs.c
)

target_sources(test-getdelim PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-getdelim.c
)

target_sources(test-hash-map PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-hash-map.c
)

target_sources(test-list PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-list.c
)

target_sources(test-md4 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-md4.c
)

target_sources(test-md5 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-md5.c
)

target_sources(test-popcount PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-popcount.c
)

target_sources(test-rbtree PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-rbtree.c
)

target_sources(test-read-write-full PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-read-write-full.c
)

target_sources(test-sha224 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-sha224.c
)

target_sources(test-sha256 PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-sha256.c
)

target_sources(test-slist PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-slist.c
)

target_sources(test-splay-tree PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-splay-tree.c
)

target_sources(test-strmode PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/test-strmode.c
)
