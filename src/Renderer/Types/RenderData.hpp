#ifndef RENDER_DATA_HPP
#define RENDER_DATA_HPP

#include <glad/glad.h>
#include "../../Texture.hpp"

//i want this to contain all potential buffers, so i can just pass a list of these to renderer
//the user should understand the format of their data so all they have to do is pass that, then renderer handles rest :)

//make sure i can track num of VAO attributes, possibly just make VAO an object as well
class RenderData
{
    public:
        RenderData(float vertices[]);
        unsigned int getVAO()const;
        unsigned int getVBO()const;
        unsigned int getEBO()const;
    private:
        unsigned int m_VAO, m_VBO, m_EBO, m_indices;
        Texture *m_texture;
};

typedef struct VertexAttrib //allows for ease of mapping out attributes
{
    unsigned int m_Stride, m_Offset, m_Index;

} VertexAttrib;

typedef struct ElementBuffer
{
    unsigned int m_Indices, m_ID;
} EBO;
#endif