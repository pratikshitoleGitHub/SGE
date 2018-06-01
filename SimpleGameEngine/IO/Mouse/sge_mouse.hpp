//
//  sge_mouse.hpp
//  SimpleGameEngine
//
//  Created by Janusz Majchrzak on 20/07/16.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#ifndef sge_mouse_h
#define sge_mouse_h

#include <glm/glm.hpp> 

namespace SGE
{
    class MouseObject
	{
         glm::vec2 mouseCoords;
        
    public:
	    MouseObject() noexcept;

	    void setMouseCoords(glm::vec2 coords) noexcept;

	    glm::vec2 getMouseCoords() const noexcept;
    };
    
}

#endif /* sge_mouse_h */
