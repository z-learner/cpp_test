cmake_minimum_required(VERSION 3.0)

project(boost_test)

add_compile_options(-Werror)
add_compile_options(-Wall)

add_compile_options(-D=BOOST_BIND_GLOBAL_PLACEHOLDERS)

SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)

include_directories(
    include
    ${Boost_INCLUDE_DIR}
)

file(GLOB_RECURSE Boost_test_SRC "src/*.cc")

find_package(Boost COMPONENTS timer)
if(NOT Boost_FOUND)
    message("NOT found Boost")
endif()

message(STATUS "BOOST_LIBRARIES=${Boost_LIBRARIES}")

add_executable(${PROJECT_NAME} ${Boost_test_SRC})
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    ${Boost_LIBRARIES} 
    )

# target_compile_definitions(${PROJECT_NAME} 
#   )

