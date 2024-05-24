#include "ui_layer.hpp"
#include "application.hpp"

namespace DS
{
    UILayer::UILayer() : m_showDemo(false)
    {
    }

    UILayer::~UILayer()
    {
    }

    void UILayer::change_style()
    {
        ImGuiIO &io = ImGui::GetIO();
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.2f, 0.2f, 0.4f, 1.0f);
        style.Colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
        style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        style.Colors[ImGuiCol_Header] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
        style.Colors[ImGuiCol_Tab] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
        style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    }

    // INIT IMGUI
    void UILayer::on_attach(Application *app)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        ImGui::StyleColorsDark();

        change_style();

        const char *glsl_version = "#version 330 core";
        ImGui_ImplGlfw_InitForOpenGL(app->m_window->get_win(), true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void UILayer::on_detach(Application *app)
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void UILayer::on_update(Application *app)
    {
        // IMGUI
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        app->on_ui();

        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        auto io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void UILayer::on_ui(Application *app)
    {
        if (m_showDemo)
            ImGui::ShowDemoWindow(&m_showDemo);
    }

} // namespace DS
