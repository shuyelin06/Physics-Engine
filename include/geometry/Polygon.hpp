#pragma once

#include "Vector.hpp"

class Polygon {
    // Instance Variables
    private:
        // Array of vertices around some center
        Vector* m_vertices;
        // Number of vertices (for iterations)
        int m_count;

    // Constructor, Destructor
    public:
        Polygon(int vertices);
        ~Polygon();

    // Methods
    public:
        void rotate(float radians);
        
        Vector*& getVertices();

        int countVertices();
        bool isConvex();
};