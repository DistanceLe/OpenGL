//
//  utils.cpp
//  MyOpenGL
//
//  Created by LiJie on 2017/8/24.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "utils.h"

/**  转码 */
unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height){
    
    if (0x4D42 == *((unsigned short*)bmpFileData)) { //是否是一个位图
        int pixelDataOffset = *((int*)(bmpFileData + 10));//位图的像素数据的偏移地址
        width = *((int16_t*)(bmpFileData + 18)); //占了两个字节，用int16_t，视频里面的int会占四个字节
        height = *((int16_t*)(bmpFileData +20)); //这边也是偏移了20(OS版本的bmp)个字节，和视频里面的22(windows版本的bmp)有出入
        unsigned char* pixelData = bmpFileData + pixelDataOffset;
        
        for (int i = 0; i<width*height *3 ; i+=3) {//BGR像素，没有alpha通道， -> (OpenGL的)RGB像素格式
            unsigned char temp = pixelData[i];
            pixelData[i] = pixelData[i+2];
            pixelData[i+2] = temp;
        }
        return pixelData;
    }
    return nullptr;
    
}

/**  创建位图纹理 */
GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type){
    
    GLuint texture;
    glGenTextures(1, &texture);//一个纹理对象， 纹理地址
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//纹理放大的过滤规则，线性
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//纹理缩小的过滤规则，线性
    
    
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//纹理放大的过滤规则，附近的,看起来更顺滑
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//纹理缩小的过滤规则，附近的
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);//纹理位置超过1.0 则取 1.0
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);//如2.0 则纹理缩小一倍。
    
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//纹理位置超过1.0 则取 1.0
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);//如2.0 则纹理缩小一倍。会复制充满。
    
    //绘制到显卡上 2D,        level, 在显卡上的格式，           在内存上的格式，
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixelData);
    glBindTexture(GL_TEXTURE_2D, 0);//设置完了后续不想继续修改(当前的纹理设为0号纹理)
    return texture;
    
}

/**  根据位图创建纹理对象 */
GLuint CreateTexture2DFromBMP(const char* bmpPath){
    
    /**  图片纹理 */
    int nFileSize = 0;
    unsigned char* bmpFileContent = LoadFileContent(bmpPath, nFileSize);
    if (bmpFileContent == nullptr) {
        return 0;
    }
    int bmpWidth = 0, bmpHeight = 0;
    unsigned char* pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
    if (bmpWidth == 0) {
        delete bmpFileContent;
        return 0;
    }
    GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
    delete bmpFileContent;
    return texture;
}







