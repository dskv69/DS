#include "layer.hpp"

namespace DS
{
	Layer::Layer()
	{
		DS_INFO("{}", id.to_uint64());
	}

	void Layer::on_attach() {}

	void Layer::on_detach() {}

	void Layer::on_update() {}

	void Layer::on_ui() {}
}