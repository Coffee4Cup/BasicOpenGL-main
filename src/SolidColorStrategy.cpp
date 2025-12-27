#include "SolidColorStrategy.h"

SolidColorStrategy::SolidColorStrategy(const glm::vec3& color) : m_color(color) {}

glm::vec3 SolidColorStrategy::getColor(const glm::vec3& point) const {
    (void)point; // point is unused for solid color
    return m_color;
}