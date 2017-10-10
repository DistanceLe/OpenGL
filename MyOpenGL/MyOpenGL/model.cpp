//
//  model.cpp
//  MyOpenGL
//
//  Created by LiJie on 2017/9/21.
//  Copyright © 2017年 LiJie. All rights reserved.
//

#include "model.hpp"
#include "utils.h"

Model::Model(){
    
}

void Model::Init(const char *modelPath){
    
    struct FloatData{
        float v[3];
    };
    struct VertexDefine{
        int posIndex;
        int texcoordIndex;
        int normalIndex;
    };
    
    std::vector<FloatData> positions, texcoords, normals;
    std::vector<VertexDefine> vertexes;
    std::vector<int> indexes;
    
    
    /**
     OBJ文件的基本结构
     OBJ文件由一行行文本组成，可以用记事本打开。
     注释行以符号“#”为开头，空格和空行可以随意加到文件中以增加文件的可读性。
     有字的行都由一两个标记字母也就是关键字(Keyword)开头，关键字可以说明这一行是什么样的数据。
     多行可以逻辑地连接在一起表示一行，方法是在每一行最后添加一个连接符(\)。 注意连接符(\)后面不能出现空格或Tab格，否则将导致文件出错。
     
     下列常用的关键字可以在OBJ文件使用。
     顶点数据(Vertex data)：
     v 几何体顶点(Geometric vertices)
     vt 贴图坐标点(Texture vertices)
     vn 顶点法线(Vertex normals)
     vp 参数空格顶点 (Parameter space vertices)
     
     元素(Elements):
     p  点(Point)
     l  线(Line)
     f  面(Face)
     
     成组(Grouping):
     g  组名称(Group name)
     o 对象名称(Object name)
     
     显示(Display)/渲染属性(render attributes):
     usemtl 材质名称(Material name)
     mtllib 材质库(Material library) */
    
    int nFileSize = 0;
    unsigned char* fileContent = LoadFileContent(modelPath, nFileSize);
    if (fileContent == nullptr) {
        return;
    }
    std::stringstream ssFileContent((char*)fileContent);
    std::string temp;
    char szOneLine[256];
    while (!ssFileContent.eof()) {
        memset(szOneLine, 0, 256);
        ssFileContent.getline(szOneLine, 256);
        if (strlen(szOneLine) >0) {
            if (szOneLine[0] == 'v') {
                std::stringstream ssOneLine(szOneLine);
                
                if (szOneLine[1] == 't') {
                    printf("texcoord: %s\n", szOneLine);
                    ssOneLine >> temp; //流输出，以空格区分
                    FloatData floatData;
                    ssOneLine >> floatData.v[0];
                    ssOneLine >> floatData.v[1];
                    texcoords.push_back(floatData);
                    printf("texcoord:%.3f, %.3f--\n", floatData.v[0], floatData.v[1]);
                    
                }else if (szOneLine[1] == 'n'){
                    printf("normal: %s\n", szOneLine);
                    ssOneLine >> temp; //流输出，以空格区分
                    FloatData floatData;
                    ssOneLine >> floatData.v[0];
                    ssOneLine >> floatData.v[1];
                    ssOneLine >> floatData.v[2];
                    normals.push_back(floatData);
                    printf("normal:%.3f, %.3f, %.3f--\n", floatData.v[0], floatData.v[1], floatData.v[2]);
                }else{
                    printf("position: %s\n", szOneLine);
                    ssOneLine >> temp; //流输出，以空格区分
                    FloatData floatData;
                    ssOneLine >> floatData.v[0];
                    ssOneLine >> floatData.v[1];
                    ssOneLine >> floatData.v[2];
                    positions.push_back(floatData);
                    printf("texcoord:%.3f, %.3f, %.3f--\n", floatData.v[0], floatData.v[1], floatData.v[2]);
                }
            }else if (szOneLine[0] == 'f'){
                printf("draw command: %s\n", szOneLine);
                
                std::stringstream ssOneLine(szOneLine);
                ssOneLine >> temp;
                std::string vertexStr;
                for (int i = 0; i < 3; i++) {
                    ssOneLine >> vertexStr;
                    size_t pos = vertexStr.find_first_of('/');
                    std::string posIndexStr = vertexStr.substr(0, pos);
                    size_t pos2 = vertexStr.find_first_of('/', pos+1);
                    std::string texcoordIndexStr = vertexStr.substr(pos+1, pos2-1-pos2);
                    std::string normalIndexStr = vertexStr.substr(pos2+1, vertexStr.length()-1-pos2);
                    VertexDefine vd;
                    vd.posIndex = atoi(posIndexStr.c_str());
                    vd.texcoordIndex = atoi(texcoordIndexStr.c_str());
                    vd.normalIndex = atoi(normalIndexStr.c_str());
                    int nCurrentVertexIndex = -1;
                    int nCurrentVertexCount = (int)vertexes.size();
                    for (int i = 0; i < nCurrentVertexCount; i++) {
                        if (vertexes[i].posIndex == vd.posIndex &&
                            vertexes[i].texcoordIndex == vd.posIndex &&
                            vertexes[i].normalIndex == vd.normalIndex) {
                            nCurrentVertexIndex = i;
                            break;
                        }
                    }
                    if (nCurrentVertexIndex == -1) {
                        nCurrentVertexIndex = (int)vertexes.size();
                        vertexes.push_back(vd);
                    }
                    indexes.push_back(nCurrentVertexIndex);
                }
            }
        }
    }
    
    mIndexCount = (int)indexes.size();
    mIndexes = new unsigned short(mIndexCount);
    for (int i = 0; i<mIndexCount; i++) {
        mIndexes[i] = indexes[i];
    }
    
    //唯一的点的个数
    int vertexCount = (int)vertexes.size();
    mVertexes = new VertexData[vertexCount];
    for (int i = 0; i<vertexCount; i++) {
        memcpy(mVertexes[i].position, positions[vertexes[i].posIndex-i].v, sizeof(float)*3);
        memcpy(mVertexes[i].texcoord, texcoords[vertexes[i].texcoordIndex].v, sizeof(float)*2);
        memcpy(mVertexes[i].normal, normals[vertexes[i].normalIndex].v, sizeof(float)*3);
    }
    
    delete fileContent;
    /**  每个keyword的意思：
     "vt 1.000000 0.000000"这句"vt"代表点的纹理贴图坐标。
     "vn 0.000000 0.000000 -1.000000"这句"vn"代表点的法线向量。
     "s off"表示关闭光滑组。
     "usemtl initialShadingGroup"表示使用的材质。
     "f 7/13/21"这时在面的数据中多了顶点点和纹理坐标和法线的索引号。这里f包含三组顶点，意味一个三角面，当然有时候会是n角面。
     格式："f 顶点索引v/纹理uv点索引vt/法线索引vn"。
     "g pCube1"表示组。 */
    
}

/**  绘制模型 */
void Model::Draw(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, mTexture);
    glEnable(GL_DEPTH_TEST);
    
    
    glPushMatrix();
    glTranslated(0, 0, -5.0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i<mIndexCount; i++) {
        glTexCoord2fv(mVertexes[mIndexes[i]].texcoord);
        glNormal3fv(mVertexes[mIndexes[i]].normal);
        glVertex3fv(mVertexes[mIndexes[i]].position);
    }
    glEnd();
    glPopMatrix();
}
























