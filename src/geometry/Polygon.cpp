#include "geometry/Polygon.hpp"

// Constructor
Polygon::Polygon(int vertices) {
    m_count = 5;

    // Temp
    m_vertices = new Vector[5]; // new Vector[vertices]

    m_vertices[0] = Vector(-3, -3);
    m_vertices[1] = Vector(-3, 3);
    m_vertices[2] = Vector(3, 3);
    m_vertices[3] = Vector(3, -3);
    m_vertices[4] = Vector(-3, -3);
}

// Destructor
Polygon::~Polygon() {
    delete[] m_vertices;
}

// Methods
void Polygon::rotate(float radians) { // Rotate all vertices in the polygon
    for( int i = 0; i < m_count; i++ ) {
        m_vertices[i].rotate(radians);
    }
}

Vector*& Polygon::getVertices() { return m_vertices; }

int Polygon::countVertices() { return m_count; }
bool Polygon::isConvex() { // WIP, all Polygons (for now) assumed to be convex
    return true;
}
