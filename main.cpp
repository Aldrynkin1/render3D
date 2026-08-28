#include <SFML/Graphics.hpp>
#include <iostream>
#include "Render3D.hpp"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{
    Render3D::PixelsBuffer buffer(WIDTH, HEIGHT);
    Render3D::WindowManager window(WIDTH, HEIGHT);
    Render3D::Model3D model;

    if (!model.load_from_file("/Users/alibek/Desktop/render3D/build/l77710-male-base-mesh-6682.obj"))
    {
        std::cerr << "file is closed" << std::endl;
        return 1;
    }
    while (window.is_open())
    {
        window.event_listener();
        buffer.clear_buffer(sf::Color::Black);

        std::vector<Render3D::Model3D::Point2D> screen_points = model.projection(WIDTH, HEIGHT, 400.0f, 4.0f);
        for (const auto &face : model.get_faces())
        {

            auto p1 = screen_points[face.v1];
            auto p2 = screen_points[face.v2];
            auto p3 = screen_points[face.v3];

            buffer.draw_line(p1.x, p1.y, p2.x, p2.y, sf::Color::White);
            buffer.draw_line(p2.x, p2.y, p3.x, p3.y, sf::Color::White);
            buffer.draw_line(p3.x, p3.y, p1.x, p1.y, sf::Color::White);
        }

        window.render(buffer);
    }

    return 0;
}
