cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode
        1-two-sum.cpp
        3-longest-substring-without-repeating-characters.cpp
        20-valid-parentheses.cpp
        100-same-tree.cpp
        102-binary-tree-level-order-traversal.cpp
        104-max-depth-of-binary-tree.cpp
        121-best-time-to-buy-and-sell-stock.cpp
        125-valid-palindrome.cpp
        200-number-of-islands.cpp
        206-reverse-linked-list.cpp
        226-invert-binary-tree.cpp
        242-valid-anagram.cpp
        235-lowest-common-ancestor-of-a-binary-search-tree.cpp
        383-ransom-note.cpp
        424-longest-repeating-character-replacement.cpp
        54-spiral-matrix.cpp
        542-01-matrix.cpp
        733-flood-fill.cpp)

add_executable(49-group-anagrams
        49-group-anagrams.cpp
)

add_executable(53-maximum-subarray
        53-maximum-subarray.cpp
)

add_executable(238-product-of-array-except-self
        238-product-of-array-except-self.cpp
)

add_executable(704-binary-search
        704-binary-search.cpp
)