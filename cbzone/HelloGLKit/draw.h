//
//  draw.h
//  HelloGLKit
//
//  Created by Jonathan Kimmitt on 23/04/2013.
//
//

#ifndef HelloGLKit_draw_h
#define HelloGLKit_draw_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include <GLKit/GLKMathUtils.h>
#include <GLKit/GLKMathTypes.h>
#include <GLKit/GLKMatrix4.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreGraphics/CGContext.h>
#include <objc/objc.h>
#include <AudioToolbox/AudioToolbox.h>

#ifdef __OBJC__
#include <UIKit/UIGraphics.h>
#include <GLKit/GLKEffects.h>
#include <Foundation/NSDate.h>
#else

extern CGContextRef UIGraphicsGetCurrentContext(void);

// if not objc, cannot use above because of inadequate guarding in header file so pasted here

typedef double NSTimeInterval;

// Named vertex attributes for mapping GLKEffects logic to client vertex attrib enables

typedef enum {
    GLKVertexAttribPosition,
    GLKVertexAttribNormal,
    GLKVertexAttribColor,
    GLKVertexAttribTexCoord0,
    GLKVertexAttribTexCoord1,
} GLKVertexAttrib;

#endif

typedef struct {
    float Position[3];
    float Color[4];
    float TexCoord[2];
} Vertex;

typedef struct { GLKMatrix4 projectionMatrix, modelviewMatrix; } up_gl_t;

extern GLuint _vertexArray;
extern GLuint _vertexBuffer;
extern GLuint _indexBuffer;

extern float _rotation;
extern int exited, intro;
extern char *TANKDIR;

typedef enum {
    senemy_seen,
    sfire,
    sgame_begin,
    sgame_end,
    skill,
    smove,
    smove_blocked,
    sobject_explodes,
    ssalvo_fired,
    suser_died,
    suser_shoots,
    slast_sound
} sound_t;

SystemSoundID soundFileObject[slast_sound];

void resetdraw(void);
up_gl_t updateGL(CGRect bounds, CGPoint center);
void drawLine(float x1, float y1, float x2, float y2, float red, float green, float blue, float alpha);
void drawLineRel(float x1, float y1, float x2, float y2, unsigned long drawforeground);
void drawBg(CGRect bounds);
void drawFg(CGRect bounds, CGPoint center);
void glSetup(CGRect bounds);
void cbzone_main(int argc, const char* const argv[]);
void cbzone_while(void);
void staticscreen(void);
void introscreen(void);
void dumpGL(void);
void mytouch(void);
void myaccel(float acceleration_x, float acceleration_y);
void init_event(void);
void staticscore();
void msgrefresh(void);
void sound(char *soundName, int soundid);
void playsound(sound_t);
void myexit(int);
void rot(float,float,float,float,float,float);
void char_tab(int);
void fcoord(float x0, float y0, float x1, float y1);
void fline(float x0, float y0, float x1, float y1);
void drawintro(void);
void loadDefaults(void);
#endif
