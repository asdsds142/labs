#include "lve_window.hpp"

// std
#include <stdexcept>

namespace lve
{

    LveWindow::LveWindow(int32_t w, int32_t h, std::string name) : width{w}, height{h}, window_name{name}, window{nullptr}
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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizedCallback);
    }

    void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface");
        }
    }

void LveWindow::framebufferResizedCallback(GLFWwindow* window, int width, int height)
{
    auto lveWindow = reinterpret_cast<LveWindow*>(glfwGetWindowUserPointer(window));
    lveWindow->framebufferResized = true;
    lveWindow->width = width;
    lveWindow->height = height;
}

} // namespace lve