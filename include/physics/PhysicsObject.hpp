#pragma once

#include "geometry/Polygon.hpp"
#include "geometry/Vector.hpp"

class PhysicsObject {
    // Member Variables
    protected:
        // Shape of the Object
        Polygon m_shape;
        
        // Linear
        Vector m_position; // Center Position (m)
        Vector m_velocity; // Velocity (m / s)
        Vector m_acceleration; // Acceleration (m / s^2) 
        
        // Angular
        float m_theta; // Angular Position (rad)
        float m_omega; // Angular Velocity (rad / sec)
        float m_alpha; // Angular Acceleration (rad / sec^2)

        // Other Variables
        float m_mass; // Mass
        float m_inertia; // Inertia

    // Constructor
    public:
        PhysicsObject();
        ~PhysicsObject();

    // Main Methods
    public:
        void update();
        void addForce(float forceX, float forceY);

    // Accessor Methods
    public:
        Polygon& getShape();

        float getX();
        float getY();
    
    // Mutator Methods
    public: 
        PhysicsObject& setMass(float mass);
        PhysicsObject& setInertia(float inertia);

        PhysicsObject& setPosition(float x, float y);
        PhysicsObject& setVelocity(float x, float y);
        PhysicsObject& setAcceleration(float x, float y);
        
        PhysicsObject& setTheta(float theta);
        PhysicsObject& setOmega(float omega);
        PhysicsObject& setAlpha(float alpha);
};