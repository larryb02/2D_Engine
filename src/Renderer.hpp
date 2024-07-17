
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glm/glm.hpp>
#include <vector>

namespace Renderer
{
    typedef struct RenderItems
    {
        void createRenderItems();
    } RenderItems;

    class SpriteRenderer
    {

    };

    void ClearBuffer();
    void CheckError(const char *file, const char *line);
}
#endif
