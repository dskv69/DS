set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

add_library (DS "include/DS.h" "source/core/log.cpp" "source/core/application.cpp" "source/core/window.cpp")
target_include_directories(DS PUBLIC ./include/DS ./include vendor/spdlog/include vendor/glfw/include vendor/glad/include)
target_link_libraries(DS spdlog glfw glad)


target_precompile_headers(DS PUBLIC <memory> <vector> <string> <unordered_map> <unordered_set> <string_view> <stdint.h>)


set_property(TARGET DS PROPERTY CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

# TODO: Add tests and install targets if needed.
