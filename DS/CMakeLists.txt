add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)

add_library (DS "include/DS.h" "source/core/log.cpp" "source/core/application.cpp" "source/core/window.cpp")
target_include_directories(DS PUBLIC ./include/DS ./include vendor/spdlog/include vendor/glfw/include)
target_link_libraries(DS spdlog glfw)
target_precompile_headers(DS PUBLIC <memory> <vector> <string> <unordered_map> <unordered_set> <string_view> <stdint.h>)

if (MSVC)

# TODO

else()

set(CMAKE_CXX_COMPILE_FEATURES -std=c++20)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-std:c++20)

endif()

set_property(TARGET DS PROPERTY CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

# TODO: Add tests and install targets if needed.
