// Copyright Max Cohn 2024
#pragma once

#include <string>
#include <vector>
#include "./lve_device.hpp"

namespace lve
{
   struct PipelineConfigInfo {
      VkViewport viewport;
      VkRect2D scissor;
      VkPipelineViewportStateCreateInfo viewportInfo;
      VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
      VkPipelineRasterizationStateCreateInfo rasterizationInfo;
      VkPipelineMultisampleStateCreateInfo multisampleInfo;
      VkPipelineColorBlendAttachmentState colorBlendAttachment;
      VkPipelineColorBlendStateCreateInfo colorBlendInfo;
      VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
      VkPipelineLayout pipelineLayout = nullptr;
      VkRenderPass renderPass = nullptr;
      uint32_t subpass = 0;
   };
class LvePipeline {
 private:
    LveDevice& lveDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

    void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

    static std::vector<char> readFile(const std::string& filepath);
    void createGraphicsPipeline(const std::string& vert_file_path, const std::string& frag_file_path, const PipelineConfigInfo& configInfo);
 public:
    LvePipeline(LveDevice &device, const std::string& vert_file_path, const std::string& frag_file_path, const PipelineConfigInfo& configInfo);
    ~LvePipeline();
    LvePipeline(const LvePipeline&) = delete;
    void operator=(const LvePipeline&) = delete;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
};
}  // namespace lve
