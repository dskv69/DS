#include "application.hpp"
#include "log.hpp"
#include <GLFW/glfw3.h>

void glfw_error_callback(int error_code, const char* description)
{
	DS_ERROR("Error: {}", description);
}

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

	Application::Application()
	{
		logger_init();
		Window::init_glfw();
		m_window = std::make_shared<Window>();
	}

	Application::~Application()
	{
		Window::terminate_glfw();
	}

	void Application::run()
	{
		glfwSetErrorCallback(glfw_error_callback);

		on_start();
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			DS_CRITICAL("FAILED TO LOAD OPENGL");
			exit(-1);
		}


		while (!m_window->should_close())
		{
			Window::poll_events();
			
			on_update();
			m_window->swap_buffers();
		}

		on_close();

		AppInstancer::s_closed = true;
	}
}