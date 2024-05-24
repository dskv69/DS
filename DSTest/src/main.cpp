#include "DS.h"

// DSTest entry point

class TestLayer : public DS::Layer
{
public:
	TestLayer() : Layer()
	{
	}

private:
	virtual void on_update(DS::Application *app) override
	{
	}

	virtual void on_ui(DS::Application *app) override
	{
		ImGui::Begin("DS Debug Window");
		ImGui::Text("Hello, World!");
		if (ImGui::Button("Show/Hide Demo", ImVec2(120, 30)))
		{
			app->imgui_demo();
		}
		ImGui::End();
	}

	virtual void on_detach(DS::Application *app) override
	{
		DS_INFO("Detached test layer");
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