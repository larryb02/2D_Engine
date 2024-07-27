#include "Renderer.hpp"
#include <iostream>

void Renderer::ClearBuffer(glm::vec3 color)
{
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLenum Renderer::CheckError_(const char *file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
        case GL_INVALID_ENUM:
            error = "INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "INVALID_OPERATION";
            break;
        case GL_STACK_OVERFLOW:
            error = "STACK_OVERFLOW";
            break;
        case GL_STACK_UNDERFLOW:
            error = "STACK_UNDERFLOW";
            break;
        case GL_OUT_OF_MEMORY:
            error = "OUT_OF_MEMORY";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "INVALID_FRAMEBUFFER_OPERATION";
            break;
        }
        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
    }
    return errorCode;
}

void Renderer::Render(std::vector<RenderData> &rd)
{   
    Shader shader("shaders/BasicVertexShader.glsl", "shaders/BasicFragmentShader.glsl");
    for (int i = 0; i < rd.size(); i++)
    {
        shader.Use();
        // bind vao
        glBindVertexArray(rd[i].getVAO());
        // handle shader things
        // change shader approach? yea... probably

        // handle texture things
        glDrawArrays(GL_TRIANGLES, 0, rd[i].getVertexCount());
        CheckError();
    }
}
