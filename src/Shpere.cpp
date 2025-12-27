#include "Shpere.h"
#include "ITextureStrategy.h"

Sphere::Sphere(const glm::vec3& center, float radius, ITextureStrategy* textureStrategy)
    : center(center), radius(radius), m_textureStrategy(textureStrategy) {}

Sphere::~Sphere() {
    delete m_textureStrategy;
}


/**
 * Intersects the ray with the sphere.
 * @param ray The ray to intersect with.
 * @return return the parametric value t along the ray where the intersection occurs, or 0 if no intersection.
 * 
 * NOTE: implements the intersection algorithm for the sphere using the geometric solution.
 */
float Sphere::intersect(const Ray& ray) const {

    //ray should be in the form P = O + tD
    glm::vec3 L = center - ray.getOrigin();
    float t = glm::dot(L, ray.getDirection());
    float d2 = glm::dot(L, L) - t * t;
    float radius2 = radius * radius;
    if (d2 > radius2) {
        return std::numeric_limits<float>::max(); // No intersection
    }
    float t1 = t - sqrt(radius2 - d2);
    float t2 = t + sqrt(radius2 - d2);
    return t1 < t2 ? t1 : t2;
}

glm::vec3 Sphere::getNormalAt(const glm::vec3& point) const {
    return glm::normalize(point - center);
}

glm::vec3 Sphere::getDiffuseColor(const glm::vec3& point) const {
    return m_textureStrategy->getColor(point);
}

glm::vec3 Sphere::getSpecularColor() const {
    return glm::vec3(255.0f, 255.0f, 255.0f); // White specular highlight
}

float Sphere::getShininess() const {
    return 32.0f; // Shininess factor
}
