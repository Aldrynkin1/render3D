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

    const void PixelsBuffer::set_pixel(size_t x, size_t y, sf::Color color) noexcept
    {
        if (x >= m_width || y >= m_height) return;

        size_t index = (y * m_width + x) * 4;
        m_data[index] = color.r;     // red
        m_data[index + 1] = color.g; // green
        m_data[index + 2] = color.b; // blue
        m_data[index + 3] = color.a; // alfa (прозрачный)
    }
    
}