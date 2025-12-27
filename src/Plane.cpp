#include "Plane.h"
#include <limits>
#include "ITextureStrategy.h"

Plane::Plane(const glm::vec3& point, const glm::vec3& normal, ITextureStrategy* textureStrategy)
    : m_point(point), m_normal(glm::normalize(normal)), m_textureStrategy(textureStrategy) {}

Plane::~Plane() {
    delete m_textureStrategy;
}
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

/*Implementation of stratgy pattern for the texture of the plane*/
glm::vec3 Plane::getDiffuseColor(const glm::vec3& point) const {
    return m_textureStrategy->getColor(point);
}

glm::vec3 Plane::getSpecularColor() const {
    return glm::vec3(255.0f, 255.0f, 255.0f);
}

float Plane::getShininess() const {
    return 32.0f;
}