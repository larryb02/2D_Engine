// move this directory out of src...

#include <math.h>
#include <filesystem>
#include "../Engine.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Scene/Entity.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/SceneManager.hpp"


#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
// #include <glm/gtc/type_ptr.hpp>

/*
Tasks:
CONVERT TO SCENE
1. Create movable "player"
2. Create a background... tentative
3. Create a level
*/

typedef struct Player
{
    Player(Entity *entity)
    {
        m_playerEntity = entity;
        pos = glm::vec3(0.0f); // start at origin.
        model = glm::mat4(1.0f);
        /*m_vertexData = m_playerEntity.getVertices(); //real world would just pass 'renderData'*/
        velX = velY = 0.0f;
    };
    void handleInput()
    {
        if (Input::keyPressed(SDL_SCANCODE_W))
        {
            // std::cout << "w key pressed" << std::endl;
            velY += 0.01f;
            // p1.pos.y += 0.01f;
        }
        if (Input::keyPressed(SDL_SCANCODE_A))
        {
            // std::cout << "a key pressed" << std::endl;
            velX -= 0.01f;
            // p1.pos.x -= 0.01f;
        }
        if (Input::keyPressed(SDL_SCANCODE_S))
        {
            // std::cout << "s key pressed" << std::endl;
            velY -= 0.01f;
            // p1.pos.y -= 0.01f;
        }
        if (Input::keyPressed(SDL_SCANCODE_D))
        {
            // std::cout << "d key pressed" << std::endl;
            velX += 0.01f;
            // p1.pos.x += 0.01f;
        }
    };
    void Update()
    {
        pos.x += velX;
        pos.y += velY;
        /*this->model = glm::translate(model, velocity);*/
        m_playerEntity->updatePosition(velX, velY);
        /*std::cout << glm::to_string(m_playerEntity.getModelMatrix()) << std::endl;*/
        velX = velY = 0.0f;
        std::cout << "x: " << pos.x << " | " << "y: " << pos.y << std::endl;
    };
    /*std::vector<Vertex> m_vertexData;*/
    glm::vec3 pos;
    glm::mat4 model;
    float velX;
    float velY;
    Entity *m_playerEntity;
} Player;

int main(int c, char **argv)
{
    std::cout << "Current working directory: " << std::__fs::filesystem::current_path() << std::endl;
    Engine::Init(0, 0, "");
    Shader shader("shaders/BasicVertexShader.glsl", "shaders/BasicFragmentShader.glsl");
    // 
    /*std::vector<Vertex> playerData{Vertex(-0.25f, -0.25f, 0.0f),*/
    /*                               Vertex(-0.25f, 0.25f, 0.0f),*/
    /*                               Vertex(0.25f, -0.25f, 0.0f),*/
    /*                               Vertex(0.25f, 0.25f, 0.0f),*/
    /*                               Vertex(-0.25f, 0.25f, 0.0f),*/
    /*                               Vertex(0.25f, -0.25f, 0.0f)};*/
    /**/
    /*Player p1(playerData);*/
    //    glm::mat4 view = glm::mat4(1.0f);
    //    glm::vec3 position = glm::vec3(0.0f, 0.0f, -0.3f);
    //    Camera gameCamera(view, position);
    // Entity playerEntity(std::string("player"));
    Scene exampleScene("Sandbox", -2.0f, +2.0f, -1.5f, +1.5f);
    SceneManager::loadScene("Sandbox");
    // add background to scene
    // add player to scene
    // add enemy to scene
    Entity backgroundEntity("background", {Vertex(1.0f, 1.0f, 0.0f),
            Vertex(1.0f, 1.0f, 0.0f),
            Vertex(1.0f, 1.0f, 0.0f),
            Vertex(1.0f, 1.0f, 0.0f),
            Vertex(1.0f, 1.0f, 0.0f),
            Vertex(1.0f, 1.0f, 0.0f)});

    Entity playerEntity("player", {Vertex(-0.25f, -0.25f, 0.0f),
            Vertex(-0.25f, 0.25f, 0.0f),
            Vertex(0.25f, -0.25f, 0.0f),
            Vertex(0.25f, 0.25f, 0.0f),
            Vertex(-0.25f, 0.25f, 0.0f),
            Vertex(0.25f, -0.25f, 0.0f)});


    Player p1(&playerEntity);

    //setup Scene to Renderer pipeline


    exampleScene.addEntity(&playerEntity);
    /*exampleScene.addEntity(&backgroundEntity);*/
    while (Engine::getState() == Engine::RUNNING)
    {

        //- Important core engine things
        //- Game Logic
        //- Render
        //- Clean up/Update/Prep for next frame

        Engine::processInput();
        p1.handleInput();
        p1.Update();

        // std::cout << glm::to_string(p1.model) << std::endl;
        // Renderer::ClearBuffer(glm::vec3(0.0, 0.0, 0.0));

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Renderer::Render(shader, SceneManager::getCurrentScene());
        Engine::Update();
        
    }

    Engine::Quit();
    return EXIT_SUCCESS;
}


