#include "Renderer.h"

void Renderer::render(){
    Hit hit;
    Ray ray;
    glm::vec3 color;
    ray.setOrigin(camera.getPosition()); // the origin of the ray is the camera position
    for(unsigned int y = 0; y < imageHeight; y++){
        for(unsigned int x = 0; x < imageWidth; x++){
            constructRayThroughPixel(ray, camera, x, y);
            findIntersection(hit, ray, currentScene);
            
            GetColor(color, currentScene, ray, hit);
            unsigned int pixelIndex = (y * imageWidth + x) * REQUIRED_COMPONENTS;
            
            finalImagebuffer[pixelIndex + 0] = static_cast<unsigned char>(glm::clamp(color.r, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 1] = static_cast<unsigned char>(glm::clamp(color.g, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 2] = static_cast<unsigned char>(glm::clamp(color.b, 0.0f, 255.0f));
            finalImagebuffer[pixelIndex + 3] = 255; // Alpha channel
        }
    }
}


const unsigned char* Renderer::getFinalImage() const {
    return finalImagebuffer.data();
}
void Renderer::constructRayThroughPixel(Ray& ray, const Camera& camera, const unsigned int& pixelX, const unsigned int& pixelY){
 
    glm::vec3 pixelPoint = getPointOnImagePlane(pixelX, pixelY);
 
    ray.setDirection(glm::normalize(pixelPoint - camera.getPosition())); 
}

void Renderer::findIntersection(Hit& hit, const Ray& ray, const Scene& scene){
    float currentT = std::numeric_limits<float>::max(), minT = std::numeric_limits<float>::max();
    hit.setSceneObject(nullptr);
    const std::vector<SceneObject*>& sceneObjects = scene.getSceneObjects();
    for(const SceneObject* obj : sceneObjects){
        currentT = obj->intersect(ray);
        if(currentT >= 0.0f && currentT < minT){
            minT = currentT;
            hit.setSceneObject(obj);
            hit.setParamtricRayValue(minT);
            hit.setPoint(ray.pointAt(minT)); //TODO: check if this is doesnt cause issues numaricaly because of floating point precision
        }
    }   
}

    //NOTE: could this be more consise? brobably yes using glm vector operations 
glm::vec3 Renderer::getPointOnImagePlane(const unsigned int& pixelX, const unsigned int& pixelY){
    return viewPlaneCenter + xCoefficient * (float)pixelX - xTerm - yCoefficient * (float)pixelY + yterm;
}

void Renderer::GetColor(glm::vec3& color, const Scene& scene, const Ray& ray, const Hit& hit){
    color = glm::vec3(0.0f); //Sets the color to be black
    if(hit.getSceneObject() != nullptr){
        for(Light *light : scene.getLights()){
            color += light->getDiffiusion(hit, scene);
            color += light->getSpecular(hit, scene, ray);
        
        }
    }
}

unsigned int Renderer::convert3DVectorToByteColor(const glm::vec3& color){
    //clamp the color values between 0 and 255
    unsigned char r = static_cast<unsigned char>(glm::clamp(color.r, 0.0f, 255.0f));
    unsigned char g = static_cast<unsigned char>(glm::clamp(color.g, 0.0f, 255.0f));
    unsigned char b = static_cast<unsigned char>(glm::clamp(color.b, 0.0f, 255.0f));
    return (r << 24) | (g << 16) | (b << 8) | 255; //assuming we want to return a 32 bit color value with alpha channel set to 255
}