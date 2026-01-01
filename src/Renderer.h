#pragma once
#include <vector>
#include <string>
#include "Scene.h"
#include "Camera.h"
#include "Ray.h"
#include "Hit.h"
#include "SceneObject.h"
#include "Light.h"
#include <glm/glm.hpp>

class Renderer {
private:

    static constexpr int DEFAULT_IMAGE_HEIGHT_AND_WIDTH = 1000; //the default height and width of the output image
    static constexpr int REQUIRED_COMPONENTS = 4; //(R,G,B,A) usually writen as req_comps in stb image write
    static constexpr float HALF_SCREEN_SCALAR = 0.5f;

    const Scene& currentScene;
    const Camera& camera;

    std::vector<unsigned char> finalImagebuffer;
    const unsigned int imageWidth; //number of pixels in line
    const unsigned int imageHeight; //number of pixels in column

    const glm::vec3 viewPlaneCenter; //P_c of the equation from the presentation
    const glm::vec3 xTerm; // w/2*V_right
    const glm::vec3 yterm; // w/2*V_up
    const glm::vec3 xCoefficient; // the slope of x R*V_right = (width of screen) / (number of pixels in line on the viewPanel)
    const glm::vec3 yCoefficient;
public:
    Renderer(Camera& camera, const Scene& scene, unsigned int width, unsigned int height)
    : currentScene(scene),
    camera(camera),
    finalImagebuffer(width * height * REQUIRED_COMPONENTS),
    imageWidth(width), imageHeight(height),
    viewPlaneCenter(camera.getScreenCenter()),
    xTerm(camera.getScreenWidth() * HALF_SCREEN_SCALAR * camera.getRightVector()),
    yterm(camera.getScreenHeight() * HALF_SCREEN_SCALAR * camera.getUpVector()),
    xCoefficient((camera.getScreenWidth() / (float)width) * camera.getRightVector()),
    yCoefficient((camera.getScreenHeight() / (float)height) * camera.getUpVector())
    {}
    void initialize(const std::string& scenePathInput);

    /**
    * Renders the current scene and returns the final image buffer
    * Implementation of the ray tracing algorithm
    */
    void render();

    const unsigned char* getFinalImage() const;

private:
    /**
     * Constructs a ray through a specific pixel on the camera's image plane.
     * @param camera The camera through which the ray is constructed.
     * @param pixelX The x-coordinate of the pixel.
     * @param pixelY The y-coordinate of the pixel.
     * @return The constructed ray.
     * 
     * ASK: should this method be part of Camera class? my toughts is that I want the camera to not be awere of the picture plane and rendering process 
     */
    void constructRayThroughPixel(Ray& ray, const Camera& camera, const unsigned int& pixelX, const unsigned int& pixelY);
    void findIntersection(Hit& hit, const Ray& ray, const Scene& scene);
    glm::vec3 getPointOnImagePlane(const unsigned int& pixelX, const unsigned int& pixelY);

    // Returns the color as a 3D vector (0.0 to 255.0 range or 0.0 to 1.0)
    void GetColor(glm::vec3& color, const Scene& scene, const Ray& ray, const Hit& hit);
    
    unsigned int convert3DVectorToByteColor(const glm::vec3& color);
};