#include <SFML/Graphics.hpp>
#include <iostream>
#include "WindowManager.hpp"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main() {
    Render3D::PixelsBuffer buffer(WIDTH, HEIGHT);
    Render3D::WindowManager window(WIDTH, HEIGHT);

    while (window.is_open()) {
        window.event_listener();
        buffer.clear_buffer(sf::Color::Blue);
        for (int i = 0; i < 1200; i++) {
            buffer.set_pixel(0 + i, 0 + i, sf::Color::Yellow);
        }
        window.render(buffer);
    }

    return 0;
}
