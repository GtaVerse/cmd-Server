cmake_minimum_required(VERSION 3.10)

project(YT-Cut-Server CXX)



set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CXXFLAGS "-Wall -Werror -Wextra -g -fsanitize=address")

set(SRCDIR source)
set(INCDIR include)


set(SRCS
        main.cpp
        ${SRCDIR}/Command.cpp
        ${SRCDIR}/CommandProcessor.cpp
        ${SRCDIR}/Server.cpp
        ${SRCDIR}/Client.cpp
        ${SRCDIR}/Environment/ENV.CSPORT.cpp
        ${SRCDIR}/Environment/ENV.CSOUTFILE.cpp
        ${SRCDIR}/ServerContext/AConfig.cpp
        ${SRCDIR}/ServerContext/AConfigFile.cpp
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(YT-Cut-Server ${SRCS})


target_include_directories(YT-Cut-Server PRIVATE ${INCDIR})

target_compile_options(YT-Cut-Server PRIVATE ${CXXFLAGS} -I${CMAKE_SOURCE_DIR}/${INCDIR})
