#include "DS.h"

// DSTest entry point

class TestLayer : public DS::Layer
{
public:
	TestLayer(size_t id) : Layer(id)
	{
	}

public:

	void on_update() override
	{
		DS_INFO("Hello from Test Layer");
	}

};

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
		load_gl();
		glClearColor(1.0f, 0.0f, 0.5f, 1.0f);
	}	
	
	void on_update() override
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}	
	
	void on_close() override
	{

	}
};

int main(int argc, char *argv[])
{
	auto app = new TestApp;
	DS::AppInstancer::create_app(app);
	app->push_layer<TestLayer>();
	DS::AppInstancer::start_app();
	delete app;
}