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

/**  绘制 线条 */
void DrawLine(){
    glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    
    //GL_LINE_LOOP
    /**  表示封闭的线条，每个点依次连线，最后封闭 */
    
    //GL_LINE_STRIP
    /**  和Loop相比，最后不会封闭 */
    
    //GL_QUADS
    /**  每四个点 绘制一共四边形，不足四个点什么也不画 */
    
    //GL_QUAD_STRIP
    /**  第一个四边形需要四个点，之后只需两个点 */
    
    //GL_POLYGON
    /**  绘制多边形，且只有凸多边形，至少三个点 */
    
    //两个点为一条线段， 一个点不会显示
    glColor4ub(255, 0, 0, 255);glVertex3f(-0.5, -0.25, -2.5);
    glColor4ub(0, 0, 255, 255);glVertex3f(0.5, -0.25, -2.5);
    
    glColor4ub(0, 0, 255, 255);glVertex3f(0.5, -0.25, -2.5);
    glColor4ub(0, 255, 0, 255);glVertex3f(1.0f, 0.5, -2.5);
    
    glEnd();
}

/**  绘制点 */
void DrawPoint(){
    glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    
    //绘制 正方形的点， 一共有三个点
    glColor4ub(255, 0, 0, 255);glVertex3f(-0.5, -0.25, -2.5);
    glColor4ub(0, 0, 255, 255);glVertex3f(0.5f, -0.25f, -2.5f);
    glColor4ub(0, 255, 0, 255);glVertex3f(0.0, 0.5, -2.5);
    
    glEnd();
}


/**  绘制三角形扇 */
void DrawFna(){
    glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    /**  移动位置， */
//    glLoadIdentity();
//    glTranslatef(0, 0, 1.5);
    
    /**  旋转， 角度，X，Y，Z轴方向 */
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    
    
    /**  缩放 XYZ轴方向，同时位置也拉近了，所以看起来还是没有变化 */
    glScalef(0.2f, 0.2f, 0.2f);
    
    //三角形 扇子
    glBegin(GL_TRIANGLE_FAN);
    
    glColor4ub(255, 0, 0, 255);
    glVertex3f(0, -0.25f, -2.5f);
    
    glColor4ub(0, 0, 255, 255);
    glVertex3f(0.5f, -0.25f, -2.5f);
    
    glColor4ub(0, 255, 0, 255);
    glVertex3f(0.4f, 0.0f, -2.5f);
    
    glColor4ub(0, 255, 0, 255);
    glVertex3f(0.2f, 0.15f, -2.5f);
    
    glColor4ub(0, 0, 255, 255);
    glVertex3f(0.0f, 0.2f, -2.5f);
    
    glEnd();
    
}

/**  绘制三角形带 */
void DrawStrip(){
    glClearColor(0.1f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_STRIP);
    
    
    /**  一种Z字型向上的，三个顶点组成一个三角形 */
    glColor4ub(255, 0, 0, 255);
    glVertex3f(-0.5f, -0.25f, -2.5f);
    
    glColor4ub(0, 0, 255, 255);
    glVertex3f(0.5f, -0.25f, -2.5f);
    
    glColor4ub(0, 255, 0, 255);
    glVertex3f(-0.5f, 0.25f, -2.5f);
    
    glColor4ub(0, 255, 0, 255);
    glVertex3f(0.5f, 0.25f, -2.5f);
    
    glColor4ub(255, 0, 0, 255);
    glVertex3f(-0.5f, 0.75f, -2.5f);
    
    glColor4ub(0, 0, 255, 255);
    glVertex3f(0.5f, 0.75f, -2.5f);
    glEnd();
}


/**  绘制三角形 */
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

/**  矩阵的 入栈和出栈 */
void PushAndPop(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    
    //一般都是先摆放摄像机，再设置图形
    /**  摆放摄像机的位置( 世界坐标系的XYZ位置，
                        眼睛看的center视点的位置XYZ，
                        从头顶发up出去的方向向量XYZ) */
    gluLookAt(0, 0, 0,
              0, 0, -1,
              0, 1, 0);
    
    glPushMatrix();//吧单位矩阵 压入栈
    
        glTranslatef(-0.3f, 0, 0);
        glBegin(GL_TRIANGLES);//三角形
        
        glColor4ub(255, 255, 255, 255);
        glVertex3f(-0.2f, -0.2f, -1.5f);
        
        glColor4ub(255, 0, 0, 255);
        glVertex3f(0.2f, -0.2f, -1.5f);
        
        glColor4ub(0, 255, 0, 255);
        glVertex3f(0.0f, 0.2f, -1.5f);
        
        glEnd();
    glPopMatrix();//吧单位矩阵 出栈
    
    
    glPushMatrix();
        glTranslatef(0.3, 0, 0);
        glBegin(GL_TRIANGLES);//三角形
        
        glColor4ub(255, 255, 255, 255);
        glVertex3f(-0.2f, -0.2f, -1.5f);
        
        glColor4ub(255, 0, 0, 255);
        glVertex3f(0.2f, -0.2f, -1.5f);
        
        glColor4ub(0, 255, 0, 255);
        glVertex3f(0.0f, 0.2f, -1.5f);
        
        glEnd();
    glPopMatrix();

}

void DrawModel(){
    glBegin(GL_QUADS);
    glColor4ub(255, 255, 255, 255);
    glVertex3f(-0.5, -0.2, -0.5);
    glVertex3f(0.5, -0.2, -0.5);
    glVertex3f(0.5, -0.2, -1);
    glVertex3f(-0.5, -0.2, -1);
    glEnd();
}

/**  开始光源 */
void EnableLighting(){
    
    glClearColor(255, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //开启
    glEnable(GL_LIGHTING);
    
    //启用一盏灯， 0~7
    glEnable(GL_LIGHT0);
    //齐次坐标，(x, y, z, w)  -> (x/w, y/w, z/w)  0表示无穷远
    float lightPos[]={0.0, 0.0, 1.0, 0.0};
    //表示方向光源，平行光，无穷远
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    
    
    float whiteColor[] = {1.0, 1.0, 1.0, 1.0};
    float ambientMat[] = {0.07, 0.07, 0.07, 1.0};
    //设置光的颜色
    glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
    //设置物体的放射系数
    glMaterialfv(GL_LIGHT0, GL_AMBIENT, ambientMat);
    
    
    
    
    
    DrawModel();
    
    
}



