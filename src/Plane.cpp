#include "Plane.h"
#include <limits>
#include "ITextureStrategy.h"

Plane::Plane(const glm::vec3& point, const glm::vec3& normal, ITextureStrategy* textureStrategy, float shininess)
    : SceneObject(textureStrategy, shininess), m_point(point), m_normal(glm::normalize(normal)) {}

Plane::~Plane() {}
float Plane::intersect(const Ray& ray) const {
    float denom = glm::dot(m_normal, ray.getDirection());
    
    // Check if the ray is not parallel to the plane
    if (glm::abs(denom) > EPSILON) {
        float t = glm::dot(m_point - ray.getOrigin(), m_normal) / denom;
        if (t >= 0.0f) {
            return t;
        }
    }
    
    return std::numeric_limits<float>::max();
}

glm::vec3 Plane::getNormalAt(const glm::vec3& point) const {
    return m_normal;
}
