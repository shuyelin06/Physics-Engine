#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "physics/PhysicsObject.hpp" 

class Renderer {
    // Instance Variables
    private:
        sf::Color m_backgroundColor;
        sf::Color m_lineColor;

    public:
        Renderer();
    
    public:
        void render(sf::RenderWindow& window, std::vector< std::unique_ptr<PhysicsObject> >& objects);
};