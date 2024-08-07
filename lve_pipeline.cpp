// Copyright 2024 Max Cohn
#include "./lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve
{
    LvePipeline::LvePipeline(LveDevice &device, const std::string& vert_file_path,
        const std::string& frag_file_path, const PipelineConfigInfo& configInfo) : lveDevice(device) {
    createGraphicsPipeline(vert_file_path, frag_file_path, configInfo);
  }

    std::vector<char> LvePipeline::readFile(const std::string& filepath) {
        std::ifstream file {filepath, std::ios::ate | std::ios::binary};
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file " + filepath);
        }

        size_t file_size = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(file_size);

        file.seekg(0);
        file.read(buffer.data(), file_size);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(
        const std::string& vert_file_path, const std::string& frag_file_path, const PipelineConfigInfo& configInfo) {
            auto vertCode = readFile(vert_file_path);
            auto fragCode = readFile(frag_file_path);
            std::cout << "Vertex Shader code size: " << vertCode.size() << std::endl;
            std::cout << "Fragment Shader code size: " << fragCode.size() << std::endl;
        }

    void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("BABABOOSHKA! Failed to create shader module.");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }

}  // namespace lve

