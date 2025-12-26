#pragma once
#include <vector>

class SceneObject;

class Scene{

private:
    std::vector<SceneObject*> sceneObjects;
    //std::vector<Light> sceneLights;
public:
    Scene(const std::vector<SceneObject*>& objects)
        : sceneObjects(objects)
    {};
    const std::vector<SceneObject*>& getSceneObjects() const;
    ~Scene();

};
