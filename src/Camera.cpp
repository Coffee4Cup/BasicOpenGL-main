#include "Camera.h"

Camera::Camera()
    : position(DEFAULT_CAMERA_POSITION),
      toVector(DEFAULT_CAMERA_TO_VECTOR),
      upVector(DEFAULT_CAMERA_UP_VECTOR),
      screenRightUpCorner(DEFAULT_CAMERA_SCREEN_RIGHT_UP_CORNER),
      screenLeftDownCorner(DEFAULT_CAMERA_SCREEN_LEFT_DOWN_CORNER)
{
    screenWidth = static_cast<unsigned int>(screenRightUpCorner.x - screenLeftDownCorner.x);
    screenHeight = static_cast<unsigned int>(screenRightUpCorner.y - screenLeftDownCorner.y);
}
Camera::Camera(const glm::vec3& position, const glm::vec3& toVector, const glm::vec3& upVector, const glm::vec3
    &screenRightUpCorner, const glm::vec3& screenLeftDownCorner)
    : position(position),
      toVector(toVector),
      upVector(upVector),
      screenRightUpCorner(screenRightUpCorner),
      screenLeftDownCorner(screenLeftDownCorner){
    screenWidth = static_cast<unsigned int>(screenRightUpCorner.x - screenLeftDownCorner.x);
    screenHeight = static_cast<unsigned int>(screenRightUpCorner.y - screenLeftDownCorner.y);
}

glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getToVector() const {
    return toVector;
}

glm::vec3 Camera::getUpVector() const {
    return upVector;
}

glm::vec3 Camera::getScreenRightUpCorner() const {
    return screenRightUpCorner;
}

glm::vec3 Camera::getScreenLeftDownCorner() const {
    return screenLeftDownCorner;
}

unsigned int Camera::getScreenWidth() const {
    return screenWidth;
}

unsigned int Camera::getScreenHeight() const {
    return screenHeight;
}