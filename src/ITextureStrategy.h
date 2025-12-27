#pragma once
#include <glm/glm.hpp>

class ITextureStrategy {
public:
    virtual ~ITextureStrategy() = default;
    virtual glm::vec3 getColor(const glm::vec3& point) const = 0;
};