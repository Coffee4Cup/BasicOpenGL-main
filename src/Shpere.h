#pragma once

#include <glm/glm.hpp>
#include "SceneObject.h"
#include "Ray.h"

class Sphere : public SceneObject {
public:
    Sphere(const glm::vec3& center = glm::vec3(0.0f, 0.0f, 3.0f), float radius = 1.0f, const glm::vec3& color = glm::vec3(255.0f, 0.0f, 0.0f))
        : center(center), radius(radius), color(color) {};
    ~Sphere() override = default;

    float intersect(const Ray& ray) const override;
    glm::vec3 getDiffuseColor() const override;
    glm::vec3 getSpecularColor() const override;
    float getShininess() const override;
    glm::vec3 getNormalAt(const glm::vec3& point) const override;

private:
    const glm::vec3 center;
    const float radius;
    const glm::vec3 color;
};
