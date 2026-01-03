#pragma once
#include <glm/glm.hpp>
#include "ITextureStrategy.h"

class Ray; 

class SceneObject {
  private:
   static constexpr glm::vec3 DEFULT_SPECULAR_COEFFICENT = glm::vec3(0.7f);
   static constexpr glm::vec3 BASE_SPECULAR_COLOR = glm::vec3(255.0f, 255.0f, 255.0f); //NOTE: not sure where this best be 
  protected:
  float shininess;
  ITextureStrategy* m_textureStrategy;
   public:
   SceneObject(ITextureStrategy* textureStrategy, float shininess = 10.0f) : m_textureStrategy(textureStrategy), shininess(shininess) {}
    virtual ~SceneObject() { delete m_textureStrategy; }
      /***
     * Intersects the ray with the scene object.
     * @param ray The ray to intersect with.
     * @return The hit information if the ray intersects the object, otherwise std::nullopt.
     */
    virtual float intersect(const Ray& ray) const = 0;
    virtual glm::vec3 getNormalAt(const glm::vec3& point) const = 0;

    glm::vec3 getDiffuseColor(const glm::vec3& point) const;
    float getShininess() const { return shininess; }
    glm::vec3 getReflectionVector(const glm::vec3& point, const glm::vec3& incidentVector) const;
    glm::vec3 getSpecularCoefficent() const {return DEFULT_SPECULAR_COEFFICENT;} //the K_s in the eqauations
    glm::vec3 getSpecularColor() const { return BASE_SPECULAR_COLOR; }

};