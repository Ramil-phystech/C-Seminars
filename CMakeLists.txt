cmake_minimum_required(VERSION 3.15)
project(get_predict_from_model)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED COMPONENTS system json beast)

set(BOOST_USE_OPENSSL OFF)
add_executable(get_predict_from_model get_predict.cpp)

target_link_libraries(get_predict_from_model PRIVATE ws2_32 Boost::system Boost::json Boost::beast)
