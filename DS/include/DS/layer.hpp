#ifndef DS_LAYER_HPP
#define DS_LAYER_HPP

#include "common.hpp"
#include "id.hpp"

namespace DS
{
	class Application;

	class Layer
	{
	private:
	public:
		Layer();
		~Layer() = default;

		virtual void on_attach(Application *app);
		virtual void on_detach(Application *app);
		virtual void on_update(Application *app);
		virtual void on_ui(Application *app);

		UUID id;
	};
}

#endif