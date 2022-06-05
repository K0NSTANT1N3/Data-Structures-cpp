cmake_minimum_required(VERSION 3.21)
project(Data-Structures-cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data-Structures-cpp
        binary-search-tree/BST.cpp binary-search-tree/BST.h
        buying-cell-towers/BuyingCellTowers.cpp buying-cell-towers/BuyingCellTowers.h
        calculator/Calculator.cpp calculator/Calculator.h
        linked-queue/LinkedQueue.cpp linked-queue/LinkedQueue.h
        permutation-combinations-subsets/PCS.cpp permutation-combinations-subsets/PCS.h
        slow-stack-with-pointer-arrays/MyStack.cpp slow-stack-with-pointer-arrays/MyStack.h
        two-stack-queue/TwoStackQueue.cpp two-stack-queue/TwoStackQueue.h
        Main.cpp)
