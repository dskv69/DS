#include "layer.hpp"

namespace DS
{
	Layer::Layer()
	{
		DS_INFO("{}", id.to_uint64());
	}

	void Layer::on_attach(Application *app) {}

	void Layer::on_detach(Application *app) {}

	void Layer::on_update(Application *app) {}

	void Layer::on_ui(Application *app) {}
}