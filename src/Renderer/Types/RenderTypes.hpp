#ifndef RENDERDATA_HPP
#define RENDERDATA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../ResourceManager/Texture.hpp"
#include "../../Shader.hpp"

// i want this to contain all potential buffers, textures, and shaders needed to render an item so i can just pass a list of these to renderer
// the user should understand the format of their data or have a file with the data, so all they have to do is pass that, then renderer handles rest :)

// create multiple constructors

// wrap in a namespace? probly just wrap in renderer namespace if i were to do so

// concerns:
typedef struct Vertex
{
    Vertex(float x, float y, float z);
    glm::vec3 pos;
} Vertex;

class RenderData
{
public:
    // constructors
    RenderData(std::vector<float> &vertices); 
    RenderData(std::vector<Vertex> &vertices); 
    // accessors
    unsigned int getVAO() const;
    unsigned int getVertexCount() const;

private:
    unsigned int m_vao, m_vbo, m_vertexCount;
};

#endif