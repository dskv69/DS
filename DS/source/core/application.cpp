#include "application.hpp"
#include "log.hpp"

namespace DS
{
	Application* AppInstancer::s_appInstance = nullptr;
	bool AppInstancer::s_created = false;
	bool AppInstancer::s_started = false;
	bool AppInstancer::s_closed = false;

	void AppInstancer::create_app(Application* app)
	{
		s_appInstance = app;
		s_created = true;
	}

	void AppInstancer::start_app()
	{
		s_appInstance->run();
		s_started = true;
	}

	void Application::run()
	{
		logger_init();

		on_start();

		while (true)
		{
			DS_INFO("App is running!");
			on_update();
		}

		on_close();

		AppInstancer::s_closed = true;
	}
}