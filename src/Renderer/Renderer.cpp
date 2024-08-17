#include "Renderer.hpp"
#include "../Scene/Scene.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

void Renderer::ClearBuffer(glm::vec3 color) //FIX
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

void Renderer::Render(Shader &shader, Scene *scene)
{   
    //need a reference to current loaded scene, get information from there
    //Scene ref, current Scene.createRenderData(), boom
    //glm::mat4 projection;
    //, view, model;
    
    //std::vector<glm::vec3> pos = {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)};
    // 
    // projection = glm::mat4(1.0f);
    // projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, 0.1f, 100.0f);
    // projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
    // projection = glm::perspective(60.0f, 1366.0f/ 768.0f, 0.1f, 100.0f);
    
    //view = glm::mat4(1.0f);
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    // view = glm::lookAt( glm::vec3( 0.f, 0.f, 2.0f ),glm::vec3( 0.0f, 0.0f, 0.0f ),glm::vec3( 0.0f, 1.0f, 0.0f ) );
    std::vector<RenderData> rd = scene->createRenderData();
    
    
    for (int i = 0; i < rd.size(); i++)
    {
        // model = glm::mat4(1.0f);
        // model = glm::scale(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::translate(model, glm::vec3(0.3f, -0.3f, 0.0f));
        shader.Use();
        shader.setMat4("projection", scene->getProjectionMatrix());
        shader.setMat4("view", scene->getCamera().getView());
        shader.setMat4("model", rd[i].getModel());
        // bind vao
        glBindVertexArray(rd[i].getVAO());
        glDrawArrays(GL_TRIANGLES, 0, rd[i].getVertexCount());
        // glBindVertexArray(0);
        CheckError();
    }
}
