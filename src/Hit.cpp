#include "Hit.h"
#include "SceneObject.h"
/* Hit class represents an intersection point in the scene between a ray and a scene object */

Hit::Hit() : paramtricRayValue(0), normal(0.0f), hitPoint(0.0f), sceneObject(nullptr) {}

Hit::Hit(const glm::vec3& hitPoint, SceneObject* sceneObject)
    : hitPoint(hitPoint), sceneObject(sceneObject) , normal(0.0f)
{}
glm::vec3 Hit::getNormal() {
    if(normal == glm::vec3(0.0f)){//normal not yet calculated
        normal = sceneObject->getNormalAt(hitPoint);
    }
    return normal;
};
glm::vec3 Hit::getHitPoint() const { return hitPoint; }
const SceneObject* Hit::getSceneObject() const { return sceneObject; }
void Hit::setSceneObject(const SceneObject* obj) { sceneObject = obj; }
float Hit::getParametricRayValue() const { return paramtricRayValue; }
void Hit::setParamtricRayValue(const float& t) { paramtricRayValue = t; }
void Hit::setPoint(const glm::vec3& point) { hitPoint = point; }