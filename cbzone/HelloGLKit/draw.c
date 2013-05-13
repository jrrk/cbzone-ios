//
//  draw.c
//  HelloGLKit
//
//  Created by Jonathan Kimmitt on 23/04/2013.
//
//

#include <setjmp.h>
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

int exited = 0;
static int cntDraw = 0;
static jmp_buf unwind;

void resetdraw(void)
{
    cntDraw = 0;
}

up_gl_t updateGL(CGRect bounds, CGPoint center)
{
    up_gl_t ret;
    float aspect = fabsf(bounds.size.width / bounds.size.height);
    GLKMatrix4 projectionMatrix = GLKMatrix4MakePerspective(1.0f, aspect, 1.0f, 0.0f);
    GLKMatrix4 modelViewMatrix = GLKMatrix4MakeTranslation(-0.5f, 0.5f, -1.0f);
    
    ret.projectionMatrix = projectionMatrix;
    ret.modelviewMatrix = modelViewMatrix;

    if (!exited)
    {
        if (!setjmp(unwind))
        {
            cntDraw = 0;
            staticscreen();
            cbzone_while();
            msgrefresh();
        }
    }
    return ret;
}

void drawBg(CGRect bounds)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void drawFg(CGRect bounds, CGPoint center)
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
    assert(cntDraw < maxDraw);
    TexturedQuad newQuad;

    newQuad.bl.geometryVertex = CGPointMake(x1/**magx+offx*/, /*offy*/-y1/**magy*/);
    newQuad.tr.geometryVertex = CGPointMake(x2/**magx+offx*/, /*offy*/-y2/**magy*/);

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
//    bsize = bounds.size;
    init_event();
    
    cbzone_main(0, NULL);
}

void myexit(int status)
{
    exited = true;
    longjmp(unwind, 1);
}
