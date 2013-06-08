//
//  HelloGLKitViewController.h
//  HelloGLKit
//
//  Created by Ray Wenderlich on 9/28/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <GLKit/GLKit.h>
#import <UIKit/UIViewController.h>

@interface HelloGLKitViewController : GLKViewController <UIGestureRecognizerDelegate>

-(void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration;

@end
