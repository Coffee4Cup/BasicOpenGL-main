#pragma once
#include <glm/glm.hpp>

class Light {
protected:
    float intensity;

public:
    Light(float intensity = 1.0f);
    virtual ~Light() = default;
    float getIntensity() const;

    virtual glm::vec3 getDiffiusion(const class Hit& hit, const class Scene& scene) const = 0;
};
