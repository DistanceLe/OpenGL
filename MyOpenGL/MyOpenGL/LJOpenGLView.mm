//
//  LJOpenGLView.m
//  MyOpenGL
//
//  Created by LiJie on 2017/8/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#import "LJOpenGLView.h"
#include "LJScene.h"


@implementation LJOpenGLView

-(void)prepareOpenGL{
    [super prepareOpenGL];
    
    Init();
    [NSTimer scheduledTimerWithTimeInterval:0.016 target:self selector:@selector(renderOneFrame) userInfo:nil repeats:YES];
}

-(void)renderOneFrame{
    [self setNeedsDisplay:YES];
}






- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    Draw();
    glFlush();
}
















@end
