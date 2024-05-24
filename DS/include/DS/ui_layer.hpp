#ifndef DS_UI_LAYER_HPP
#define DS_UI_LAYER_HPP

#include "layer.hpp"

namespace DS
{
    class UILayer : public Layer
    {
    public:
        bool m_showDemo;

    public:
        UILayer();
        ~UILayer();

        void on_attach(Application *app) override;
        void on_detach(Application *app) override;
        void on_update(Application *app) override;
        void on_ui(Application *app) override;
        void change_style();
    };

} // namespace DS

#endif