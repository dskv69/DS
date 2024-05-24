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
		m_uiLayer = std::make_unique<UILayer>();
	}

	Application::~Application()
	{
		Window::terminate_glfw();
	}

	void Application::on_start()
	{
		glfwSetErrorCallback(glfw_error_callback);
		m_window->create(m_info.width, m_info.height, m_info.title);
		load_gl();
	}

	void Application::on_update()
	{

		glClearColor(0.3f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer *layer : m_layers)
		{
			layer->on_update(this);
		}
		m_uiLayer->on_update(this);

		Window::poll_events();
		m_window->swap_buffers();
	}

	void Application::on_close()
	{
	}

	void Application::on_ui()
	{
		for (Layer *layer : m_layers)
		{
			layer->on_ui(this);
		}
		m_uiLayer->on_ui(this);
	}

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
		on_start();
		m_uiLayer->on_attach(this);

		while (!m_window->should_close())
		{
			on_update();
		}

		while (m_layers.size() != 0)
		{
			pop_layer();
			m_uiLayer->on_detach(this);
		}

		on_close();

		AppInstancer::s_closed = true;
	}

	void Application::pop_layer()
	{
		Layer *l = m_layers[m_layers.size() - 1];
		l->on_detach(this);
		delete l;
		m_layers.pop_back();
	}
}