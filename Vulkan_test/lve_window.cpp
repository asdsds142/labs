#include "lve_window.hpp"

namespace lve {

LveWindow::LveWindow(int32_t w, int32_t h, std::string name): 
width{w}, height{h}, window_name{name}, window{nullptr}
{
    initWindow();
} 

LveWindow::~LveWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


void LveWindow::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
}


} // namespace lve