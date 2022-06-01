#pragma once

class Vector {
    // Instance Variables
    private:
        float m_x;
        float m_y;

    // Constructor
    public:
        Vector();
        Vector(float x, float y);

    // Accessor Methods
    public:
        float getX();
        float getY();
    
    // Mutator Methods
    public:
        void setXY(float x, float y);

    // Methods that operate on the vector itself
    public:
        void clear();

        void add(float x, float y);
        void add(const Vector& vector);
        
        void scalarMultiply(float scalar);
        void rotate(float radians);   
};