// std::vector<float> vertices{-0.5f, -0.5f, 0.0f,
//                             -0.5f, 0.5f, 0.0f,
//                             0.5f, -0.5f, 0.0f,
//                             0.5f, 0.5f, 0.0f,
//                             -0.5f, 0.5f, 0.0f,
//                             0.5f, -0.5f, 0.0f};

// std::vector<float> cube{-0.5f, -0.5f, -0.5,
//                         0.5f, -0.5f, -0.5f,
//                         0.5f, 0.5f, -0.5f,
//                         0.5f, 0.5f, -0.5f,
//                         -0.5f, 0.5f, -0.5f,
//                         -0.5f, -0.5f, -0.5f,

//                         -0.5f, -0.5f, 0.5f,
//                         0.5f, -0.5f, 0.5f,
//                         0.5f, 0.5f, 0.5f,
//                         0.5f, 0.5f, 0.5f,
//                         -0.5f, 0.5f, 0.5f,
//                         -0.5f, -0.5f, 0.5f,

//                         -0.5f, 0.5f, 0.5f,
//                         -0.5f, 0.5f, -0.5f,
//                         -0.5f, -0.5f, -0.5,
//                         -0.5f, -0.5f, -0.5,
//                         -0.5f, -0.5f, 0.5f,
//                         -0.5f, 0.5f, 0.5f,

//                         0.5f, 0.5f, 0.5f,
//                         0.5f, 0.5f, -0.5f,
//                         0.5f, -0.5f, -0.5f,
//                         0.5f, -0.5f, -0.5f,
//                         0.5f, -0.5f, 0.5f,
//                         0.5f, 0.5f, 0.5f,

//                         -0.5f, -0.5f, -0.5,
//                         0.5f, -0.5f, -0.5f,
//                         0.5f, -0.5f, 0.5f,
//                         0.5f, -0.5f, 0.5f,
//                         -0.5f, -0.5f, 0.5f,
//                         -0.5f, -0.5f, -0.5,

//                         -0.5f, 0.5f, -0.5f,
//                         0.5f, 0.5f, -0.5f,
//                         0.5f, 0.5f, 0.5f,
//                         0.5f, 0.5f, 0.5f,
//                         -0.5f, 0.5f, 0.5f,
//                         -0.5f, 0.5f, -0.5f};

// std::vector<float> vertices2{-0.5f, -0.5f,
//                              -0.5f, 0.5f,
//                              0.5f, -0.5f};

// std::vector<Vertex> verts{Vertex(-0.5f, -0.5f, 0.0f), Vertex(-0.5f, 0.5f, 0.0f), Vertex(0.5f, -0.5f, 0.0f)};
// shader.Use();
//  bind vao
//  glBindVertexArray(vao);
//  glDrawArrays(GL_TRIANGLES, 0, 6);
//  Renderer::CheckError();

// glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
// // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// glActiveTexture(GL_TEXTURE0);
// glBindTexture(GL_TEXTURE_2D, texture[0]);
// glActiveTexture(GL_TEXTURE1);
// glBindTexture(GL_TEXTURE_2D, texture[1]);

// myShader.Use();
// // glm::mat4 model = glm::mat4(1.0f);
// // model = glm::rotate(model, ((float)SDL_GetTicks()/1000.0f) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

// glm::mat4 view = glm::mat4(1.0f);
// const float radius = 10.0f;
// float camX = sin((SDL_GetTicks64() / 1000.0f) * radius);
// float camZ = cos((SDL_GetTicks64() / 1000.0f) * radius);
// // std::cout << camZ << std::endl;

// view = glm::lookAt(glm::vec3(camX, 0.0f, 10.0),
//                    glm::vec3(0.0f, 0.0f, 0.0f),
//                    glm::vec3(0.0f, 1.0f, 0.0f));
// // j += sin(1.0f);
// // std::cout << j << std::endl;
// // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
// myShader.setMat4("view", view);

// glBindVertexArray(VAO);
// for (unsigned int i = 0; i < 10; i++)
// {
//     glm::mat4 model = glm::mat4(1.0f);
//     model = glm::translate(model, cubePositions[i]);
//     float angle = 20.0f * i;
//     model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//     myShader.setMat4("model", model);
//     glDrawArrays(GL_TRIANGLES, 0, 36);
// }
// float vertices[] = {
//     // positions     // texture coords
//     0.5f, 0.5f, 0.0f, 1.0f, 1.0f,   // top right
//     0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
//     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
//     -0.5f, 0.5f, 0.0f, 0.0f, 1.0f   // top left
// };

// float vertices[] = {
//     0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
//     -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f};

// float vertices[] =
//     {
//         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//         0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
//         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

