
add_library(cfunk)

target_include_directories(cfunk PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/
  ${CMAKE_CURRENT_BINARY_DIR}/
)

list(APPEND CMAKE_REQUIRED_DEFINITIONS "-D_GNU_SOURCE")

include(CheckSymbolExists)

# string.h
check_symbol_exists(strchrnul "string.h" HAVE_STRCHRNUL)
check_symbol_exists(strmode "string.h" HAVE_STRMODE)
check_symbol_exists(explicit_bzero "string.h" HAVE_EXPLICIT_BZERO)
check_symbol_exists(memset_explicit "string.h" HAVE_MEMSET_EXPLICIT)
check_symbol_exists(SecureZeroMemory "windows.h" HAVE_SECUREZEROMEMORY)
check_symbol_exists(strdup "string.h" HAVE_STRDUP)
check_symbol_exists(strndup "string.h" HAVE_STRNDUP)

# strings.h
check_symbol_exists(ffs "strings.h" HAVE_FFS)
check_symbol_exists(ffsl "strings.h" HAVE_FFSL)
check_symbol_exists(ffsll "strings.h" HAVE_FFSLL)

# stdlib.h
check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)

configure_file(
  ${CMAKE_CURRENT_LIST_DIR}/config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

target_sources(cfunk PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/bstree.h
  ${CMAKE_CURRENT_LIST_DIR}/bswap.h
  ${CMAKE_CURRENT_LIST_DIR}/circular-shift.h
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.h
  ${CMAKE_CURRENT_LIST_DIR}/list.h
  ${CMAKE_CURRENT_LIST_DIR}/read-full.h
  ${CMAKE_CURRENT_LIST_DIR}/read-nointr.h
  ${CMAKE_CURRENT_LIST_DIR}/sha256.h  
  ${CMAKE_CURRENT_LIST_DIR}/slist.h
  ${CMAKE_CURRENT_LIST_DIR}/write-full.h
  ${CMAKE_CURRENT_LIST_DIR}/write-nointr.h
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.h
  ${CMAKE_CURRENT_LIST_DIR}/bstree.c
  ${CMAKE_CURRENT_LIST_DIR}/hash-map.c
  ${CMAKE_CURRENT_LIST_DIR}/list.c
  ${CMAKE_CURRENT_LIST_DIR}/read-full.c
  ${CMAKE_CURRENT_LIST_DIR}/read-nointr.c
  ${CMAKE_CURRENT_LIST_DIR}/sha256.c
  ${CMAKE_CURRENT_LIST_DIR}/slist.c
  ${CMAKE_CURRENT_LIST_DIR}/write-full.c
  ${CMAKE_CURRENT_LIST_DIR}/write-nointr.c
  ${CMAKE_CURRENT_LIST_DIR}/xmalloc.c
)

if (NOT HAVE_STRCHRNUL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strchrnul.c
  )
endif ()

if (NOT HAVE_STRMODE)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strmode.c
  )
endif ()

if (NOT HAVE_EXPLICIT_BZERO)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/explicit-bzero.c
  )
endif ()

if (NOT HAVE_STRDUP)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strdup.c
  )
endif ()

if (NOT HAVE_STRNDUP)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/strndup.c
  )
endif ()

if (NOT HAVE_FFS)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffs.c
  )
endif ()

if (NOT HAVE_FFSL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffsl.c
  )
endif ()

if (NOT HAVE_FFSLL)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ffsll.c
  )
endif ()

if (NOT HAVE_REALLOCARRAY)
  target_sources(cfunk PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/reallocarray.c
  )
endif ()
