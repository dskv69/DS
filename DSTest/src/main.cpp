#include "DS.h"

// DSTest entry point

class TestApp : public DS::Application
{
public: 
	TestApp() : Application()
	{
	}

private:
	void on_start() override
	{
		m_window->create(800, 600, "DS ENGINE TEST");
	}	
	
	void on_update() override
	{

	}	
	
	void on_close() override
	{

	}


};

int main(int argc, char* argv[])
{
	auto app = new TestApp;
	DS::AppInstancer::create_app(app);
	DS::AppInstancer::start_app();
	delete app;
}