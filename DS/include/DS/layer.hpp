#ifndef DS_LAYER_HPP
#define DS_LAYER_HPP

#include "common.hpp"
#include "id.hpp"

namespace DS
{
	class Layer
	{
	private:
	public:
		Layer();
		~Layer() = default;

		virtual void on_attach();
		virtual void on_detach();
		virtual void on_update();
		virtual void on_ui();

		UUID id;
	};
}

#endif