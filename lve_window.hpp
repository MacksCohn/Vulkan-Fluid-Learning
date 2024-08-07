// Copyright 2024 Max Cohn
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace lve {
class LveWindow {
 private:
    const int width;
    const int height;

    std::string name;

    GLFWwindow* window;

    void initWindow();
 public:
    LveWindow(int w, int h, std::string n);
    ~LveWindow();
    LveWindow(const LveWindow&) = delete;
    LveWindow& operator=(const LveWindow&) = delete;

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    bool shouldClose() { return glfwWindowShouldClose(window); }
};
}  // namespace lve
