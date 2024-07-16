
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glm/glm.hpp>
#include <vector>

namespace Renderer
{
    typedef struct RenderData
    {
        void createRenderData();
    } RenderData;


    void ClearBuffer();
    void CheckError(const char *file, const char *line);
}
#endif
