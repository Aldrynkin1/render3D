#include "../include/WindowManager.hpp"
#include "../include/PixelsBuffer.hpp"

namespace Render3D
{
    WindowManager::WindowManager(unsigned int width, unsigned int height) : m_width(width), m_height(height), m_sprite(m_texture)
    {

        m_window.create(sf::VideoMode({m_width, m_height}), "3D_RENDER");
        m_window.setFramerateLimit(60);

        m_texture.resize({m_width, m_height});

        m_sprite.setTextureRect(sf::IntRect({0, 0}, {static_cast<int>(width), static_cast<int>(height)}));
    }

    void WindowManager::event_listener()
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
               m_window.close();
            }
        }
    }

    void WindowManager::render(const PixelsBuffer &buffer) {
        m_texture.update(buffer.get_data());

        m_window.clear();
        m_window.draw(m_sprite);
        m_window.display();
    }
}