#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin::ECS::Components
{
    struct Transform
    {
        glm::vec2 Position;
        glm::vec2 Scale;
        float Rotation;

        Transform() = default;
        Transform(const Transform &) = default;
        Transform(const glm::vec2 &position, const glm::vec2 &scale, const float rotation)
        {
            Position = position;
            Scale = scale;
            Rotation = rotation;
        }
    };

} // namespace Gin::ECS::Components