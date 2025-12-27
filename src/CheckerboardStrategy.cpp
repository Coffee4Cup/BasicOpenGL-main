#include "CheckerboardStrategy.h"

CheckerboardStrategy::CheckerboardStrategy(const glm::vec3& color, float scale) 
    : m_color(color), m_scaleParameter(scale) {}

glm::vec3 CheckerboardStrategy::getColor(const glm::vec3& point) const {
    float checkerboard = 0.0f;

    if (point.x < 0.0f) {
        checkerboard += glm::floor((0.5f - point.x) / m_scaleParameter);
    } else {
        checkerboard += glm::floor(point.x / m_scaleParameter);
    }

    if (point.z < 0.0f) {
        checkerboard += glm::floor((0.5f - point.z) / m_scaleParameter);
    } else {
        checkerboard += glm::floor(point.z / m_scaleParameter);
    }

    float pattern = (checkerboard * 0.5f) - static_cast<int>(checkerboard * 0.5f);
    pattern *= 2.0f;

    if (pattern > 0.5f) {
        return 0.5f * m_color;
    }
    return m_color;
}