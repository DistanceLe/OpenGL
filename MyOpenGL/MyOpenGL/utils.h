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

unsigned char* LoadFileContent(const char* path, int& filesize);

unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int& height);
