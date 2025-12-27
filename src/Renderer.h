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

    Scene currentScene;
    Camera camera;

    unsigned char* finalImagebuffer;
    const unsigned int imageWidth;
    const unsigned int imageHeight;

public:

    Renderer(Camera camera, const Scene& scene, unsigned int width, unsigned int height)
    : currentScene(scene),
    camera(camera),
    finalImagebuffer(new unsigned char[width * height * REQUIRED_COMPONENTS]),
    imageWidth(width), imageHeight(height)
    {}
    
    ~Renderer();
    void initialize(const std::string& scenePathInput);

    /**
    * Renders the current scene and returns the final image buffer
    * Implementation of the ray tracing algorithm
    */
    void render();

    unsigned char* getFinalImage() const;

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
    glm::vec3 getPointOnImagePlane(const Camera& camera, const unsigned int& pixelX, const unsigned int& pixelY);

    // Returns the color as a 3D vector (0.0 to 255.0 range or 0.0 to 1.0)
    void GetColor(glm::vec3& color, const Scene& scene, const Ray& ray, const Hit& hit);
    
    unsigned int convert3DVectorToByteColor(const glm::vec3& color);
};