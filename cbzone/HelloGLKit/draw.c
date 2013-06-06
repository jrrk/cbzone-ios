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

typedef struct {
    CGPoint geometryVertex;
//    CGPoint textureVertex;
    struct {float red, green, blue, alpha;} colorVertex;
} TexturedVertex;

typedef struct {
    TexturedVertex bl;
    TexturedVertex tr;
} TexturedQuad;

static struct {
    int cntDraw;
    TexturedQuad vectors[maxDraw];
} rounds[maxRound];

int exited = 0;
static int myround = 0;
static jmp_buf unwind;

void resetdraw(void)
{
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
struct timeval tval;
static struct timeval oldtval;
gettimeofday(&tval, 0);
//if (tval.tv_usec < oldtval.tv_usec || 1)
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//        glEnable(GL_BLEND);
    }
    oldtval = tval;
}

void drawFg(CGRect bounds, CGPoint center)
{
    TexturedQuad newQuad;
    for (int rnd = opt->trails ? 0 : maxRound-1; rnd < maxRound; rnd++)
    {
        int myrnd = (rnd+myround+1)%maxRound;
        int mycnt = rounds[myrnd].cntDraw;
        TexturedQuad *vectors = rounds[myrnd].vectors;
        for (int i = 0; i < mycnt; i++)
        {
            newQuad = vectors[i];
            long offset = (long)&newQuad;
        
            glLineWidth(opt->linewidth);
            glEnableVertexAttribArray(GLKVertexAttribPosition);
            glEnableVertexAttribArray(GLKVertexAttribColor);
        
            glVertexAttribPointer(GLKVertexAttribPosition, 2, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), (void *) (offset + offsetof(TexturedVertex, geometryVertex)));
            glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, sizeof(TexturedVertex), (void *) (offset + offsetof(TexturedVertex, colorVertex)));
        
            glDrawArrays(GL_LINES, 0, 2);
        }
    }
}

void drawLineRel(float x1, float y1, float x2, float y2, unsigned long drawforeground)
{
    float red = (drawforeground >> 16)/255.0;
    float green = ((drawforeground >> 8) & 255)/255.0;
    float blue = (drawforeground & 255)/255.0;
    float alpha = 1.0;
    assert(rounds[myround].cntDraw < maxDraw);
    TexturedQuad newQuad;

    newQuad.bl.geometryVertex = CGPointMake(x1, -y1);
    newQuad.tr.geometryVertex = CGPointMake(x2, -y2);

    newQuad.bl.colorVertex.red = red;
    newQuad.bl.colorVertex.green = green;
    newQuad.bl.colorVertex.blue = blue;
    newQuad.bl.colorVertex.alpha = alpha;
    newQuad.tr.colorVertex.red = red;
    newQuad.tr.colorVertex.green = green;
    newQuad.tr.colorVertex.blue = blue;
    newQuad.tr.colorVertex.alpha = alpha;
    
    rounds[myround].vectors[rounds[myround].cntDraw] = newQuad;
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
