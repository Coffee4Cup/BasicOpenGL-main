#pragma once
#include <glm/glm.hpp>
#include "Ray.h"

class Hit;
class Scene;

class Light {
protected:
    float intensity;

public:
    Light(float intensity = 1.0f);
    virtual ~Light() = default;
    float getIntensity() const;
    virtual glm::vec3 getDiffiusion(const Hit& hit, const Scene& scene) const = 0;
    virtual glm::vec3 getSpecular(const Hit& hit, const Scene& scene, const class Ray& ray) const = 0;
};
