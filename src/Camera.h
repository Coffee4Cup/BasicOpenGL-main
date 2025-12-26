#pragma once
#include <glm/glm.hpp>

/**
 * Camera class represents the camera in the 3D scene
 * It holds the position, to vector, and up vector of the camera
 * The default position is (0,0,0), looking towards negative Z axis with Y axis as up direction
 */
class Camera {
private:
    // Move the camera back so it can look through the image plane at Z=0
    static constexpr glm::vec3 DEFAULT_CAMERA_POSITION = glm::vec3(0.0f, 0.0f, 5.0f);
    static constexpr glm::vec3 DEFAULT_CAMERA_UP_VECTOR = glm::vec3(0.0f, 1.0f, 0.0f);
    static constexpr glm::vec3 DEFAULT_CAMERA_TO_VECTOR = glm::vec3(0.0f, 0.0f, -1.0f);
    static constexpr glm::vec3 DEFAULT_CAMERA_RIGHT_VECTOR = glm::vec3(1.0f, 0.0f, 0.0f);
    static constexpr glm::vec3 DEFAULT_CAMERA_SCREEN_RIGHT_UP_CORNER = glm::vec3(1.0f, 1.0f, 0.0f);
    static constexpr glm::vec3 DEFAULT_CAMERA_SCREEN_LEFT_DOWN_CORNER = glm::vec3(-1.0f, -1.0f, 0.0f);

    glm::vec3 position;
    glm::vec3 toVector;
    glm::vec3 upVector;
    glm::vec3 screenRightUpCorner;
    glm::vec3 screenLeftDownCorner;
    unsigned int screenWidth;
    unsigned int screenHeight;

public:
    /**
     * Default constructor for the Camera class and screen
     * Phase 1 - Fixed Camera:
     * o Screen located on the XY Plane, at Z = 0.
     * o Right up corner of the screen is located at (1, 1, 0) in the 3D scene.
     * o Left down corner of the screen is located at (-1, -1, 0) in the 3D scene.
     * o Camera position specified in input file.
     */
    Camera();
    Camera(const glm::vec3& position, const glm::vec3& toVector, const glm::vec3& upVector, const glm::vec3
        &screenRightUpCorner, const glm::vec3& screenLeftDownCorner);
    glm::vec3 getPosition() const;
    glm::vec3 getToVector() const;
    glm::vec3 getUpVector() const;
    glm::vec3 getScreenRightUpCorner() const;
    glm::vec3 getScreenLeftDownCorner() const;
    unsigned int getScreenWidth() const;
    unsigned int getScreenHeight() const;
};