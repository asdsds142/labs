#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve
{
class LveWindow
{
  public:
    LveWindow(int32_t w, int32_t h, std::string name);
    ~LveWindow();

    LveWindow(const LveWindow&) = delete;
    LveWindow& operator=(const LveWindow&) = delete;

    bool shouldClose() {return glfwWindowShouldClose(window);}
    VkExtent2D getExtent() {return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};}

    void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

  private:
  
    void initWindow();

    const int32_t width;
    const int32_t height;
    
    std::string window_name;
    GLFWwindow* window;


};

} // namespace lve
