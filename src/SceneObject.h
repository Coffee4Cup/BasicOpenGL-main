#pragma once
#include <glm/glm.hpp>

class Ray; 

class SceneObject {
public:
    virtual ~SceneObject() = default;
      /***
     * Intersects the ray with the scene object.
     * @param ray The ray to intersect with.
     * @return The hit information if the ray intersects the object, otherwise std::nullopt.
     */
    virtual float intersect(const Ray& ray) const = 0;
    virtual glm::vec3 getDiffuseColor() const = 0;
    virtual glm::vec3 getSpecularColor() const = 0;
    virtual float getShininess() const = 0;
    virtual glm::vec3 getNormalAt(const glm::vec3& point) const = 0;
    glm::vec3 getReflectionVector(const glm::vec3& point, const glm::vec3& incidentVector) const;
};