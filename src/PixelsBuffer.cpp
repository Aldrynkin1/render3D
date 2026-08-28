#include "../include/PixelsBuffer.hpp"

namespace Render3D
{
    PixelsBuffer::PixelsBuffer(size_t width, size_t height) : m_width(width), m_height(height)
    {
        m_data.resize(m_width * m_height * 4, 0);
    }

    void PixelsBuffer::clear_buffer(sf::Color color) noexcept
    {
        for (size_t i = 0; i < m_data.size(); i += 4)
        {
            m_data[i] = color.r;     // red
            m_data[i + 1] = color.g; // green
            m_data[i + 2] = color.b; // blue
            m_data[i + 3] = color.a; // alfa (прозрачный)
        }
    }

    void PixelsBuffer::set_pixel(size_t x, size_t y, sf::Color color) noexcept
    {
        if (x >= m_width || y >= m_height)
            return;

        size_t index = (y * m_width + x) * 4;
        m_data[index] = color.r;     // red
        m_data[index + 1] = color.g; // green
        m_data[index + 2] = color.b; // blue
        m_data[index + 3] = color.a; // alfa (прозрачный)
    }

    void PixelsBuffer::draw_line(int x1, int y1, int x2, int y2, sf::Color color) noexcept
    {
        int direct_x = x1 - x2;
        if (direct_x < 0)
        {
            direct_x = -direct_x;
        }

        int direct_y = y1 - y2;
        if (direct_y < 0)
        {
            direct_y = -direct_y;
        }

        int side_x = (x1 < x2) ? 1 : -1;
        int side_y = (y1 < y2) ? 1 : -1;

        int err = direct_x - direct_y;

        while (true)
        {
            if (x1 >= 0 && y1 >= 0)
            {
                set_pixel(static_cast<size_t>(x1), static_cast<size_t>(y1), color);
            }
            if (x1 == x2 && y1 == y2)
                break;
            int next_pixel = err * 2;

            if (next_pixel > -direct_y)
            {
                err -= direct_y;
                x1 += side_x;
            }
            if (next_pixel < direct_x)
            {
                err += direct_x;
                y1 += side_y;
            }
        }
    }
}