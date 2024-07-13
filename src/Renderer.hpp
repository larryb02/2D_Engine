/*
Graphics Pipeline:
    raw data, bind a buffer, send raw data to buffer,

DATA:

Textures
Sprties
Text
we learn as we go...
*/
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glm/glm.hpp>
#include <vector>

namespace Renderer
{
    typedef struct
    {

    } RenderItems;

    typedef struct
    {
        VertexArrayObject();
        const unsigned int ID;
        void createVAO();
    } VertexArrayObject;

    typedef struct
    {
        VertexBufferObject();
        const unsigned int ID;
        void createVAO();
    } VertexBufferObject;

    typedef struct
    {
        ElementBufferObject();
        const unsigned int ID;
        void createEBO();
    } ElementBufferObject;

    std::vector<RenderItems> renderItems;

    void glCheckError(const char *file, const char *line);
}
#endif
