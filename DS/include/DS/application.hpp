#ifndef DS_APP_HPP
#define DS_APP_HPP

#include "common.hpp"
#include "window.hpp"

namespace DS
{
	class AppInstancer;

	// This class is meant to be inherited
	class Application
	{
	private:
		friend AppInstancer;
		void run();

		virtual void on_start() = 0;
		virtual void on_update() = 0;
		virtual void on_close() = 0;


	public:
		 std::shared_ptr<Window> m_window;

		Application();
		~Application();
	};

	// makes the app a signleton
	class AppInstancer
	{
	private:
		static Application* s_appInstance;
		static bool s_created;
		static bool s_started;
		static bool s_closed;

		friend Application;

		AppInstancer() = delete;

	public:
		static void create_app(Application* app);
		static void start_app();
		
		GETTER(Application*, get_app, s_appInstance)
		GETTER(bool, is_created, s_created)
		GETTER(bool, is_started, s_started)
		GETTER(bool, is_closed, s_closed)
	};
}; // DS

#endif
