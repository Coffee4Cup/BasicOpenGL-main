#pragma once
#include "ITextureStrategy.h"

class SolidColorStrategy : public ITextureStrategy {
private:
    glm::vec3 m_color;
public:
    SolidColorStrategy(const glm::vec3& color);
    glm::vec3 getColor(const glm::vec3& point) const override;
};