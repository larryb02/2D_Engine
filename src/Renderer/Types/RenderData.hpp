#ifndef RENDER_DATA_HPP
#define RENDER_DATA_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../Texture.hpp"
#include "../../Shader.hpp"


//i want this to contain all potential buffers, textures, and shaders needed to render an item so i can just pass a list of these to renderer
//the user should understand the format of their data so all they have to do is pass that, then renderer handles rest :)

//make sure i can track num of VAO attributes, possibly just make VAO an object as well
//create multiple constructors 

//wrap in a namespace? probly just wrap in renderer namespace if i were to do so

class RenderData
{
    public:
        RenderData(float vertices[]);
        RenderData(float vertices[], glm::vec3 rgb);
        RenderData(float vertices[], glm::vec3 rgb, glm::vec2 texCords);
        unsigned int getVAO()const;
        unsigned int getVBO()const;
        unsigned int getEBO()const;
    private:
        unsigned int m_VAO, m_VBO, m_EBO, m_indices;
        Shader *m_shader;
        Texture *m_tex;
};

typedef struct VertexAttrib //allows for ease of mapping out attributes
{
    unsigned int m_Stride, m_Offset, m_Index;
    VertexAttrib(const unsigned int stride, const unsigned int offset, const unsigned int index); //construct attr
    void setAttrib(const unsigned int index, const unsigned int size);

} VertexAttrib;

typedef struct ElementBuffer
{
    unsigned int m_Indices, m_ID;
    ElementBuffer(const unsigned int indices);
} ElementBuffer;
#endif