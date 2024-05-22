add_subdirectory(vendor/spdlog)

add_library (DS "source/core/DS.cpp" "include/DS.h" "source/core/log.cpp" "source/core/application.cpp")
target_include_directories(DS PUBLIC ./include/DS ./include vendor/spdlog/include)
target_link_libraries(DS spdlog)

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
