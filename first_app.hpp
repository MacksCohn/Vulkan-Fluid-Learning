#pragma once

#include "./lve_pipeline.hpp"
#include "./lve_window.hpp"
#include "./lve_device.hpp"

namespace lve {
    class FirstApp {
        private:
            LveWindow window{WIDTH, HEIGHT, "Hello Vulkan"};
            LveDevice device{window};
            LvePipeline pipeline{
                device, "shaders/simple_shader.vert.spv",
                 "shaders/simple_shader.frag.spv", LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();
    };
}