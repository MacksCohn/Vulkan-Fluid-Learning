// Copyright Max Cohn 2024
#pragma once

#include <string>
#include <vector>

namespace lve
{
class LvePipeline {
 private:
    static std::vector<char> readFile(const std::string& filepath);
    void createGraphicsPipeline(const std::string& vert_file_path, const std::string& frag_file_path);
 public:
  LvePipeline(const std::string& vert_file_path, const std::string& frag_file_path);
};
}  // namespace lve
