//
//  HelloGLKitViewController.m
//  HelloGLKit
//
//  Created by Ray Wenderlich on 9/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "HelloGLKitViewController.h"
#include "draw.h"

@interface HelloGLKitViewController () {
    float _curRed;
    BOOL _increasing;
}
@property (strong, nonatomic) EAGLContext *context;
@property (strong, nonatomic) GLKBaseEffect *effect;

@end

@implementation HelloGLKitViewController 
@synthesize context = _context;
@synthesize effect = _effect;
// Rest of file...

-(id)initWithCoder:(NSCoder *)sourceCoder
{
	if( (self = [super initWithCoder:sourceCoder]) )
	{
        [[UIAccelerometer sharedAccelerometer] setUpdateInterval:0.20] ;
        [[UIAccelerometer sharedAccelerometer] setDelegate:self];
    }
	return self;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/

- (void)setupGL {
    
    [EAGLContext setCurrentContext:self.context];
    glEnable(GL_CULL_FACE);
    
    self.effect = [[GLKBaseEffect alloc] init];
    
    NSDictionary * options = [NSDictionary dictionaryWithObjectsAndKeys:
                              [NSNumber numberWithBool:YES],
                              GLKTextureLoaderOriginBottomLeft, 
                              nil];

    NSError * error;    
    NSString *path = [[NSBundle mainBundle] pathForResource:@"tile_floor" ofType:@"png"];
    GLKTextureInfo * info = [GLKTextureLoader textureWithContentsOfFile:path options:options error:&error];
    if (info == nil) {
        NSLog(@"Error loading file: %@", [error localizedDescription]);
    }
    self.effect.texture2d0.name = info.name;
    self.effect.texture2d0.enabled = true;

    glSetup(self.view.bounds);
    
}

- (void)tearDownGL {
    
    [EAGLContext setCurrentContext:self.context];
        
    self.effect = nil;    
    
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }

    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableMultisample = GLKViewDrawableMultisample4X;
    [self setupGL];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    
    [self tearDownGL];

    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
    self.context = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return YES; // for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - GLKViewDelegate

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {

    drawBg(self.view.bounds);
    
    [self.effect prepareToDraw];

    drawFg(self.view.bounds);
}

#pragma mark - GLKViewControllerDelegate

- (void)update {

    up_gl_t ret = updateGL(self.view.bounds, self.timeSinceLastUpdate);
    self.effect.transform.projectionMatrix = ret.projectionMatrix;
    self.effect.transform.modelviewMatrix = ret.modelviewMatrix;
 }

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
//    UIEventSubtype  subtype = event.subtype;
    NSTimeInterval  timestamp = event.timestamp;

    switch(event.type)
    {
        case UIEventTypeTouches: mytouch(timestamp); break;
        case UIEventTypeMotion: mymotion(timestamp); break;
        case UIEventTypeRemoteControl: myremote(timestamp); break;
    }
}

-(void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration
{	
	CGPoint levelPosition;
	float tiltDirection;
	float tiltMagnitude;
	
	tiltDirection = atan2(acceleration.y, acceleration.x);
	tiltMagnitude = MIN(1, sqrt( acceleration.x*acceleration.x+acceleration.y*acceleration.y));
	levelPosition.y = sin(tiltDirection)*tiltMagnitude;
	levelPosition.x = -cos(tiltDirection)*tiltMagnitude;
    
    myaccel(levelPosition, tiltDirection, tiltMagnitude);
}

@end
