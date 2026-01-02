#include <glm/glm.hpp>
#include <glad/glad.h>
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>

#include <iostream>
#include <fstream>

#include "Renderer.h"

#include "Camera.h"
#include "Scene.h"
#include "Ray.h"
#include "Hit.h"
#include "SceneObject.h"
#include "Shpere.h"
#include "SolidColorStrategy.h"
#include "Light.h"
#include "PointLight.h"
#include "CheckerboardStrategy.h"
#include "Plane.h"

static constexpr int DEFULAT_SCENE_HEIGHT_AND_WIDTH = 1000;

int main(void)
{
    // std::string scenePathInput = "src/scenes/scene1.txt";
    char scenePathOutput[] = "res/textures/testing3.png";

    std::vector<SceneObject*> sceneObjects;
    std::vector<Light*> sceneLights;

    sceneObjects.push_back(new Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, new SolidColorStrategy(glm::vec3(255.0f, 0.0f, 0.0f))));
    sceneObjects.push_back(new Sphere(glm::vec3(1.0f, 1.0f, 0.0f), 0.75f, new CheckerboardStrategy(glm::vec3(200.0f, 0.0f, 200.0f), 0.2f)));
    sceneObjects.push_back(new Plane(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 1.0f, 1.0f), new CheckerboardStrategy(glm::vec3(200.0f, 200.0f, 200.0f), 0.5f)));
    
    sceneLights.push_back(new PointLight(glm::vec3(-2.0f, 0.0f, 4.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
    Scene scene(sceneObjects, sceneLights);
    
    Camera camera(glm::vec3(0.0f, 0.0f, 12.0f), //position
                           glm::vec3(0.0f, 0.0f, -1.0f), //to vector
                           glm::vec3(0.0f, 1.0f, 0.0f), //up vector
                           2, 2, 5);
    Renderer renderer(camera, scene, DEFULAT_SCENE_HEIGHT_AND_WIDTH, DEFULAT_SCENE_HEIGHT_AND_WIDTH);
    renderer.render();
    
    int result = stbi_write_png(scenePathOutput, DEFULAT_SCENE_HEIGHT_AND_WIDTH, DEFULAT_SCENE_HEIGHT_AND_WIDTH, 4, renderer.getFinalImage(), DEFULAT_SCENE_HEIGHT_AND_WIDTH * 4);
    std::cout << result << std::endl;
    return 0;
}