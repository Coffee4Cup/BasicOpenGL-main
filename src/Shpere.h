#pragma once

#include <glm/glm.hpp>
#include "SceneObject.h"
#include "Ray.h"

class ITextureStrategy;

class Sphere : public SceneObject {
public:
    Sphere(const glm::vec3& center, float radius, ITextureStrategy* textureStrategy, float shininess = 10.0f);
    ~Sphere() override;

    float intersect(const Ray& ray) const override;
    glm::vec3 getNormalAt(const glm::vec3& point) const override;

private:
    const glm::vec3 center;
    const float radius;
};