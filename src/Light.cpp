#include "Light.h"

Light::Light(float intensity)
    : intensity(intensity) {}
float Light::getIntensity() const {
    return intensity;
}
