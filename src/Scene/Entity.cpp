#include "Entity.hpp"

Entity::Entity(std::string name)
{
    m_entityName = name;
    m_model = glm::mat4(1.0f);
    std::cout << "Entity: " << m_entityName << "Has Been Created" << std::endl;
}

const std::string &Entity::getName() const
{
    return m_entityName;
}

const glm::mat4 &Entity::getModel() const
{
	return m_model;
}
