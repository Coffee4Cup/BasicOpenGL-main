#include "Scene.h"
#include "SceneObject.h"
#include "Shpere.h" //WE NEED TO REMOVE THIS LATER AFTER WE HAVE A PROPER SCENE LOADER
#include "Light.h"


Scene::~Scene() {
    for (SceneObject* obj : sceneObjects) {
        delete obj;
    }
    for(Light* light : sceneLights){
        delete light;
    }
}
