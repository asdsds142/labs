#pragma once

#include "lve_window.hpp"
#include "lve_device.hpp"
#include "lve_game_object.hpp"
#include "lve_renderer.hpp"
#include "lve_simple_render_system.hpp"

//std
#include <memory>
#include <vector>
#include <stdexcept>
#include <cmath>

//c style
#include <unistd.h>

 namespace lve
{
class FirstApp
{
  public:
    static constexpr int32_t WIDTH = 1200;
    static constexpr int32_t HEIGHT = 800;

    FirstApp();
    ~FirstApp();

    FirstApp(const FirstApp&) = delete;
    FirstApp& operator=(const FirstApp&) = delete;

    void run();
  private:
    void loadGameObjects();

    LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    LveDevice lveDevice{lveWindow};
    LveRenderer lveRenderer{lveWindow, lveDevice};

    std::vector<LveGameObject> gameObjects;
};

    
} // namespace lve

