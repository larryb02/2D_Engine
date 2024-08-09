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
	//const Camera &getCamera() const;
	Camera &getCamera();
	void setCamera(glm::vec3 pos);
	const Entity *getItem(const std::string key) const;
	glm::mat4 setProjection(glm::mat4 proj);
    private:
        uint32_t m_sceneWidth, m_sceneHeight; //projection dimensions
	std::unordered_map<std::string, Entity*> m_sceneItems;
	Camera m_sceneCamera;
	glm::mat4 m_sceneProjection;
	std::vector<RenderData> createRenderData(); 
};

#endif
