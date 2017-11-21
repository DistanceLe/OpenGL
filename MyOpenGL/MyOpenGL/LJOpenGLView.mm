//
//  LJOpenGLView.m
//  MyOpenGL
//
//  Created by LiJie on 2017/8/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#import "LJOpenGLView.h"
#include "LJScene.h"
#include "utils.h"

/**  加载图片文件 */
unsigned char* LoadFileContent(const char* path, int& filesize){
    
    unsigned char* fileContent = nullptr;
    filesize = 0;
    NSString* imagePath = [[NSBundle mainBundle]pathForResource:[NSString stringWithUTF8String:path] ofType:nil];
    NSData* data = [NSData dataWithContentsOfFile:imagePath];
    
    if (data.length>0) {//最末尾添加一个 '\0', 代码更健壮
        filesize = (int)data.length;
        fileContent = new unsigned char[filesize+1];
        memcpy(fileContent, [data bytes], filesize);
        fileContent[filesize] = '\0';
    }
    return fileContent;
}

@implementation LJOpenGLView

-(void)prepareOpenGL{
    [super prepareOpenGL];
    
    Init();
    [NSTimer scheduledTimerWithTimeInterval:0.016 target:self selector:@selector(renderOneFrame) userInfo:nil repeats:YES];
}

/**  每帧去 重新绘制 */
-(void)renderOneFrame{
    /**  会调用 drawRect: */
    [self setNeedsDisplay:YES];
}


- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
//    Draw();
//    DrawStrip();
//    DrawFna();
//    DrawPoint();
    
//    DrawLine();
    
//    PushAndPop();
//    EnableLighting();
    
//    DrawTexture();
//    DrawSkybox();
//    DrawGLModel();
//    glFlush();
    DrawGround();
}
















@end
