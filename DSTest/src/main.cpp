#include "DS.h"

// DSTest entry point

class TestLayer : public DS::Layer
{
public:
	TestLayer() : Layer()
	{
	}

public:
	virtual void on_update() override
	{
		glClearColor(0.3f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
};

int main(int argc, char *argv[])
{
	DS::PerformanceTimer p("Application");
	auto app = new DS::Application();

	DS::AppInstancer::create_app(app);
	app->push_layer<TestLayer>();
	DS::AppInstancer::start_app();

	delete app;
	return 0;
}