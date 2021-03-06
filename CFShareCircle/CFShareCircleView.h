//
//  CFShareCircleView.h
//  CFShareCircle
//
//  Created by Camden on 12/18/12.
//  Copyright (c) 2012 Camden. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>

#define BACKGROUND_SIZE 250
#define PATH_SIZE 180
#define TEMP_SIZE 50
#define CLOSE_BUTTON_SIZE 40
#define TOUCH_SIZE 70

/** Notification that gets posted when the underRight view will appear */
extern NSString *const CFShareCircleViewCanceled;

@class CFShareCircleView;

@protocol CFShareCircleViewDelegate
- (void)shareCircleView:(CFShareCircleView *)aShareCircleView didSelectIndex:(int)index;
@end

@interface CFShareCircleView : UIView{
    CGPoint currentPosition, origin;
    BOOL dragging, visible;
    UIDeviceOrientation currentOrientation;
    CALayer *closeButtonLayer;
    CAShapeLayer *backgroundLayer, *touchLayer;
    CATextLayer *introTextLayer, *shareTitleLayer;
    NSMutableArray *imageLayers, *imageColors, *sharers;
}

@property (assign) id <CFShareCircleViewDelegate> delegate;

/** 
 Initialize the share circle with a custom list of image file names. NOTE: These images must be resources that are referenced in your project.
 
 @param array of sharer names that are going to be set for the share circle.
 */
- (id)initWithSharers: (NSArray*)someSharers;

/**
 Animates the share circle into view. 
 */
- (void)animateIn;

/**
 Animates the share circle out of view.
 */
- (void)animateOut;

@end
