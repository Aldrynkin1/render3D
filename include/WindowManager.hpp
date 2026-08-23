#include "SFML/Graphics.hpp"
#include "PixelsBuffer.hpp"

namespace Render3D
{
    class PixelsBuffer;
    class WindowManager
    {
    private:
        sf::RenderWindow m_window;
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        unsigned int m_width;
        unsigned int m_height;

    public:
        WindowManager(unsigned int width, unsigned int height);
        ~WindowManager() = default;
        
        void event_listener();
        void render(const PixelsBuffer &buffer);

        inline bool is_open() const { return true ? m_window.isOpen() : false; };
    };

}
