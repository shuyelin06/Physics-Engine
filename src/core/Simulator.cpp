#include "core/Simulator.hpp"
#include "core/Settings.hpp"

#include <iostream>

Simulator::Simulator(std::string name) :
    m_window(sf::VideoMode(Settings::Resolution_X, Settings::Resolution_Y), name ),
    m_objects(),
    m_renderer()
{
    m_active = true;
    m_window.setFramerateLimit(Settings::Frames_Per_Second);

    std::cout << "Creating Object";

    for( int i = 0; i < Settings::Object_Count; i++ ) {
        std::unique_ptr<PhysicsObject> object(new PhysicsObject());

        object -> setVelocity(0.05f, 0.05f);
        object -> setOmega(0.015f);
        
        m_objects.push_back( std::move(object) );
    }

    std::cout << "Simulator Created";
}

auto& Simulator::getWindow() { return m_window; }
auto& Simulator::getObjects() { return m_objects; }

bool Simulator::isActive() { return m_active; }
void Simulator::update() {
    if( m_window.isOpen() ) {
        // Event Polling
        sf::Event event;
        while( m_window.pollEvent(event) ) {
            if( event.type == sf::Event::Closed ) {
                m_window.close(); // Close window
                m_active = false; // Set simulator as inactive
            } 
        }

        // Manager Updates
        // Force Manager
        // Collision Manager

        // Object Updating
        for(auto& o: m_objects) { o -> update(); }

        // Rendering
        m_renderer.render(m_window, m_objects);
    }
}