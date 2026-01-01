#include "Camera.h"

Camera::Camera(const glm::vec3& position, const glm::vec3& toVector, const glm::vec3& upVector, float screenWidth, float screenHeight, float distance) :
      position(position),
      toVector(glm::normalize(toVector)),
      upVector(glm::normalize(upVector)),
      rightVector(glm::normalize(glm::cross(toVector, upVector))),
      screenWidth(screenWidth),
      screenHeight(screenHeight),
      distance(distance),
      screenCenter(position + (this->toVector * distance))
{}
glm::vec3 Camera::getPosition() const {
    return position;
}

glm::vec3 Camera::getToVector() const {
    return toVector;
}

glm::vec3 Camera::getRightVector() const {
    return rightVector;
}

glm::vec3 Camera::getUpVector() const {
    return upVector;
}

float Camera::getScreenWidth() const {
    return screenWidth;
}

float Camera::getScreenHeight() const {
    return screenHeight;
}
glm::vec3 Camera::getScreenCenter() const {
    return screenCenter;
}