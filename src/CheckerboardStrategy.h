#pragma once
#include "ITextureStrategy.h"

class CheckerboardStrategy : public ITextureStrategy {
private:
    glm::vec3 m_color;
    float m_scaleParameter;
public:
    CheckerboardStrategy(const glm::vec3& color, float scale = 0.5f);
    glm::vec3 getColor(const glm::vec3& point) const override;
};