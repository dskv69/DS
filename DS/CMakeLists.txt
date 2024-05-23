set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

set(SRC_FILES 	"source/core/log.cpp"
				"source/core/application.cpp" 
				"source/core/window.cpp"
				"source/opengl/gl_renderer.cpp"
				"source/core/layer.cpp")

set(HEADER_FILES "include/DS/application.hpp"
				 "include/DS/window.hpp" 
				 "include/DS/log.hpp" 
				 "include/DS/common.hpp" 
				 "include/DS/gl_renderer.hpp" 
				 "include/DS/layer.hpp"
				 "include/DS.h" )

add_library (DS ${SRC_FILES} ${HEADER_FILES})
target_include_directories(DS PUBLIC ./include/DS ./include vendor/spdlog/include vendor/glfw/include vendor/glad/include vendor/glm)
target_link_libraries(DS spdlog glfw glad)


target_precompile_headers(DS PUBLIC <memory> <vector> <string> <unordered_map> <unordered_set> <string_view> <stdint.h>)


set_property(TARGET DS PROPERTY CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

# TODO: Add tests and install targets if needed.
