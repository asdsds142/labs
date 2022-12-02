#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cstring>


constexpr uint32_t WIDTH = 1000;
constexpr uint32_t HEIGHT = 800;

const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif




class HelloTriangleApplication {
public:
    void run();

private:
    GLFWwindow*                 window;
    VkInstance                  instance;
    VkDebugUtilsMessengerEXT    debug_messenger;

    void initWindow();
    bool checkValidationLayerSupport();
    void createInstance();
    void initVulkan();
    void mainLoop();
    void cleanup();
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData);
};