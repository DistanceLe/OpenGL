//
//  skybox.cpp
//  MyOpenGL
//
//  Created by LiJie on 2017/9/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "skybox.hpp"
#include "utils.h"

void Skybox::Init(const char *imageDir){
    
    char temp[256];
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "front.bmp");
    mTextures[0] = CreateTexture2DFromBMP(temp);
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "front.bmp");//back
    mTextures[1] = CreateTexture2DFromBMP(temp);
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "left.bmp");
    mTextures[2] = CreateTexture2DFromBMP(temp);
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "left.bmp");//right
    mTextures[3] = CreateTexture2DFromBMP(temp);
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "top.bmp");
    mTextures[4] = CreateTexture2DFromBMP(temp);
    
    memset(temp, 0, 256);
    strcpy(temp, imageDir);
    strcat(temp, "top.bmp");//bottom
    mTextures[5] = CreateTexture2DFromBMP(temp);
    
    mFastDrawCall = CreateDisplayList([this]()->void {DrawCommand(); });
    
}

void Skybox::DrawCommand(){
    this->Draw();
}

void Skybox::NewDraw(){
    glCallList(mFastDrawCall);
}

void Skybox::Draw(){
    
    glDisable(GL_DEPTH_TEST);//关闭深度缓冲区，这样深度就不会被修改。
    glEnable(GL_TEXTURE_2D);
    
    //front
    glBindTexture(GL_TEXTURE_2D, mTextures[0]);
    glBegin(GL_QUADS);
    glColor4ub(255, 255, 255, 255);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, -0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();
    
    //back
    glBindTexture(GL_TEXTURE_2D, mTextures[1]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    
    //left
    glBindTexture(GL_TEXTURE_2D, mTextures[2]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.5, 0.5, -0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    
    //right
    glBindTexture(GL_TEXTURE_2D, mTextures[3]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.5, -0.5, -0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
    
    
    //top
    glBindTexture(GL_TEXTURE_2D, mTextures[4]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, 0.5, -0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, 0.5, -0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, 0.5, 0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    
    
    //bottom
    glBindTexture(GL_TEXTURE_2D, mTextures[5]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.5);
    
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
}


















