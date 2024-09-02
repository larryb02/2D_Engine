#ifndef SANDBOX_TYPES_HPP
#define SANDBOX_TYPES_HPP

#include "../src/Scene/Entity.hpp"
#include "../src/Input/Input.hpp"

typedef struct Player
{
    Player(Entity entity)
    : m_playerEntity(entity)

    {
           //make smart_ptr
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
        m_playerEntity.updatePosition(velX, velY);
        /*std::cout << glm::to_string(m_playerEntity.getModelMatrix()) << std::endl;*/
        velX = velY = 0.0f;
        /*std::cout << "x: " << pos.x << " | " << "y: " << pos.y << std::endl;*/
    };
    /*std::vector<Vertex> m_vertexData;*/
    glm::vec3 pos;
    glm::mat4 model;
    float velX;
    float velY;
    Entity m_playerEntity;
} Player;

#endif
