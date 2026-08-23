#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <optional>

namespace Render3D
{
    class PixelsBuffer
    {
    private:
        size_t m_width;
        size_t m_height;
        std::vector<std::uint8_t> m_data;

    public:
        PixelsBuffer(size_t width, size_t height);
        ~PixelsBuffer() = default;
        void clear_buffer(sf::Color color) noexcept;
        const void set_pixel(size_t x, size_t y, sf::Color color) noexcept;
        inline const std::uint8_t *get_data() const { return m_data.data(); };
        inline size_t get_width() const { return m_width; };
        inline size_t get_height() const { return m_height; };
    };

}
