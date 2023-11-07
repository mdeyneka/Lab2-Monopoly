include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(Monopoly_test Monopoly_test.cpp)

target_link_libraries(Monopoly_test
 PRIVATE
  GTest::GTest
  GTest::gmock
  MonopolyGame)

add_test(MonopolyGame_gtests MoonopolyGame_test)