#ifndef SCENE_HPP
#define SCENE_HPP

#include "../Renderer/Types/RenderTypes.hpp"
#include "../Camera.hpp"
#include "./Entity.hpp"

//first handle adding items to scene
//next scene layers

class Scene
{
    public:
        Scene(uint32_t width, uint32_t height);
	void addItem(Entity *item);
	void removeItem(Entity *item);
	void setCamera(glm::mat4 view, glm::vec3 pos);
    private:
        uint32_t m_sceneWidth, m_sceneHeight; //viewport
	std::unordered_map<std::string, Entity*> m_sceneItems;
        Camera *m_sceneCamera;
};

#endif
