//
//  utils.hpp
//  MyOpenGL
//
//  Created by LiJie on 2017/8/24.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>

#endif /* utils_hpp */

#pragma once
#include "LJGL.h"

/**  加载图片文件 */
unsigned char* LoadFileContent(const char* path, int& filesize);

/**  转码位图文件 */
unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height);


/**  创建位图纹理 */
GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type);


/**  根据位图创建纹理对象 */
GLuint CreateTexture2DFromBMP(const char* bmpPath);
