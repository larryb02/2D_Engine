#include "RenderTypes.hpp"
// #include <cstddef>


RenderData::RenderData(std::vector<float> &vertices) //basic object
{
    this->m_vertexCount = vertices.size()/2;
    glGenVertexArrays(1, &this->m_vao);
    glGenBuffers(1, &this->m_vbo);
    glBindVertexArray(this->m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

unsigned int RenderData::getVAO() const
{
    return this->m_vao;
}


unsigned int RenderData::getVertexCount() const
{
    return this->m_vertexCount;
}

// TODO: If i decide there is a need for these i will implement

// RenderData::RenderData(float vertices[], glm::vec3 rgb)
// {
//     this->m_indices = sizeof(vertices);
//     glGenVertexArrays(1, &m_vao);
//     glGenBuffers(1, &m_vbo);
//     glBindVertexArray(m_vao);
//     glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     // configure VAO

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

// RenderData::RenderData(float vertices[], glm::vec3 rgb, glm::vec2 texCords)
// {
//     this->m_indices = sizeof(vertices);
//     glGenVertexArrays(1, &m_vao);
//     glGenBuffers(1, &m_vbo);
//     glBindVertexArray(m_vao);
//     glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     // configure VAO
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

// REWRITE
//  VertexAttrib::VertexAttrib(const unsigned int stride, const unsigned int offset, const unsigned int index)
//  {
//      this->m_index = index;
//      this->m_offset = offset;
//      this->m_stride = stride;
//  }

// void VertexAttrib::setAttrib(const unsigned int index, const unsigned int size) //just need to make sure im updating the correct VAO
// {
//     glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(Vertex),
//                           (void *)(offsetof(Vertex, pos) * sizeof(Vertex)));
//     glEnableVertexAttribArray(index);
// }