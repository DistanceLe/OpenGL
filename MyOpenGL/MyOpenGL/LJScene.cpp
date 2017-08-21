//
//  LJScene.cpp
//  MyOpenGL
//
//  Created by LiJie on 2017/8/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "LJScene.h"

void Init(){
    
    //设置矩阵 模式 投射模式
    glMatrixMode(GL_PROJECTION);
    
    //设置 透视参数
    //垂直方向上的视角， 画布宽与高的比， 最近可以看到的距离， 最远可以看到的距离
    gluPerspective(50.f, 800.0f/600.0f, 0.1f, 1000.0f);
    
    //模型视图
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Draw(){
    //清除背景
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //开始 绘制三角形
    glBegin(GL_TRIANGLES);//三角形
    
    //一个颜色 一个点
    glColor4ub(255, 255, 255, 255);
    glVertex3f(-0.2f, -0.2f, -1.5f);

    glColor4ub(255, 0, 0, 255);
    glVertex3f(0.2f, -0.2f, -1.5f);
    
    glColor4ub(0, 255, 0, 255);
    glVertex3f(0.0f, 0.2f, -1.5f);
    
    //结束绘制
    glEnd();
    
}
