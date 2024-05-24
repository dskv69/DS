#ifndef DS_APP_HPP
#define DS_APP_HPP

#include "common.hpp"
#include "window.hpp"
#include "layer.hpp"
#include "ui_layer.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace DS
{
	struct AppInfo
	{
		int width;
		int height;
		const char *title;
	};

	class AppInstancer;

	// This class is meant to be inherited
	class Application
	{
		friend AppInstancer;
		friend UILayer;

	private:
		AppInfo m_info;
		std::vector<Layer *> m_layers;
		std::unique_ptr<UILayer> m_uiLayer;

	public:
		std::shared_ptr<Window> m_window;
		bool gl_loaded;

	private:
		void run();

	protected:
		void load_gl();

		virtual void on_start();
		// called after all layers are updated
		virtual void on_update();
		virtual void on_close();
		virtual void on_ui();

	public:
		Application(AppInfo info = {800, 600, "DS ENGINE"});
		~Application();

		inline void imgui_demo()
		{
			m_uiLayer->m_showDemo = !m_uiLayer->m_showDemo;
		}

		template <typename T>
		void push_layer()
		{
			m_layers.push_back(new T());
			m_layers[m_layers.size() - 1]->on_attach(this);
		}

		void pop_layer();
	};

	// makes the app a signleton
	class AppInstancer
	{
	private:
		static Application *s_appInstance;
		static bool s_created;
		static bool s_started;
		static bool s_closed;

		friend Application;

		AppInstancer() = delete;

	public:
		static void create_app(Application *app);
		static void start_app();

		GETTER(Application *, get_app, s_appInstance)
		GETTER(bool, is_created, s_created)
		GETTER(bool, is_started, s_started)
		GETTER(bool, is_closed, s_closed)
	};
}; // DS

#endif
