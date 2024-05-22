#include "application.hpp"
#include "log.hpp"
#include <GLFW/glfw3.h>

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
		glfwInit();
		auto window = glfwCreateWindow(800, 600, "DS", NULL, NULL);
		glfwMakeContextCurrent(window);

		on_start();

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
			
			on_update();
			glfwSwapBuffers(window);
		}

		glfwTerminate();
		on_close();

		AppInstancer::s_closed = true;
	}
}