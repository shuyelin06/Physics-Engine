#include "rendering/Renderer.hpp"

#include "core/Settings.hpp"

Renderer::Renderer() :
    m_backgroundColor( sf::Color::Black ),
    m_lineColor( sf::Color::White )
{}

void Renderer::render(sf::RenderWindow& window, std::vector< std::unique_ptr<PhysicsObject> >& objects) {
    window.clear( m_backgroundColor );

    for( const auto& o: objects ) {
        Vector* vertices = o -> getShape().getVertices();
        int size = o -> getShape().countVertices();

        sf::VertexArray lines(sf::LinesStrip, size);
        for( int i = 0; i < size; i++ ) {
            lines[i] = sf::Vector2f(
                (o -> getX() + vertices[i].getX()) * Settings::Pixels_Per_Unit,
                Settings::Resolution_Y - (o -> getY() + vertices[i].getY()) * Settings::Pixels_Per_Unit
            );
        }

        window.draw(lines);
    }

    window.display();
}