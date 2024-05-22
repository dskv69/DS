#include "window.hpp"

namespace DS
{
	bool Window::s_glfwInitialized = false;

	Window::Window() : m_glfwWindow(nullptr), m_width(0), m_height(0)
	{
	}

	Window::~Window()
	{
		if(s_glfwInitialized && m_glfwWindow != nullptr)
			glfwDestroyWindow(m_glfwWindow);
	}

	void Window::init_glfw() 
	{ 
		s_glfwInitialized = true;
		glfwInit();
	}

	void Window::terminate_glfw()
	{
		s_glfwInitialized = false;
		glfwTerminate();
	}
	void Window::create(int w, int h, const char* title, bool make_current)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		m_glfwWindow = glfwCreateWindow(w, h, title, NULL, NULL);

		DS_ASSERT(!m_glfwWindow, "failed to create window");

		if (make_current)
		{
			glfwMakeContextCurrent(m_glfwWindow);
		}
	}

	bool Window::should_close() 
	{
		DS_DBG_ASSERT(m_glfwWindow==nullptr);
		return glfwWindowShouldClose(m_glfwWindow);
	}

	void Window::poll_events()
	{
		glfwPollEvents();
	}

	void Window::swap_buffers()
	{
		DS_DBG_ASSERT(m_glfwWindow==nullptr);
		glfwSwapBuffers(m_glfwWindow);
	}
}