#include "PointLight.h"
#include "Hit.h"
#include "Scene.h"
#include "SceneObject.h"

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
