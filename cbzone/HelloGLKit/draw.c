//
//  draw.c
//  HelloGLKit
//
//  Created by Jonathan Kimmitt on 23/04/2013.
//
//

#include "draw.h"

enum {maxDraw=10000};

typedef struct {
    CGPoint geometryVertex;
//    CGPoint textureVertex;
    struct {float red, green, blue, alpha;} colorVertex;
} TexturedVertex;

typedef struct {
    TexturedVertex bl;
    TexturedVertex tr;
} TexturedQuad;

TexturedQuad vectors[maxDraw];

CGSize bsize;
int cntDraw = 0;

up_gl_t updateGL(CGRect bounds, NSTimeInterval timeSinceLastUpdate)
{
    up_gl_t ret;
    float aspect = fabsf(bounds.size.width / bounds.size.height);
    GLKMatrix4 projectionMatrix = GLKMatrix4MakePerspective(GLKMathDegreesToRadians(65.0f), aspect, 4.0f, 10.0f);
    GLKMatrix4 modelViewMatrix = GLKMatrix4MakeTranslation(0.0f, 0.0f, -6.0f);
#if 0
    _rotation += 90 * timeSinceLastUpdate;
    modelViewMatrix = GLKMatrix4Rotate(modelViewMatrix, GLKMathDegreesToRadians(_rotation), 1, 0, 0);
    modelViewMatrix = GLKMatrix4Rotate(modelViewMatrix, GLKMathDegreesToRadians(40), 0, 1, 0);
    modelViewMatrix = GLKMatrix4Rotate(modelViewMatrix, GLKMathDegreesToRadians(60), 0, 0, 1);
#endif
    
    ret.projectionMatrix = projectionMatrix;
    ret.modelviewMatrix = modelViewMatrix;

    cntDraw = 0;
    bsize = bounds.size;
    staticscreen();
    cbzone_while();
    msgrefresh();
    return ret;
}

void drawBg(CGRect bounds)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void drawFg(CGRect bounds)
{
    TexturedQuad newQuad;
    for (int i = 0; i < cntDraw; i++)
    {
        newQuad = vectors[i];
        long offset = (long)&newQuad;
        
        glLineWidth(2.0);
        glEnableVertexAttribArray(GLKVertexAttribPosition);
        glEnableVertexAttribArray(GLKVertexAttribColor);
        
        glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), (void *) (offset + offsetof(TexturedVertex, geometryVertex)));
        glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), (void *) (offset + offsetof(TexturedVertex, colorVertex)));
        
        glDrawArrays(GL_LINES, 0, 2);
    }
}

void drawLineRel(float x1, float y1, float x2, float y2, unsigned long drawforeground)
{
    float red = (drawforeground >> 16)/255.0;
    float green = ((drawforeground >> 8) & 255)/255.0;
    float blue = (drawforeground & 255)/255.0;
    float alpha = 1.0;
    float offx, offy, magx, magy;
    int sz = (int)bsize.width;
    switch(sz)
    {
        case 0:
            assert(0);
            break;
        case 768:
            offx = 0;
            offy = 0;
            magx = 8.0;
            magy = 8.0;
            break;
        case 1024:
            offx = -5;
            offy = +3;
            magx = 8.0;
            magy = 8.0;
            break;
        case 300:
        case 480:
            offx = -6.75;
            offy = +3.5;
            magx = 4.0;
            magy = 4.0;
            break;
        default:
            offx = -6.5;
            offy = +3.5;
            magx = 4.25;
            magy = 4.25;
            break;
    }
    assert(cntDraw < maxDraw);
    TexturedQuad newQuad;

    newQuad.bl.geometryVertex = CGPointMake(x1*magx+offx, offy-y1*magy);
    newQuad.tr.geometryVertex = CGPointMake(x2*magx+offx, offy-y2*magy);

    newQuad.bl.colorVertex.red = red;
    newQuad.bl.colorVertex.green = green;
    newQuad.bl.colorVertex.blue = blue;
    newQuad.bl.colorVertex.alpha = alpha;
    newQuad.tr.colorVertex.red = red;
    newQuad.tr.colorVertex.green = green;
    newQuad.tr.colorVertex.blue = blue;
    newQuad.tr.colorVertex.alpha = alpha;
    
    vectors[cntDraw++] = newQuad;
}

void glSetup(CGRect bounds)
{
    bsize = bounds.size;
    init_event();
    cbzone_main(0, NULL);
}
