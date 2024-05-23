#include "layer.hpp"

namespace DS
{
	Layer::Layer(size_t i) : id(i)
	{
	}

	void Layer::on_attach() {}

	void Layer::on_detach() {}

	void Layer::on_update() {}

	void Layer::on_ui() {}
}