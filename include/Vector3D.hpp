#include <string>
#include <vector>
#include <optional>
#include <string_view>

namespace Render3D {
    class Vector3D
    {
    private:
    int x;
    int y;
    int z;
    public:
        Vector3D();
        ~Vector3D();
        void create_3d_object(FILE *file);
    };
    
    Vector3D::Vector3D()
    {
    }
    
    Vector3D::~Vector3D()
    {
    }
    
}