#include "Scene.hpp"

Scene::Scene(uint32_t width, uint32_t height)
	: m_sceneCamera(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -0.3f))
{
	m_sceneWidth = width;
	m_sceneHeight = height;
//	m_sceneProjection = glm::ortho();
	m_sceneItems = {};
}

void Scene::addItem(Entity *item)
{
	m_sceneItems.insert({item->getName(), item});
}

void Scene::removeItem(Entity *item)
{
	m_sceneItems.erase(item->getName());	
}

const Entity *Scene::getItem(const std::string key) const
{
	//add logic to check if key exists
	return m_sceneItems.find(key) != m_sceneItems.end() ? m_sceneItems.at(key) : nullptr;
}

//const Camera &Scene::getCamera() const
//{
//	return m_sceneCamera;
//}
//

Camera &Scene::getCamera() 
{
	return m_sceneCamera;
}


void Scene::setCamera(glm::vec3 pos)
{
	m_sceneCamera.UpdatePosition(pos);
}
