//
//  draw.c
//  HelloGLKit
//
//  Created by Jonathan Kimmitt on 23/04/2013.
//
//

#include <setjmp.h>
#include <sys/time.h>
#include "c_includes.h"

enum {maxRound=2, maxDraw=10000};

typedef struct {float red, green, blue, alpha, red2, green2, blue2, alpha2;} rgb_t;
typedef struct {CGPoint bl,tr; } bl_tr_t;

static struct {
    int cntDraw;
    bl_tr_t geometryVertex[maxDraw];
    rgb_t colorVertex[maxDraw];
} rounds[maxRound];

int exited = 0;
static int myround = 0;
static jmp_buf unwind;

void resetdraw(void)
{
#if 0
    if (opt->trails)
    {
        int mycnt = rounds[myround].cntDraw;
        TexturedQuad *vectors = rounds[myround].vectors;
        for (int i = 0; i < mycnt; i++)
            {
                float fade = (vectors[i].bl.colorVertex.red+vectors[i].bl.colorVertex.green+vectors[i].bl.colorVertex.blue)/3;
                vectors[i].bl.colorVertex.red = fade;
                vectors[i].bl.colorVertex.green = fade;
                vectors[i].bl.colorVertex.blue = fade;
                vectors[i].tr.colorVertex.red = fade;
                vectors[i].tr.colorVertex.green = fade;
                vectors[i].tr.colorVertex.blue = fade;
            }
    }
#endif
    myround = (myround+1)%maxRound;
    rounds[myround].cntDraw = 0;
}

up_gl_t updateGL(CGRect bounds, CGPoint center)
{
    up_gl_t ret;
    GLKMatrix4 projectionMatrix = GLKMatrix4MakePerspective(1.0f, 1.0f, 1.0f, 0.0f);
    GLKMatrix4 modelViewMatrix = GLKMatrix4MakeTranslation(-0.5f, 0.5f, -1.0f);
    
    ret.projectionMatrix = projectionMatrix;
    ret.modelviewMatrix = modelViewMatrix;

    if (!exited)
    {
        if (!setjmp(unwind))
        {
            resetdraw();
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
}

void drawFg(CGRect bounds, CGPoint center)
{
    for (int rnd = opt->trails ? 0 : maxRound-1; rnd < maxRound; rnd++)
    {
        int myrnd = (rnd+myround+1)%maxRound;
        int mycnt = rounds[myrnd].cntDraw;
        bl_tr_t *geomVertices = rounds[myrnd].geometryVertex;
        rgb_t *colorVertices = rounds[myround].colorVertex;
#if 0
        for (int i = 0; i < mycnt; i++)
        {
            rgb_t colorVertex = colorVertices[i];
            bl_tr_t newQuad = geomVertices[i];
        
            glLineWidth(opt->linewidth);
            glEnableVertexAttribArray(GLKVertexAttribPosition);
            glEnableVertexAttribArray(GLKVertexAttribColor);
        
            glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, 0, (void *) &newQuad);
            glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, 0, (void *) &colorVertex);
        
            glDrawArrays(GL_LINES, 0, 2);
        }
#else
            glLineWidth(opt->linewidth);
            glEnableVertexAttribArray(GLKVertexAttribPosition);
            glEnableVertexAttribArray(GLKVertexAttribColor);
            
            glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, 0, (void *) geomVertices);
            glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, 0, (void *) colorVertices);
            
            glDrawArrays(GL_LINES, 0, 2*mycnt);
#endif
    }
}

void drawLineRel(float x1, float y1, float x2, float y2, unsigned long drawforeground)
{
    float red = (drawforeground >> 16)/255.0;
    float green = ((drawforeground >> 8) & 255)/255.0;
    float blue = (drawforeground & 255)/255.0;
    float alpha = 1.0;
    assert(rounds[myround].cntDraw < maxDraw);

    rounds[myround].geometryVertex[rounds[myround].cntDraw].bl = CGPointMake(x1, -y1);
    rounds[myround].geometryVertex[rounds[myround].cntDraw].tr = CGPointMake(x2, -y2);

    rounds[myround].colorVertex[rounds[myround].cntDraw].red = red;
    rounds[myround].colorVertex[rounds[myround].cntDraw].green = green;
    rounds[myround].colorVertex[rounds[myround].cntDraw].blue = blue;
    rounds[myround].colorVertex[rounds[myround].cntDraw].alpha = alpha;
    rounds[myround].colorVertex[rounds[myround].cntDraw].red2 = red;
    rounds[myround].colorVertex[rounds[myround].cntDraw].green2 = green;
    rounds[myround].colorVertex[rounds[myround].cntDraw].blue2 = blue;
    rounds[myround].colorVertex[rounds[myround].cntDraw].alpha2 = alpha;
    
    if (drawforeground) rounds[myround].cntDraw++;
}

void glSetup(CGRect bounds)
{
//    bsize = bounds.size;
    init_event();
    
    cbzone_main(0, NULL);
    
    playsound(sgame_begin);
}

void myexit(int status)
{
    exited = true;
    playsound(sgame_end);
    longjmp(unwind, 1);
}
