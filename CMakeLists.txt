cmake_minimum_required(VERSION 3.25)
project(DataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructures main.cpp zlasdtest/container/container.hpp zlasdtest/container/container.cpp zlasdtest/container/dictionary.hpp zlasdtest/container/testable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/linear.hpp zlasdtest/container/foldable.hpp zlasdtest/exercise1a/fulltest.cpp zlasdtest/exercise1a/simpletest.cpp zlasdtest/exercise1a/test.hpp zlasdtest/exercise1b/test.hpp zlasdtest/exercise1b/simpletest.cpp zlasdtest/exercise1b/fulltest.cpp zlasdtest/test.cpp zmytest/test.cpp zmytest/Stack/stack.hpp)
