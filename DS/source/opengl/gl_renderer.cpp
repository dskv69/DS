#include "gl_renderer.hpp"

namespace DS
{
	void GLRenderer::clear(GLbitfield mask)
	{
		glClear(mask);
	}

	void GLRenderer::set_clear_color(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

}