#pragma once

#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <sstream>
#include <vector>

#include "SFML/Graphics.hpp"

namespace Render3D
{
    class Model3D
    {
    public:
        struct Vector3D
        {
            float x, y, z;
        };

        struct Face
        {
            std::size_t v1, v2, v3;
        };

        struct Point2D
        {
            int x, y;
        };

    private:
        std::string filename;
        std::vector<Face> m_faces;
        std::vector<Vector3D> m_vectors;

    public:
        Model3D() = default;
        ~Model3D() = default;
        bool load_from_file(const std::string &filename);
        std::vector<Point2D> projection(int width, int height, float FOV, float distance);
        inline std::vector<Face> get_faces() { return m_faces; };
        inline std::vector<Vector3D> get_vectors() { return m_vectors; }
    };
}
