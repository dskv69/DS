#include "log.hpp"

namespace DS {

	void logger_init()
	{
		auto console = spdlog::stdout_color_mt("ds_logger");
		auto debug_logger = spdlog::stdout_color_mt("ds_debug");
	}
}