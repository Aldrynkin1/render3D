#pragma once

#include <SFML/Graphics.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Render3D
{
    class PixelsBuffer
    {
    private:
        std::size_t m_width;
        std::size_t m_height;
        std::vector<std::uint8_t> m_data;

    public:
        PixelsBuffer(std::size_t width, std::size_t height);
        ~PixelsBuffer() = default;
        void clear_buffer(sf::Color color) noexcept;
        void set_pixel(std::size_t x, std::size_t y, sf::Color color) noexcept;
        void draw_line(int x1, int y1, int x2, int y2, sf::Color color) noexcept;
        inline const std::uint8_t *get_data() const { return m_data.data(); }
        inline std::size_t get_width() const { return m_width; }
        inline std::size_t get_height() const { return m_height; }
    };
}
