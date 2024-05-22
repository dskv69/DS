#ifndef DS_LOG_HPP
#define DS_LOG_HPP

#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DS
{
	// Creates two multithreaded spdlogger instance
	void logger_init();

} // DS


#define DS_ERROR(str, ...) spdlog::get("ds_logger")->error(str, __VA_ARGS__)
#define DS_WARN(str, ...) spdlog::get("ds_logger")->warn(str, __VA_ARGS__)
#define DS_INFO(str, ...) spdlog::get("ds_logger")->info(str, __VA_ARGS__)
#define DS_CRITICAL(str, ...) spdlog::get("ds_logger")->critical(str, __VA_ARGS__)
#define DS_ASSERT(expr, msg) if ((expr)) {DS_ERROR("Assertion failed: {} at {}", msg, #expr); exit(-1);} 

#ifdef _DEBUG

#define DS_DEBUG_ERROR(str, ...) spdlog::get("ds_debug")->error(str, __VA_ARGS__)
#define DS_DEBUG_WARN(str, ...) spdlog::get("ds_debug")->warn(str, __VA_ARGS__)
#define DS_DEBUG_INFO(str, ...) spdlog::get("ds_debug")->info(str, __VA_ARGS__)
#define DS_DEBUG_CRITICAL(str, ...) spdlog::get("ds_debug")->critical(str, __VA_ARGS__)
#define DS_DEBUG(str, ...) spdlog::get("ds_debug")->debug(str, __VA_ARGS__)
#define DS_DBG_ASSERT(expr) if ((expr)) {DS_DEBUG_ERROR("Assertion failed at {}", #expr); exit(-1);} 
#define DS_DBG_ASSERTM(expr, msg) if ((expr)) {DS_DEBUG_ERROR("Assertion failed at {}, message: {}", #expr, msg); exit(-1);} 
 
#else

#define DS_DEBUG_ERROR(str, ...)
#define DS_DEBUG_WARN(str, ...)
#define DS_DEBUG_INFO(str, ...)
#define DS_DEBUG_CRITICAL(str, ...)
#define DS_DEBUG(str, ...)
#define DS_DBG_ASSERT(expr)
#define DS_DBG_ASSERTM(expr, msg)

#endif // DEBUG

#endif // DS_LOG_HPP