#include "PointLight.h"
#include "Hit.h"
#include "Scene.h"
#include "SceneObject.h"
#include <iostream>

PointLight::PointLight(const glm::vec3& position, const glm::vec3& color, float intensity)
    : Light(intensity), position(position), color(color) {}
 

glm::vec3 PointLight::getDiffiusion(const Hit& hit, const Scene& scene) const {
    glm::vec3 hitPoint = hit.getHitPoint();
    const SceneObject* hitObject = hit.getSceneObject();

    // Calculate the vector from the hit point to the light source
    glm::vec3 lightDir = glm::normalize(position - hitPoint);

    // Calculate the diffuse component
    float teta = glm::dot(lightDir, hitObject->getNormalAt(hitPoint));
    float diff = glm::max(teta, 0.0f);/*NOTE: maybe this could be a Hit function*/
    glm::vec3 diffuse = color * hitObject->getDiffuseColor(hitPoint) * diff * intensity;
    
    return diffuse;
}

glm::vec3 PointLight::getSpecular(const Hit& hit, const Scene& scene, const Ray& ray) const {
    glm::vec3 hitPoint = hit.getHitPoint();
    const SceneObject* hitObject = hit.getSceneObject();
    glm::vec3 reflectionVector = hitObject->getReflectionVector(hitPoint,position - hitPoint);
    float angleBetweenViewAndReflectionRadian = glm::dot(glm::normalize(ray.getDirection()),glm::normalize(reflectionVector));
    angleBetweenViewAndReflectionRadian = glm::max(angleBetweenViewAndReflectionRadian, 0.0f);

    if (angleBetweenViewAndReflectionRadian > 0.25f) {
        // Set a standard breakpoint on the line below to "skip" to a positive iteration
        float hitDetected = angleBetweenViewAndReflectionRadian; 
    }

    float specularFactor = static_cast<float>(pow(angleBetweenViewAndReflectionRadian, hitObject->getShininess()));
    glm::vec3 specular = color * specularFactor * (hitObject->getSpecularColor() * hitObject->getSpecularCoefficent());
    return specular;
}