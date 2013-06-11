//
//  HelloGLKitViewController.m
//  HelloGLKit
//
//  Created by Ray Wenderlich on 9/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "HelloGLKitViewController.h"
#include "draw.h"
//#include "missing.h"
#include "c_includes.h"

char *TANKDIR;

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

void playsound(sound_t id)
{
    if (!opt->silent)
        AudioServicesPlaySystemSound (soundFileObject[id]);
}

void sound(char *name, int arg)
{
    NSString *soundName = [NSString stringWithUTF8String: name];
    NSURL *tapSound = [[NSBundle mainBundle] URLForResource: soundName
                                             withExtension: @"wav"];

    assert(tapSound);
// Store the URL as a CFURLRef instance
CFURLRef	soundFileURLRef1 = (CFURLRef) CFBridgingRetain(tapSound);

// Create a system sound object representing the sound file.
AudioServicesCreateSystemSoundID (
                                  soundFileURLRef1,
                                  soundFileObject+arg
                                  );
}

static void rotate(UIInterfaceOrientation InterfaceOrientation)
{
switch(InterfaceOrientation)
    {
    case UIInterfaceOrientationLandscapeLeft:
        rot(0,-1,-1,0,0,-0.5);
        break;
    case UIInterfaceOrientationLandscapeRight:
        rot(0,1,1,0,0,-0.5);
        break;
    case UIInterfaceOrientationPortrait:
        rot(1,0,0,-1,0,-0.5);
        break;
    case UIInterfaceOrientationPortraitUpsideDown:
        rot(1,0,0,1,0,-0.5);
        break;
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.preferredFramesPerSecond=15;
    // start monitoring the document directory…
    NSString *path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];

    TANKDIR = strdup([[path stringByAppendingString:@"/"] UTF8String] );

    NSUserDefaults *standardDefaults = [NSUserDefaults standardUserDefaults];
    
    opt->delay = 5;
    opt->msalvos = -1;
    opt->menemies = 0;
    opt->mobjects = 0;
    opt->estart = 0;
    opt->lstart = 0;
    opt->sstart = 0;
    opt->bstart = 0;
    opt->output = 1;
    opt->scores = 0;
    opt->version = 0;
    opt->help = 0;
    opt->original = 0;
    opt->cursor = 0;
    opt->copters = [standardDefaults boolForKey:@"copters_preference"];
    opt->silent = [standardDefaults boolForKey:@"silent_preference"];
    opt->loud = [standardDefaults boolForKey:@"loud_preference"];
    opt->trails = [standardDefaults boolForKey:@"trails_preference"];
    opt->training = [standardDefaults boolForKey:@"practice_preference"];
    opt->numleft = [standardDefaults integerForKey:@"ownTanks"];
    opt->mtanks = [standardDefaults integerForKey:@"enemyTanks"];
    opt->mlanders = [standardDefaults integerForKey:@"enemyLanders"];
    opt->mmissiles = [standardDefaults integerForKey:@"enemyMissiles"];;
    opt->mblocks = [standardDefaults integerForKey:@"blocks"];
    opt->linewidth = [standardDefaults integerForKey:@"lineWidth"];
    
    sound("enemy_seen2", senemy_seen);
    sound("fire", sfire);
    sound("game_begin", sgame_begin);
    sound("game_end2", sgame_end);
    sound("kill", skill);
    sound("move", smove);
    sound("move_blocked2", smove_blocked);
    sound("object_explodes2", sobject_explodes);
    sound("salvo_fired2", ssalvo_fired);
    sound("user_died", suser_died);
    sound("user_shoots2", suser_shoots);
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
#if 1
    UIRotationGestureRecognizer *rotationGesture = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rotatePiece:)];
    [self.view addGestureRecognizer:rotationGesture];
    
    UIPinchGestureRecognizer *pinchGesture = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(scalePiece:)];
    [pinchGesture setDelegate:self];
    [self.view addGestureRecognizer:pinchGesture];
    
    UIPanGestureRecognizer *panGesture = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panPiece:)];
    [panGesture setMaximumNumberOfTouches:2];
    [panGesture setDelegate:self];
    [self.view addGestureRecognizer:panGesture];
    
    UILongPressGestureRecognizer *longPressGesture = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(showResetMenu:)];
    [self.view addGestureRecognizer:longPressGesture];
#endif
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableMultisample = GLKViewDrawableMultisample4X;
    rotate(super.interfaceOrientation);
    [self setupGL];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    
    [self tearDownGL];

    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
    for (sound_t i = 0; i < slast_sound; i++)
        AudioServicesDisposeSystemSoundID (soundFileObject[i]);
    self.context = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return intro ? YES : NO;
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
//    CGSize bsize = self.view.bounds.size;
//    int sz = (int)bsize.width;
    rotate(toInterfaceOrientation);
}

#pragma mark - GLKViewDelegate

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {

    drawBg(self.view.bounds);
    
    [self.effect prepareToDraw];

    drawFg(self.view.bounds, self.view.center);
}

#pragma mark - GLKViewControllerDelegate

- (void)update {

    up_gl_t ret = updateGL(self.view.bounds, self.view.center);
    self.effect.transform.projectionMatrix = ret.projectionMatrix;
    self.effect.transform.modelviewMatrix = ret.modelviewMatrix;
 }

