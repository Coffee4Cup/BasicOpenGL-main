#include "SceneObject.h"
#include "Ray.h"

  glm::vec3 SceneObject::getReflectionVector(const glm::vec3& point, const glm::vec3& incidentVector) const{
        glm::vec3 normal = getNormalAt(point);
        return glm::reflect(incidentVector, normal); //NOTE: using glm's reflect function, if we were to implement it ourselves it would be: u - 2 * dot(u, v) * v
    }