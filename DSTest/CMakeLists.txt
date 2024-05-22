project(DSTEST VERSION 1.0)

add_executable(DSTEST src/main.cpp)
target_include_directories(DSTEST PUBLIC ../DS/include)
target_link_libraries(DSTEST DS)