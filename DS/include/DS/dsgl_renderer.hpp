#ifndef DS_GL_RENDERER_HPP
#define DS_GL_RENDERER_HPP

#include "common.hpp"

namespace DS
{
	class GLRenderer
	{
	private:


	public:
		static void clear(GLbitfield mask);
		static void set_clear_color(float r, float g, float b, float a);

		static void render_triangle();
	};
}

#endif