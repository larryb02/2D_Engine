#include "Entity.hpp"

Entity::Entity(std::string name)
{
    m_entityName = name;
    m_model = glm::mat4(1.0f);
    std::cout << "Entity: " << m_entityName << "Has Been Created" << std::endl;
}

const std::string &Entity::getEntityName() const
{
    return m_entityName;
}

const glm::mat4 &Entity::getModelMatrix() const
{
	return m_model;
}
