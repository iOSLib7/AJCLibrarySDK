//
//  WVPlayerStatusView.h
//  VideoPlayer
//
//  Created by HX on 2018/6/25.
//  Copyright © 2018年 HX. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum{
    cameraStatusGettingUrl = 1,
    cameraStatusPreparePlay = 2,
    cameraStatusNetworkProblem = 3,
    cameraStatusRetry = 4
}StatusViewCameraStatus;



typedef void(^BtnPressed)(void);

@interface WVPlayerStatusView : UIView
-(instancetype)initWithFrame:(CGRect)frame;
@property(copy,nonatomic) BtnPressed BtnPressed;
@property(copy,nonatomic) BtnPressed DiagnoseBtnPressed;
@property(assign,nonatomic) BOOL shouldShowDiaBtn;

-(void)showPlayBtnInView:(UIView *)view;
-(void)showReplayBtnInView:(UIView *)view;
-(void)showLoadingViewInView:(UIView *)view;

-(void)hideLoadingView;
-(void)forceHideLoadingView;

-(void)showStatus:(StatusViewCameraStatus)status msg:(NSString *)Msg;
-(void)showStatus:(StatusViewCameraStatus)status msg:(NSString *)Msg force:(BOOL)isforce;
@end
