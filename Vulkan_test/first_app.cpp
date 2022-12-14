#include "first_app.hpp"

//libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

//std
#include <iostream>
#include <cassert>
#include <stdexcept>


namespace lve
{

FirstApp::FirstApp()
{
    loadGameObjects();
}

FirstApp::~FirstApp()
{
}

void FirstApp::run()
{
    std::cout << "maxPushConstantSIze = " << lveDevice.properties.limits.maxPushConstantsSize << '\n';

    SimpleRenderSystem simpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};

    while (!lveWindow.shouldClose())
    {
        glfwPollEvents();
        
        if (auto commandBuffer = lveRenderer.beginFrame())
        {
            lveRenderer.beginSwapChainRenderPass(commandBuffer);
            simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
            lveRenderer.endSwapChainRenderPass(commandBuffer);
            lveRenderer.endFrame();
        }
    }

    vkDeviceWaitIdle(lveDevice.device());
}



void FirstApp::loadGameObjects() {
    std::vector<LveModel::Vertex> vertices{
        {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}} 
    };
    auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);

    for (size_t i = 0; i < 48; ++i)
    {
    auto triangle = LveGameObject::createGameObject();
        triangle.model = lveModel;
        triangle.color = {.4f + glm::sin(98294.0f * i), .5f + glm::sin(i * 342.0f), .0f + glm::abs(glm::cos(i * 25.0f))};
        triangle.transform2d.translation.x = .0f;
        triangle.transform2d.translation.y = .0f;
        triangle.transform2d.scale = {1.f + 0.02 * i, 1.f + 0.02 * 1};
        triangle.transform2d.rotation = 0.5 * glm::pi<float>() + 0.03 * i;

        gameObjects.push_back(std::move(triangle));
    }
}

} // namespace lve
