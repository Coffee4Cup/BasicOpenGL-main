#pragma once

#include <glm/glm.hpp>
#include "SceneObject.h"
#include "Ray.h"

class ITextureStrategy;

class Plane : public SceneObject {
public:
    Plane(const glm::vec3& point, const glm::vec3& normal, ITextureStrategy* textureStrategy);
    ~Plane() override;

    float intersect(const Ray& ray) const override;
    glm::vec3 getNormalAt(const glm::vec3& point) const override;
private:
    static constexpr float EPSILON = 1e-6f;
    const glm::vec3 m_point;
    const glm::vec3 m_normal;
};