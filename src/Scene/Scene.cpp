#include "Scene.hpp"

Scene::Scene(const char *name, float leftWidth, float rightWidth, float bottomHeight, float topHeight)
	: 	
	m_sceneName(name),
	m_sceneCamera(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -0.3f))
{
	m_sceneWidth = leftWidth;
	m_sceneHeight = topHeight;
	//m_sceneProjection = glm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height), 0.1f, 100.0f);
	m_sceneProjection = glm::ortho(leftWidth, rightWidth, bottomHeight, topHeight, 0.1f, 100.0f);
	m_sceneItems = {};
}

void Scene::addItem(Entity *item)
{
	m_sceneItems.insert({item->getEntityName(), item});
}

void Scene::removeItem(Entity *item)
{
	m_sceneItems.erase(item->getEntityName());	
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

const glm::mat4 &Scene::getProjectionMatrix() const
{
    return m_sceneProjection;
}
