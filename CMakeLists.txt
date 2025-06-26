cmake_minimum_required(VERSION 3.10)
project(ssh_logger)

set(CMAKE_CXX_STANDARD 17)

include_directories(conf)
include_directories(inc)

add_executable(ssh_logger
    main.cpp
    src/config.cpp
    src/db.cpp
    src/parser.cpp
)

find_library(MYSQLCPP_CONN mysqlcppconn)
target_link_libraries(ssh_logger ${MYSQLCPP_CONN})
