#include "RenderData.hpp"

RenderData::RenderData(float vertices[])
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);

    //configure VAO
};