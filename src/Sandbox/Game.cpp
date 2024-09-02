#include "Game.hpp"
#include "Types.hpp"
#include "../Scene/Scene.hpp"

namespace Game
{
    //will changfe this later just testing
    Player *p_Player = nullptr;
    Scene *p_Scene = nullptr;
    void init()
    {
        Scene exampleScene("Sandbox", -2.0f, +2.0f, -1.5f, +1.5f); 
        Player p1({"player", {Vertex(-0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 1.0f),
             Vertex(-0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 1.0f),
             Vertex(0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 1.0f),
             Vertex(0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 1.0f),
             Vertex(-0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 1.0f),
             Vertex(0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 1.0f)}});

        p_Player = &p1;
        p_Scene = &exampleScene;
        exampleScene.addEntity(&p_Player->m_playerEntity);
    }

    void gameLoop()
    {
        //handleInput
        p_Player->handleInput();
        //process Game Events
        //Update
        p_Player->Update();
    }
}
