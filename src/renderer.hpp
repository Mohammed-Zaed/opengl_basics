#pragma once

#include "GL/glew.h"
#include "math3d.hpp"
#include "triangle.hpp"

namespace renderer
{

    void init() 
    {
        triangle::init();
    }

    void render()
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        triangle::render();
    }

    void cleanUp()
    {
        triangle::cleanUp();
    }

}