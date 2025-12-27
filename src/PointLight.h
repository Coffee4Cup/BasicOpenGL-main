#pragma once
#include <glm/glm.hpp>
#include "Light.h"

class Hit;
class Scene;
class PointLight : public Light {
    protected:
        glm::vec3 position;
        glm::vec3 color;

    public:
        PointLight(const glm::vec3& position, const glm::vec3& color, float intensity);
        glm::vec3 getDiffiusion(const Hit& hit, const Scene& scene) const override;

};