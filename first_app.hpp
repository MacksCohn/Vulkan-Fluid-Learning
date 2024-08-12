#pragma once

#include "./lve_pipeline.hpp"
#include "./lve_window.hpp"
#include "./lve_device.hpp"
#include "./lve_swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
    class FirstApp {
        private:
            LveWindow window{WIDTH, HEIGHT, "Hello Vulkan"};
            LveDevice device{window};
            LveSwapChain swap_chain{device, window.getExtent()};
            std::unique_ptr<LvePipeline> pipeline;
            VkPipelineLayout layout;
            std::vector<VkCommandBuffer> command_buffers;

            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void drawFrame();
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            FirstApp();
            ~FirstApp();

            FirstApp(const FirstApp&) = delete;
            FirstApp& operator=(const FirstApp&) = delete;

            void run();
    };
}