//         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//         0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//         -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
//         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

//         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//         -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//         -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

//         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//         0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

//         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
//         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//         0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//         -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

//         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//         0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//         0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//         -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
//         -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

// unsigned int indices[] =
//     {0, 1, 3,
//      1, 2, 3};

// unsigned int VBO, VAO, EBO;
// glGenVertexArrays(1, &VAO);
// std::cout << "Gen Vertex Arrays: " << glGetError() << std::endl;

// glGenBuffers(1, &VBO);
// std::cout << "Gen VBO Buffers: " << glGetError() << std::endl;

// glGenBuffers(1, &EBO);
// std::cout << "Gen EBO Buffers " << glGetError() << std::endl;

// glBindVertexArray(VAO);
// std::cout << "Bind VAO " << glGetError() << std::endl;

// glBindBuffer(GL_ARRAY_BUFFER, VBO);
// std::cout << "Bind VBO " << glGetError() << std::endl;

// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
// std::cout << "vertex buffer data " << glGetError() << std::endl;

// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
// std::cout << "Bind EBO " << glGetError() << std::endl;

// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
// std::cout << "index buffer data " << glGetError() << std::endl;

// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
// std::cout << "Init VAO[0] " << glGetError() << std::endl;

// glEnableVertexAttribArray(0);
// std::cout << "Enable VAO[0] " << glGetError() << std::endl;

// glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
// std::cout << "Init VAO[1] " << glGetError() << std::endl;

// glEnableVertexAttribArray(1);
// std::cout << "Enable VAO[1] " << glGetError() << std::endl;

// glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
// std::cout << "Init VAO[2] " << glGetError() << std::endl;
// glEnableVertexAttribArray(2);
// std::cout << "Enable VAO[2] " << glGetError() << std::endl;

// unsigned int texture[2];
// glGenTextures(2, texture);
// // glActiveTexture(GL_TEXTURE0);
// glBindTexture(GL_TEXTURE_2D, texture[0]);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// // set texture filtering parameters
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// int width, height, nrChannels;
// unsigned char *texData = stbi_load("./res/container.jpg", &width, &height, &nrChannels, 0);
// if (texData)
// {
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
//     glGenerateMipmap(GL_TEXTURE_2D);
// }
// else
// {
//     std::cout << "Unable to load texture..." << std::endl;
// }

// stbi_image_free(texData);

// glBindTexture(GL_TEXTURE_2D, texture[1]);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // set texture wrapping to GL_REPEAT (default wrapping method)
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
// // set texture filtering parameters
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// width = height = nrChannels = 0;
// stbi_set_flip_vertically_on_load(true);
// texData = stbi_load("./res/awesomeface.png", &width, &height, &nrChannels, 0);

// if (texData)
// {
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
//     glGenerateMipmap(GL_TEXTURE_2D);
// }
// else
// {
//     std::cout << "Unable to load texture..." << std::endl;
// }

// stbi_image_free(texData);

// myShader.Use();
// myShader.setInt("texture1", 0);
// myShader.setInt("texture2", 1);

// glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)Engine::getScreenWidth() / (float)Engine::getScreenHeight(), 0.1f, 100.0f);
// myShader.setMat4("projection", projection);

// glBindVertexArray(0);
// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// glBindBuffer(GL_ARRAY_BUFFER, 0);

// glm::vec3 cubePositions[] =
//     {
//         glm::vec3(0.0f, 0.0f, 0.0f),
//         glm::vec3(2.0f, 5.0f, -15.0f),
//         glm::vec3(-1.5f, -2.2f, -2.5f),
//         glm::vec3(-3.8f, -2.0f, -12.3f),
//         glm::vec3(2.4f, -0.4f, -3.5f),
//         glm::vec3(-1.7f, 3.0f, -7.5f),
//         glm::vec3(1.3f, -2.0f, -2.5f),
//         glm::vec3(1.5f, 2.0f, -2.5f),
//         glm::vec3(1.5f, 0.2f, -1.5f),
//         glm::vec3(-1.3f, 1.0f, -1.5f)
//     };

// -0.5f, -0.5f, 0.0f,
//  0.5f, -0.5f, 0.0f,
//  0.0f,  0.5f, 0.0f

// uint32_t vao, vbo;
// glGenVertexArrays(1, &vao);
// glGenBuffers(1, &vbo);
// glBindVertexArray(vao);
// glBindBuffer(GL_ARRAY_BUFFER, vbo);
// glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
// glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void *)0);
// glEnableVertexAttribArray(0);
// glBindBuffer(GL_ARRAY_BUFFER, 0);
// glBindVertexArray(0);

// Shader shader("shaders/BasicVertexShader.glsl", "shaders/BasicFragmentShader.glsl");

// glDeleteVertexArrays(1, &VAO);
// glDeleteBuffers(1, &VBO);
// glDeleteBuffers(1, &EBO);
