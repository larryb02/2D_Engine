#include "Entity.hpp"

Entity::Entity(std::string name)
{
    m_entityName = name;
    std::cout << "Entity: " << m_entityName << "Has Been Created" << std::endl;
}

const std::string &Entity::getName() const
{
    return m_entityName;
}