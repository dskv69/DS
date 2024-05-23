#include "application.hpp"
#include "log.hpp"
#include "timer.hpp"
#include <GLFW/glfw3.h>

void glfw_error_callback(int error_code, const char *description)
{
	DS_ERROR("Error: {}", description);
}

namespace DS
{
	Application *AppInstancer::s_appInstance = nullptr;
	bool AppInstancer::s_created = false;
	bool AppInstancer::s_started = false;
	bool AppInstancer::s_closed = false;

	void AppInstancer::create_app(Application *app)
	{
		s_appInstance = app;
		s_created = true;
	}

	void AppInstancer::start_app()
	{
		s_appInstance->run();
		s_started = true;
	}

	Application::Application(AppInfo info)
	{
		logger_init();
		Window::init_glfw();
		m_window = std::make_shared<Window>();
		gl_loaded = false;
		m_info = info;
	}

	Application::~Application()
	{
		Window::terminate_glfw();
	}

	void Application::on_start() {}
	void Application::on_update() {}
	void Application::on_close() {}

	void Application::load_gl()
	{
		if (gl_loaded)
			return;

		DS_ASSERT(m_window->m_glfwWindow == nullptr, "");
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			DS_CRITICAL("FAILED TO LOAD OPENGL");
			exit(-1);
		}
		gl_loaded = true;
	}

	void Application::run()
	{
		glfwSetErrorCallback(glfw_error_callback);
		m_window->create(m_info.width, m_info.height, m_info.title);
		load_gl();

		on_start();

		while (!m_window->should_close())
		{
			Window::poll_events();
			on_update();

			for (Layer *layer : m_layers)
			{
				layer->on_update();
			}
			m_window->swap_buffers();
		}

		on_close();

		AppInstancer::s_closed = true;
	}

	void Application::pop_layer()
	{
		Layer *l = m_layers[m_layers.size() - 1];
		l->on_detach();
		delete l;
		m_layers.pop_back();
	}
}