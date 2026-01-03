#include "Light.h"
#include "Hit.h"
#include "Scene.h"
#include "Scene.h"
#include "SceneObject.h"

Light::Light(float intensity)
    : intensity(intensity) {}
float Light::getIntensity() const {
    return intensity;
}
