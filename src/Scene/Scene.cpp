#include "Scene.hpp"

Scene::Scene(uint32_t width, uint32_t height)
{
	m_sceneWidth = width;
	m_sceneHeight = height;
	m_sceneItems = {};
	m_sceneCamera = nullptr;
}

void Scene::addItem(Entity *item)
{
	m_sceneItems.insert({item->getName(), item});
}

void Scene::removeItem(Entity *item)
{
	//need the index of entity...
	m_sceneItems.erase(item->getName());
	
}
