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


#ifdef _DEBUG

#define DS_DEBUG_ERROR(str, ...) spdlog::get("ds_debug")->error(str, __VA_ARGS__)
#define DS_DEBUG_WARN(str, ...) spdlog::get("ds_debug")->warn(str, __VA_ARGS__)
#define DS_DEBUG_INFO(str, ...) spdlog::get("ds_debug")->info(str, __VA_ARGS__)
#define DS_DEBUG_CRITICAL(str, ...) spdlog::get("ds_debug")->critical(str, __VA_ARGS__)
#define DS_DEBUG(str, ...) spdlog::get("ds_debug")->debug(str, __VA_ARGS__)

#else

#define DS_DEBUG_ERROR(str, ...)
#define DS_DEBUG_WARN(str, ...)
#define DS_DEBUG_INFO(str, ...)
#define DS_DEBUG_CRITICAL(str, ...)
#define DS_DEBUG(str, ...)

#endif // DEBUG

#endif // DS_LOG_HPP