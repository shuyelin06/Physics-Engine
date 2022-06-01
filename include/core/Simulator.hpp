#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

#include "physics/PhysicsObject.hpp"
#include "rendering/Renderer.hpp"

class Simulator {
    // Instance Variables
    private:
        sf::RenderWindow m_window; // Window
        std::vector< std::unique_ptr<PhysicsObject> > m_objects; // Array of Objects
        
        Renderer m_renderer; // Rendering
        
        bool m_active; // If simulation is active or not

    // Constructor
    public:
        Simulator(std::string name);
    
    // Methods
    public:
        void update();

        auto& getWindow();
        auto& getObjects();

        bool isActive();
};