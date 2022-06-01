#include "physics/PhysicsObject.hpp"

// Constructor
PhysicsObject::PhysicsObject()
    : m_shape(4), 
        m_theta(0), m_omega(0), m_alpha(0), 
        m_mass(1), m_inertia(1) {}

// Destructor
PhysicsObject::~PhysicsObject() {
    m_shape.~Polygon(); // Delete the polygon vertex array
}

// Update Method
void PhysicsObject::update() {
    m_velocity.add(m_acceleration); // Update Velocity
    m_position.add(m_velocity); // Update Position
    m_acceleration.clear(); // Clear Acceleration

    m_omega += m_alpha; // Update Omega
    m_shape.rotate(m_omega); m_theta += m_omega; // Update Theta and Shape's Theta
    m_alpha = 0.f; // Clear Alpha
}

// Add Forces
void PhysicsObject::addForce(float forceX, float forceY) {
    m_acceleration.add(forceX / m_mass, forceY / m_mass);
}

// Accessor Methods
Polygon& PhysicsObject::getShape() { return m_shape; }

float PhysicsObject::getX() { return m_position.getX(); }
float PhysicsObject::getY() { return m_position.getY(); }

// Mutator Methods
PhysicsObject& PhysicsObject::setMass(float mass) { m_mass = mass; return *this; }
PhysicsObject& PhysicsObject::setInertia(float inertia) { m_inertia = inertia; return *this; }

PhysicsObject& PhysicsObject::setPosition(float x, float y) { m_position.setXY(x, y); return *this; }
PhysicsObject& PhysicsObject::setVelocity(float x, float y) { m_velocity.setXY(x, y); return *this; }
PhysicsObject& PhysicsObject::setAcceleration(float x, float y) { m_acceleration.setXY(x, y); return *this; }

PhysicsObject& PhysicsObject::setTheta(float theta) { m_theta = theta; return *this; }
PhysicsObject& PhysicsObject::setOmega(float omega) { m_omega = omega; return *this; }
PhysicsObject& PhysicsObject::setAlpha(float alpha) { m_alpha = alpha; return *this; }