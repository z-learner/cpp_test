cmake_minimum_required(VERSION 3.0)
 
# Define project name
project(protocol)

# add_compile_options(-Werror)
add_compile_options(-Wall)
add_compile_options(-std=c++14)
# 消除boost的note
add_compile_options(-D=BOOST_BIND_GLOBAL_PLACEHOLDERS)
# if开启Debug模式
SET(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
# 添加头文件
include_directories(
    include
    ${Boost_INCLUDE_DIRS}
)

# 添加代码文件
file(GLOB_RECURSE PROTOCOL_SRC "src/*.cpp")


# 查找依赖
find_package(Boost REQUIRED COMPONENTS thread)
message(STATUS "BOOST_LIBRARIES=${Boost_LIBRARIES}")
if(NOT Boost_FOUND)
    message("NOT found Boost")
endif()

# # 添加动态库
# add_library(${PROJECT_NAME} SHARED ${PROTOCOL_LIB_SRC})

# target_link_libraries(${PROJECT_NAME} pthread boost_thread )

add_executable(client main_client.cc ${PROTOCOL_SRC})
target_link_libraries(client boost_thread pthread)


add_executable(server main_server.cc ${PROTOCOL_SRC})
target_link_libraries(server boost_thread pthread)