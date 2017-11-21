//
//  ground.cpp
//  MyOpenGL
//
//  Created by LiJie on 2017/9/28.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "ground.hpp"

void Ground::Draw(){
    
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    for (int z = 0; z < 20; ++z) {
        
        float zStart = 100.0 - z*10.0;
        for (int x = 0; x < 20; ++x) {
            
            float xStart = x*10.0 - 100.0;
            if ((z%2)^(x%2)) {
                glColor4ub(41, 41, 41, 255);
            }else{
                glColor4ub(200, 200, 200, 255);
            }
            glVertex3f(xStart, -1.0, zStart);
            glVertex3f(xStart+10.0, -1.0, zStart);
            glVertex3f(xStart+10.0, -1.0, zStart - 10.0);
            glVertex3f(xStart, -1.0, zStart - 10.0);
        }
    }
    glEnd();
}
