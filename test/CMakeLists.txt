# book

set(TEST ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SRC book/unittest.cpp)

add_executable(${TEST} ${TEST_SRC})
add_test(NAME ${TEST} COMMAND ${TEST})
target_include_directories(${TEST} PUBLIC ${gtest_SOURCE_DIR}/include)
target_link_libraries(${TEST} PUBLIC GTest::gtest GTest::gtest_main)

# common
set(COMMON_TEST common_test)

file(GLOB_RECURSE COMMON_TEST_SRC common/*.cpp)

add_executable(${COMMON_TEST} ${COMMON_TEST_SRC})
add_test(NAME ${COMMON_TEST} COMMAND ${COMMON_TEST})

target_include_directories(${COMMON_TEST} PUBLIC ${PROJECT_SOURCE_DIR}/features/common ${gtest_SOURCE_DIR}/include)
target_link_libraries(${COMMON_TEST} PUBLIC common GTest::gtest GTest::gtest_main)

 # 这行代码用于包含Google Test框架的CMake模块。通过包含GoogleTest模块，可以使用Google Test提供的一些CMake函数和宏，用于配置和管理测试相关的任务。
# include(GoogleTest)
find_package(GTest CONFIG REQUIRED)
# 设置包含目录，通常这不是必需的，因为 FetchContent_MakeAvailable 已经处理了  
# 但如果您遇到问题，可以手动添加
# target_include_directories(${COMMON_TEST} PUBLIC ${gtest_SOURCE_DIR}/include)

# add_subdirectory(jnitest)

# fuzz
# add_executable(request_message_parse fuzzers/request_message_parse.cpp)
# target_compile_options(request_message_parse PRIVATE -fsanitize=address,fuzzer)
# target_link_libraries(request_message_parse simple-web-server -fsanitize=address,fuzzer)
# set_target_properties(request_message_parse PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 一个单元测试来说，添加的步骤为：
# 1. 使用add_executable添加测试目标
# 2. 使用target_link_libraries为测试目标添加依赖gtest和gtest_main
# 3. 使用add_test添加到项目，以便可以使用ctest命令执行测试

# 1. build/test 执行 执行 ctest -V -C Debug 可以输出详细信息
# 2. build/test 执行 make test 只能输出测试结果
# 3. build/test 执行 xxx