#pragma once

namespace math3d 
{
    struct Vector3f 
    {
        Vector3f(float _x, float _y, float _z)
        {
            x = _x;
            y = _y;
            z = _z;

        }

        float x;
        float y;
        float z;
    };

}

