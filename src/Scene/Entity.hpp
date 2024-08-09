#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Renderer/Types/RenderTypes.hpp"

class Entity
{
    public:
        Entity(std::string name);
        const std::string &getName() const;
	const glm::mat4 &getModel() const;
	void setPosition();
	const glm::mat4 &getModel() const;
    private:
        void constructRenderData(); //hmm...
        std::string m_entityName; 
	//m_vertices, and m_indices are not needed if i pass this information at object construction
        std::vector<Vertex> m_vertices;
        std::vector<int> m_indices;
        RenderData *m_renderData; //will contain tex info, vertex data, etc...
	glm::mat4 m_model;
};

#endif
