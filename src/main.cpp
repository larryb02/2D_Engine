// #include <iostream>
// #include <SDL2/SDL.h>
// #include <glad/glad.h>
#include <math.h>
#include <filesystem>
#include "Shader.hpp"
#include "Game.hpp"
#include <stb_image/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int c, char **argv)
{
    std::cout << "Current working directory: " << std::__fs::filesystem::current_path() << std::endl;

    Game::Init();

    Shader myShader("shaders/vertex.glsl", "shaders/fragment.glsl");

    float vertices[] = {
        // positions     // texture coords
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
    };

    // float vertices[] = {
    //     0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    //     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    //     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    //     -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f};

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3};

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    std::cout << "Gen Vertex Arrays: " << glGetError() << std::endl;

    glGenBuffers(1, &VBO);
    std::cout << "Gen VBO Buffers: " << glGetError() << std::endl;

    glGenBuffers(1, &EBO);
    std::cout << "Gen EBO Buffers " << glGetError() << std::endl;

    glBindVertexArray(VAO);
    std::cout << "Bind VAO " << glGetError() << std::endl;

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    std::cout << "Bind VBO " << glGetError() << std::endl;

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    std::cout << "vertex buffer data " << glGetError() << std::endl;

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    std::cout << "Bind EBO " << glGetError() << std::endl;

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    std::cout << "index buffer data " << glGetError() << std::endl;

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    std::cout << "Init VAO[0] " << glGetError() << std::endl;

    glEnableVertexAttribArray(0);
    std::cout << "Enable VAO[0] " << glGetError() << std::endl;

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    std::cout << "Init VAO[1] " << glGetError() << std::endl;

    glEnableVertexAttribArray(1);
    std::cout << "Enable VAO[1] " << glGetError() << std::endl;

    // glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
    // std::cout << "Init VAO[2] " << glGetError() << std::endl;
    // glEnableVertexAttribArray(2);
    // std::cout << "Enable VAO[2] " << glGetError() << std::endl;

    unsigned int texture[2];
    glGenTextures(2, texture);
    // glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *texData = stbi_load("./res/container.jpg", &width, &height, &nrChannels, 0);
    if (texData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Unable to load texture..." << std::endl;
    }

    stbi_image_free(texData);

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    width = height = nrChannels = 0;
    stbi_set_flip_vertically_on_load(true);
    texData = stbi_load("./res/awesomeface.png", &width, &height, &nrChannels, 0);

    if (texData)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Unable to load texture..." << std::endl;
    }

    stbi_image_free(texData);

    myShader.Use();
    myShader.setInt("texture1", 0);
    myShader.setInt("texture2", 1);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    // glm::mat4 trans = glm::mat4(1.0f);
    // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    // trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    // trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    // trans = glm::rotate(trans, ((float)(SDL_GetTicks() / 1000.0f)), glm::vec3(0.0f, 0.0f, 1.0f));

    // vec = trans * vec;
    // std::cout << vec.x << " " << vec.y << " " << vec.z << std::endl;

    while (Game::_gState == Game::RUNNING) //ik its bad, this will be fixed
    {

        Game::processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture[1]);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, ((float)(SDL_GetTicks() / 1000.0f)), glm::vec3(0.0f, 0.0f, 1.0f));

        myShader.Use();
        unsigned int transformLoc = glGetUniformLocation(myShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        Game::Update();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    Game::Quit();
    return EXIT_SUCCESS;
}