#if 1
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
//    NSTimeInterval  timestamp = event.timestamp;
    switch(event.type)
    {
        case UIEventTypeTouches:
            if (exited)
            {
//                exit(0);
            }
            else
            {
                UIEventSubtype  subtype = event.subtype;
                switch(subtype)
                {
                default:
                mytouch(); break;
                }
            }
            break;
        case UIEventTypeMotion: break;
        case UIEventTypeRemoteControl: break;
    }
}
#endif

-(void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration
{	    
    myaccel(acceleration.x, acceleration.y);
}

// scale and rotation transforms are applied relative to the layer's anchor point
// this method moves a gesture recognizer's view's anchor point between the user's fingers
- (void)adjustAnchorPointForGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
    if (intro && (gestureRecognizer.state == UIGestureRecognizerStateBegan)) {
        UIView *piece = gestureRecognizer.view;
        CGPoint locationInView = [gestureRecognizer locationInView:piece];
        CGPoint locationInSuperview = [gestureRecognizer locationInView:piece.superview];
        
//        piece.layer.anchorPoint = CGPointMake(locationInView.x / piece.bounds.size.width, locationInView.y / piece.bounds.size.height);
        piece.center = locationInSuperview;
    }
}

// display a menu with a single item to allow the piece's transform to be reset
- (void)showResetMenu:(UILongPressGestureRecognizer *)gestureRecognizer
{
    if (intro && ([gestureRecognizer state] == UIGestureRecognizerStateBegan)) {
        UIMenuController *menuController = [UIMenuController sharedMenuController];
        UIMenuItem *resetMenuItem = [[UIMenuItem alloc] initWithTitle:@"Reset" action:@selector(resetPiece:)];
        CGPoint location = [gestureRecognizer locationInView:[gestureRecognizer view]];
        
        [self becomeFirstResponder];
        [menuController setMenuItems:[NSArray arrayWithObject:resetMenuItem]];
        [menuController setTargetRect:CGRectMake(location.x, location.y, 0, 0) inView:[gestureRecognizer view]];
        [menuController setMenuVisible:YES animated:YES];
        
//        self.pieceForReset = [gestureRecognizer view];
    }
}

// UIMenuController requires that we can become first responder or it won't display
- (BOOL)canBecomeFirstResponder
{
    return YES;
}

// shift the piece's center by the pan amount
// reset the gesture recognizer's translation to {0, 0} after applying so the next callback is a delta from the current position
- (void)panPiece:(UIPanGestureRecognizer *)gestureRecognizer
{
    UIView *piece = [gestureRecognizer view];
    
    [self adjustAnchorPointForGestureRecognizer:gestureRecognizer];
    
    if (intro && ([gestureRecognizer state] == UIGestureRecognizerStateBegan || [gestureRecognizer state] == UIGestureRecognizerStateChanged)) {
        CGPoint translation = [gestureRecognizer translationInView:[piece superview]];
        
        [piece setCenter:CGPointMake([piece center].x + translation.x, [piece center].y + translation.y)];
        [gestureRecognizer setTranslation:CGPointZero inView:[piece superview]];
    }
}

// rotate the piece by the current rotation
// reset the gesture recognizer's rotation to 0 after applying so the next callback is a delta from the current rotation
- (void)rotatePiece:(UIRotationGestureRecognizer *)gestureRecognizer
{
    [self adjustAnchorPointForGestureRecognizer:gestureRecognizer];
    
    if (intro && ([gestureRecognizer state] == UIGestureRecognizerStateBegan || [gestureRecognizer state] == UIGestureRecognizerStateChanged)) {
//        [gestureRecognizer view].transform = CGAffineTransformRotate([[gestureRecognizer view] transform], [gestureRecognizer rotation]);
        [gestureRecognizer setRotation:0];
    }
}

// scale the piece by the current scale
// reset the gesture recognizer's rotation to 0 after applying so the next callback is a delta from the current scale
- (void)scalePiece:(UIPinchGestureRecognizer *)gestureRecognizer
{
    [self adjustAnchorPointForGestureRecognizer:gestureRecognizer];
    
    if (intro && ([gestureRecognizer state] == UIGestureRecognizerStateBegan || [gestureRecognizer state] == UIGestureRecognizerStateChanged)) {
        [gestureRecognizer view].transform = CGAffineTransformScale([[gestureRecognizer view] transform], [gestureRecognizer scale], [gestureRecognizer scale]);
        [gestureRecognizer setScale:1];
    }
}

// ensure that the pinch, pan and rotate gesture recognizers on a particular view can all recognize simultaneously
// prevent other gesture recognizers from recognizing simultaneously
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer
{
    // if the gesture recognizers are on different views, don't allow simultaneous recognition
    if (gestureRecognizer.view != otherGestureRecognizer.view)
        return NO;
    
    // if either of the gesture recognizers is the long press, don't allow simultaneous recognition
    if ([gestureRecognizer isKindOfClass:[UILongPressGestureRecognizer class]] || [otherGestureRecognizer isKindOfClass:[UILongPressGestureRecognizer class]])
    {
        intro = 0;
        return NO;
    }
    
    return YES;
}

@end
