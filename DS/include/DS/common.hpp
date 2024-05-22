#ifndef DS_COMMON_HPP
#define DS_COMMON_HPP

// STL
#include <vector>
#include <stdint.h>
#include <string>
#include <string_view>
#include <unordered_set>
#include <unordered_map>
#include <memory>

// VENDORED
#include <GLFW/glfw3.h>

// DS
#include "DS/log.hpp"

// MACROS
#define GETTER(type, name, var) inline type name() {return var;}
#define CGETTER(type, name, var) inline type name() const {return var;}

#endif