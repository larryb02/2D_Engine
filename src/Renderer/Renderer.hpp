
#ifndef RENDERER_HPP
#define RENDERER_HPP

// #include <glm/glm.hpp>
#include <vector>
// #include "Texture.hpp"
#include "./Types/RenderTypes.hpp"
// #include <glad/glad.h>

/* things i want renderer to be able to do
    - store multiple VAOs, VBOs, EBOs, FBs
        - Make objects for each? or one object that has all of this per
            - class or struct?
    - data structures that can contain all these buffers for render passes
        - array seems the most reasonable in this case
    - Render Modes
        - Normal: (don't have to explain...)
        - Debug: Render lines around models
*/


//Render Pipeline:
// list of data to draw per frame gets pushed to a list, (from respected sources)
// every frame a render call is made, 
// renderer creates the RenderData then renders the items
namespace Renderer
{
    enum RenderMode { DEBUG };
    
    void Render(std::vector<RenderData> &rd, Shader &shader);
    void ClearBuffer(glm::vec3 color);
    GLenum CheckError_(const char *file, int line);
    
    #define CheckError() CheckError_(__FILE__, __LINE__)
}


#endif
