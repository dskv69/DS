#ifndef DS_LAYER_HPP
#define DS_LAYER_HPP

namespace DS
{
	class Layer
	{
	private:

	public: 
		Layer(size_t id);
		~Layer() = default;

		virtual void on_attach() {}
		virtual void on_detach() {}
		virtual void on_update() {}
		virtual void on_ui() {}

		size_t id;
	};
}

#endif