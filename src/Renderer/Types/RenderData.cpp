#include "RenderData.hpp"

RenderData::RenderData(float vertices[])
{
    this->m_indices = sizeof(vertices); // as long as vertices doesnt decay this should work? we'll see

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // configure VAO

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

RenderData::RenderData(float vertices[], glm::vec3 rgb)
{
    this->m_indices = sizeof(vertices);
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // configure VAO

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

RenderData::RenderData(float vertices[], glm::vec3 rgb, glm::vec2 texCords)
{
    this->m_indices = sizeof(vertices);
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // configure VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

VertexAttrib::VertexAttrib(const unsigned int stride, const unsigned int offset, const unsigned int index)
{
    this->m_Index = index;
    this->m_Offset = offset;
    this->m_Stride = stride;
}

void VertexAttrib::setAttrib(const unsigned int index, const unsigned int size)
{
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, this->m_Stride * sizeof(float),
                          (void *)(this->m_Offset * sizeof(float)));
    glEnableVertexAttribArray(index);
}