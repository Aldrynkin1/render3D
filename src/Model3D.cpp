#include "../include/Model3D.hpp"

namespace Render3D
{
    bool Model3D::load_from_file(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "file is closed in Model3D::load_from_file" << std::endl;
            return false;
        }

        std::string str;
        std::cout << str << std::endl;

        while (std::getline(file, str))
        {
            std::stringstream ss(str);
            std::string type;
            ss >> type;

            if (type == "v")
            {
                float x, y, z;
                ss >> x >> y >> z;

                m_vectors.push_back({x, y, z});
            }
            else if (type == "f")
            {
                size_t v1, v2, v3;
                ss >> v1 >> v2 >> v3;
                v1--;
                v2--;
                v3--;
                m_faces.push_back({v1, v2, v3});
            }
        }

        return true;
    }

    std::vector<Model3D::Point2D> Model3D::projection(int width, int height, float FOV, float distance)
    {
        std::vector<Point2D> screen_points;

        for (const auto &pair : m_vectors)
        {
            float projected_z = pair.z + distance;

            if (projected_z <= 0.1f)
            {
                projected_z = 0.1f;
            }

            int x_screen = static_cast<int>((pair.x * FOV) / projected_z) + (width / 2);
            int y_screen = static_cast<int>((pair.y * FOV) / projected_z) + (height / 2);

            screen_points.push_back({x_screen, y_screen});
        }

        return screen_points;
    }
}