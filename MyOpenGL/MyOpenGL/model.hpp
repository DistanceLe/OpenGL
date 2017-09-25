//
//  model.hpp
//  MyOpenGL
//
//  Created by LiJie on 2017/9/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <stdio.h>

#endif /* model_hpp */
#pragma once
#include "LJGL.h"


struct VertexData{
    float position[3];
    float normal[3];
    float texcoord[2];
};

class Model{
    
    VertexData* mVertexes;
    unsigned short* mIndexes;//索引指针
    int mIndexCount;//多少个索引
public:
    Model();
    void Init(const char* modelPath);
    void Draw();
};
