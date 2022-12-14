#pragma once

#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"

//std
#include <memory>
#include <vector>
#include <stdexcept>
#include <cmath>

//c style
#include <unistd.h>

 namespace lve
{
class SimpleRenderSystem
{
  public:

    SimpleRenderSystem(LveDevice& device, VkRenderPass renderPass);
    ~SimpleRenderSystem();

    SimpleRenderSystem(const SimpleRenderSystem&) = delete;
    SimpleRenderSystem& operator=(const SimpleRenderSystem&) = delete;

    void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<LveGameObject>& gameObject);

  private:
    void createPipelineLayout();
    void createPipeline(VkRenderPass renderPass);
    


    LveDevice& lveDevice;

    std::unique_ptr<LvePipeline> lvePipeline;
    VkPipelineLayout pipelineLayout;
};
}