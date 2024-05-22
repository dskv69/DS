#ifndef DS_LOG_HPP
#define DS_LOG_HPP

#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DS
{
	// Creates two multithreaded spdlogger instance
	void logger_init();

} // DS

#define DS_ERROR(...) spdlog::get("ds_logger")->error(__VA_ARGS__)
#define DS_WARN(...) spdlog::get("ds_logger")->warn(__VA_ARGS__)
#define DS_INFO(...) spdlog::get("ds_logger")->info(__VA_ARGS__)
#define DS_CRITICAL(...) spdlog::get("ds_logger")->critical(__VA_ARGS__)

#ifdef _DEBUG

#define DS_DEBUG_ERROR(...) spdlog::get("ds_debug")->error(__VA_ARGS__)
#define DS_DEBUG_WARN(...) spdlog::get("ds_debug")->warn(__VA_ARGS__)
#define DS_DEBUG_INFO(...) spdlog::get("ds_debug")->info(__VA_ARGS__)
#define DS_DEBUG_CRITICAL(...) spdlog::get("ds_debug")->critical(__VA_ARGS__)
#define DS_DEBUG(...) spdlog::get("ds_debug")->debug(__VA_ARGS__)

#else

#define DS_DEBUG_ERROR(...)
#define DS_DEBUG_WARN(...)
#define DS_DEBUG_INFO(...)
#define DS_DEBUG_CRITICAL(...)
#define DS_DEBUG(...)

#endif // DEBUG

#endif // DS_LOG_HPP