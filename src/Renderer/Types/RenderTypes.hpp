#ifndef RENDERDATA_HPP
#define RENDERDATA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../Texture.hpp"
#include "../../Shader.hpp"

// i want this to contain all potential buffers, textures, and shaders needed to render an item so i can just pass a list of these to renderer
// the user should understand the format of their data or have a file with the data, so all they have to do is pass that, then renderer handles rest :)

// make sure i can track num of VAO attributes, possibly just make VAO an object as well
// create multiple constructors

// wrap in a namespace? probly just wrap in renderer namespace if i were to do so

// concerns:

// THINK IMA REMOVE
//  typedef struct VertexAttrib // allows for ease of mapping out attributes
//  {
//      unsigned int m_stride, m_offset, m_index;
//      VertexAttrib(const unsigned int stride, const unsigned int offset, const unsigned int index); // construct attr
//      void setAttrib(const unsigned int index, const unsigned int size);

// } VertexAttrib;


class RenderData
{
public:
    // constructors
    RenderData(std::vector<float> &vertices); // should end up being std::vector<Vertex> vertices
    // probly removing
    // RenderData(float vertices[], glm::vec3 rgb);
    // RenderData(float vertices[], glm::vec3 rgb, glm::vec2 texCords);
    // accessors
    unsigned int getVAO() const;
    unsigned int getVertexCount() const;

private:
    unsigned int m_vao, m_vbo, m_ebo, m_vertexCount;
    Shader *m_shader;
    Texture *m_tex;
    
};

#endif