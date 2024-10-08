#include "lve_model.hpp"
#include <cassert>
#include <cstring>

namespace lve {
    LveModel::LveModel(LveDevice &device, const std::vector<Vertex>& vertices) : device{device} {
        createVertexBuffers(vertices);
    }
    LveModel::~LveModel() {
        vkDestroyBuffer(device.device(), vertex_buffer, nullptr);
        vkFreeMemory(device.device(), vertex_buffer_memory, nullptr);
    }

    void LveModel::createVertexBuffers(const std::vector<Vertex>& vertices) {
        vertex_count = static_cast<uint32_t>(vertices.size());
        assert(vertex_count >= 3 && "Vertex count must be at least 3");
        VkDeviceSize buffer_size = sizeof(vertices[0]) * vertex_count;
        device.createBuffer(
            buffer_size,
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            vertex_buffer,
            vertex_buffer_memory
        );

        void* data;
        vkMapMemory(device.device(), vertex_buffer_memory, 0, buffer_size, 0, &data);
        memcpy(data, vertices.data(), static_cast<size_t>(buffer_size));
        vkUnmapMemory(device.device(), vertex_buffer_memory);
    }

    void LveModel::bind(VkCommandBuffer command_buffer) {
        VkBuffer buffers[] = {vertex_buffer};
        VkDeviceSize offsets[] = {0};
        vkCmdBindVertexBuffers(command_buffer, 0, 1, buffers, offsets);
    }

    void LveModel::draw(VkCommandBuffer command_buffer) {
        vkCmdDraw(command_buffer, vertex_count, 1, 0, 0);
    }

}