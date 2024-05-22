#include "DS.h"

// DSTest entry point

class TestApp : public DS::Application
{
private:
	void on_start() override
	{

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
	DS::AppInstancer::create_app(new TestApp);
	DS::AppInstancer::start_app();
}