#ifndef DS_WINDOW_HPP
#define DS_WINDOW_HPP

#include "common.hpp"

namespace DS
{
	class Application;

	class Window
	{
	private:
		GLFWwindow *m_glfwWindow;
		int m_width, m_height;
		static bool s_glfwInitialized;

		static void init_glfw();
		static void terminate_glfw();

		friend Application;

	public:
		Window();
		~Window();

		void create(int width, int height, const char *title, bool make_current = true);

		CGETTER(int, get_width, m_width);
		CGETTER(int, get_height, m_height);
		CGETTER(GLFWwindow *, get_win, m_glfwWindow);

		bool should_close();
		void swap_buffers();
		static void poll_events();
	};
}

#endif