#include "Scene.h"
#include "SceneObject.h"
#include "Shpere.h" //WE NEED TO REMOVE THIS LATER AFTER WE HAVE A PROPER SCENE LOADER

const std::vector<SceneObject*>& Scene::getSceneObjects() const {
    return sceneObjects;
}

Scene::~Scene() {
    for (SceneObject* obj : sceneObjects) {
        delete obj;
    }
}
