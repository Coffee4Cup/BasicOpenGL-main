#pragma once
#include <glm/glm.hpp>

class Ray {
private:
    glm::vec3 origin;
    glm::vec3 direction;
public:
    Ray() : origin(0.0f), direction(0.0f) {}
    Ray(const glm::vec3& o, const glm::vec3& d) : origin(o), direction(d) {}
    glm::vec3 getOrigin() const { return origin; }
    glm::vec3 getDirection() const { return direction; }
    void setOrigin(const glm::vec3& o) { origin = o; }
    void setDirection(const glm::vec3& d) { direction = d; }
    glm::vec3 pointAt(float t) const { return origin + direction * t; }
};