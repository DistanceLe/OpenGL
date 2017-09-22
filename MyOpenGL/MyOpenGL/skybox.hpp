//
//  skybox.hpp
//  MyOpenGL
//
//  Created by LiJie on 2017/9/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#ifndef skybox_hpp
#define skybox_hpp

#include <stdio.h>

#endif /* skybox_hpp */


#pragma once
#include "LJGL.h"


class Skybox{
    GLuint mTextures[6]; //存储6个纹理对象 前后左右上下
    GLuint mFastDrawCall;
public:
    void Init(const char* imageDir);//图片的目录
    void Draw();
    
    void NewDraw();
    void DrawCommand();
};
