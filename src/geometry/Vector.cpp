#include "geometry/Vector.hpp"
#include <math.h>

// Constructors
Vector::Vector() {
    m_x = 0;
    m_y = 0;
}
Vector::Vector(float x, float y) {
    m_x = x;
    m_y = y;
}

// Accessor Methods
float Vector::getX() { return m_x; }
float Vector::getY() { return m_y; }

// Mutator Methods
void Vector::setXY(float x, float y) {
    m_x = x;
    m_y = y;
}

// Helper Methods
void Vector::clear() {
    m_x = 0;
    m_y = 0;
}

void Vector::add(float x, float y) {
    m_x += x;
    m_y += y;
}
void Vector::add(const Vector& vector) {
    m_x += vector.m_x;
    m_y += vector.m_y;
}

void Vector::scalarMultiply(float scalar) {
    m_x *= scalar;
    m_y *= scalar;
}
void Vector::rotate(float radians) {
    float new_x = m_x * cos(radians) - m_y * sin(radians);
    float new_y = m_x * sin(radians) + m_y * cos(radians);

    m_x = new_x;
    m_y = new_y;
}