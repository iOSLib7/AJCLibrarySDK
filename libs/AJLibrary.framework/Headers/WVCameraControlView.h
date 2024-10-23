//
//  WVCameraView.h
//  cameraControlDemo
//
//  Created by HX on 2018/5/30.
//  Copyright © 2018年 HX. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    controlViewDirectionUp,
    controlViewDirectionLeft,
    controlViewDirectionDown,
    controlViewDirectionRight,
    controlViewDirectionCenter,
} controlViewDirection;

@protocol WVCameraControlViewDelegate <NSObject>

- (void)WVCameraControlViewStepDirection:(controlViewDirection)direction;

- (void)WVCameraControlViewTouchOnceDirection:(controlViewDirection)direction;
- (void)WVCameraControlViewDirectionBegin:(controlViewDirection)direction;
- (void)WVCameraControlViewPTZEnd;

@end

typedef void (^ReturnParameter) (NSUInteger vertical, NSUInteger horizontal);

@interface WVCameraControlView : UIView

@property (nonatomic, assign) NSUInteger vertical;

@property (nonatomic, assign) NSUInteger horizontal;

@property (strong, nonatomic) UIColor *controlCoolor;

- (instancetype)initWithFrame:(CGRect)frame color:(UIColor *)backgroundColor;

@property (nonatomic, copy) ReturnParameter returnPar;

@property (weak) id<WVCameraControlViewDelegate> delegate;
@end
