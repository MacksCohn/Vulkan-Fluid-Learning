// Copyright 2024 Max Cohn
#include "./lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lve
{
  LvePipeline::LvePipeline(const std::string& vert_file_path, const std::string& frag_file_path) {
    createGraphicsPipeline(vert_file_path, frag_file_path);
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
        const std::string& vert_file_path, const std::string& frag_file_path) {
            auto vertCode = readFile(vert_file_path);
            auto fragCode = readFile(frag_file_path);
            std::cout << "Vertex Shader code size: " << vertCode.size() << std::endl;
            std::cout << "Fragment Shader code size: " << fragCode.size() << std::endl;
        }


}  // namespace lve

