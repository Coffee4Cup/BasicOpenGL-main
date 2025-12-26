#pragma once
#include <glm/glm.hpp>

class SceneObject; 

/* Hit class represents an intersection point in the scene between a ray and a scene object */
class Hit
{
private:
    float paramtricRayValue; //t value along the ray where the hit occurred
    glm::vec3 normal;
    glm::vec3 hitPoint;
    const SceneObject* sceneObject;

public:
/*Creates the Hit object with a hit point, the scene object (element) being hit, and a normal of the scene object at the point of intersection
*NOTE: normal is optional and can be calculated later if the current hit turns out to be the closest hit, otherwise it is not relevent. So the normal gets a default value of (0,0,0) to indicate it is not yet calculated.
*@param hitPoint The point in 3D space where the hit occurred
*@param sceneObject The scene object that was hit
*
*/
    Hit();
    
    Hit(const glm::vec3& hitPoint, SceneObject* sceneObject);

    glm::vec3 getNormal();
    glm::vec3 getHitPoint() const;
    const SceneObject* getSceneObject() const;
    void setSceneObject(const SceneObject* obj);
    float getParametricRayValue() const;
    void setParamtricRayValue(const float& t);
    void setPoint(const glm::vec3& point);
};
