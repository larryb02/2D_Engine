#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Renderer/Types/RenderTypes.hpp"

class Entity
{
    public:
        Entity(std::string name);
        const std::string &getName() const;
    private:
        void constructRenderData(); //hmm...
        std::string m_entityName; 
        std::vector<Vertex> m_vertices;
        std::vector<int> m_indices;
        RenderData *m_renderData; //will contain tex info, vertex data, etc...
};

#endif