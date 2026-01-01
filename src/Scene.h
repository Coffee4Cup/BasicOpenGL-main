#pragma once
#include <vector>
class Light;
class SceneObject;

class Scene{

private:
    std::vector<SceneObject*> sceneObjects;
    std::vector<Light*> sceneLights;
public:
    Scene(const std::vector<SceneObject*>& objects, const std::vector<Light*>& lights)
        : sceneObjects(objects), sceneLights(lights)
    {}

    ~Scene();
    const std::vector<SceneObject*>& getSceneObjects() const {return sceneObjects;}
  
    const std::vector<Light*>& getLights() const {return sceneLights;}
    };
