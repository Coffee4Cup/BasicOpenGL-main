#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
static constexpr int DEFULAT_SCENE_HEIGHT_AND_WIDTH = 1000;

int main(void)
{
    // std::string scenePathInput = "src/scenes/scene1.txt";
    char scenePathOutput[] = "bin/res/textures/testing1.png";

    std::vector<SceneObject*> sceneObjects;
    sceneObjects.push_back(new Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f));
    sceneObjects.push_back(new Sphere(glm::vec3(0.0f, 0.5f, 2.0f), 0.5f, glm::vec3(0.0f, 255.0f, 0.0f)));
    Scene scene = Scene(sceneObjects);

    Camera camera = Camera(glm::vec3(0.0f, 0.0f, 5.0f), //position
                           glm::vec3(0.0f, 0.0f, -1.0f), //to vector
                           glm::vec3(0.0f, 1.0f, 0.0f), //up vector
                           glm::vec3(1.0f, 1.0f, 0.0f), //screen right up corner
                           glm::vec3(-1.0f, -1.0f, 0.0f) //screen left down corner
                           );
    Renderer renderer = Renderer(camera, scene, DEFULAT_SCENE_HEIGHT_AND_WIDTH, DEFULAT_SCENE_HEIGHT_AND_WIDTH);
    renderer.render();

    int result = stbi_write_png(scenePathOutput, DEFULAT_SCENE_HEIGHT_AND_WIDTH, DEFULAT_SCENE_HEIGHT_AND_WIDTH, 4, renderer.getFinalImage(), DEFULAT_SCENE_HEIGHT_AND_WIDTH * 4);
    std::cout << result << std::endl;

}

// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

// #include <stb/stb_image.h>
// #include <stb/stb_image_write.h>

// #include <iostream>

// int main(void)
// {
//     std::string filepath = "res/textures/plane.png";
//     int width, height, comps;
//     int req_comps = 4;
//     unsigned char * buffer = stbi_load(filepath.c_str(), &width, &height, &comps, req_comps);
//     int result = stbi_write_png("res/textures/new_plane.png", width, height, req_comps, buffer, width * comps);
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <GLFW/glfw3.h>

// int main(void)
// {
//     GLFWwindow* window;

//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;

//     /* Create a windowed mode window and its OpenGL context */
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }

//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);

//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);

//         glBegin(GL_TRIANGLES);
//         glVertex2f(-0.5f, -0.5f);
//         glColor3f(1.0f, 0.0f, 0.0f);
//         glVertex2f(0.0f, 0.5f);
//         glColor3f(0.0f, 1.0f, 0.0f);
//         glVertex2f(0.5f, -0.5f);
//         glColor3f(0.0f, 0.0f, 1.0f);
//         glEnd();

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);

//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }