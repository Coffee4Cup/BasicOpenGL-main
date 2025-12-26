#include "Renderer.h"

Renderer::~Renderer() {
    delete[] finalImagebuffer;
}

void Renderer::render(){
    Hit hit;
    Ray ray;
    ray.setOrigin(camera.getPosition()); // the origin of the ray is the camera position
    for(unsigned int y = 0; y < imageHeight; y++){
        for(unsigned int x = 0; x < imageWidth; x++){
            constructRayThroughPixel(&ray, camera, x, y);
            findIntersection(&hit, ray, currentScene);
            
            glm::vec3 color = GetColor(currentScene, ray, hit);
            unsigned int pixelIndex = (y * imageWidth + x) * REQUIRED_COMPONENTS;
            
            finalImagebuffer[pixelIndex + 0] = static_cast<unsigned char>(glm::clamp(color.r, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 1] = static_cast<unsigned char>(glm::clamp(color.g, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 2] = static_cast<unsigned char>(glm::clamp(color.b, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 3] = 255; // Alpha channel
        }
    }
}


unsigned char* Renderer::getFinalImage() const {
    return finalImagebuffer;
}
void Renderer::constructRayThroughPixel(Ray* ray, const Camera& camera, const unsigned int& pixelX, const unsigned int& pixelY){
 
    glm::vec3 pixelPoint = getPointOnImagePlane(camera, pixelX, pixelY);
 
    ray->setDirection(glm::normalize(pixelPoint - camera.getPosition())); 
}

void Renderer::findIntersection(Hit* hit, const Ray& ray, const Scene& scene){
    float currentT = std::numeric_limits<float>::max(), minT = std::numeric_limits<float>::max();
    hit->setSceneObject(nullptr);
    const std::vector<SceneObject*>& sceneObjects = scene.getSceneObjects();
    for(const SceneObject* obj : sceneObjects){
        currentT = obj->intersect(ray);
        if(currentT >= 0.0f && currentT < minT){
            minT = currentT;
            hit->setSceneObject(obj);
            hit->setParamtricRayValue(minT);
            hit->setPoint(ray.pointAt(minT)); //TODO: check if this is doesnt cause issues numaricaly because of floating point precision
        }
    }   
}

    //NOTE: could this be more consise? brobably yes using glm vector operations 
glm::vec3 Renderer::getPointOnImagePlane(const Camera& camera, const unsigned int& pixelX, const unsigned int& pixelY){
    float xScreenPos = camera.getScreenLeftDownCorner().x + camera.getScreenWidth() * (float) pixelX / (float) imageWidth;
    float yScreenPos = camera.getScreenLeftDownCorner().y + camera.getScreenHeight() * (float) pixelY / (float) imageHeight;
    return glm::vec3(xScreenPos, yScreenPos, 0.0f); //assuming the screen is at z = 0 plane TODO: change it for phase 2 
    } //NOTE: should be called viewPlane?

glm::vec3 Renderer::GetColor(const Scene& scene, const Ray& ray, const Hit& hit){
    if(hit.getSceneObject() != nullptr){
        return hit.getSceneObject()->getDiffuseColor(); 
    }
    else{
        return glm::vec3(0.0f, 0.0f, 0.0f); // Black for background
    }
}

unsigned int Renderer::convert3DVectorToByteColor(const glm::vec3& color){
    //clamp the color values between 0 and 255
    unsigned char r = static_cast<unsigned char>(glm::clamp(color.r, 0.0f, 255.0f));
    unsigned char g = static_cast<unsigned char>(glm::clamp(color.g, 0.0f, 255.0f));
    unsigned char b = static_cast<unsigned char>(glm::clamp(color.b, 0.0f, 255.0f));
    return (r << 24) | (g << 16) | (b << 8) | 255; //assuming we want to return a 32 bit color value with alpha channel set to 255
}