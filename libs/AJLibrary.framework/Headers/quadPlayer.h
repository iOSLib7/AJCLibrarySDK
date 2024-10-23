//
//  quadPlayer.h
//  Wansview
//
//  Created by HX on 2018/10/12.
//  Copyright © 2018 AJCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WVPlayerStatusView.h"

typedef enum {
    cameraErrorOffline   = 1,
    cameraErrorNetwork   = 2,
    cameraErrorTurnedOff = 3,
    cameraErrorInvalid   = 4,
    cameraErrorP2PFailed =5
}cameraError;

typedef enum {
    quadPlayerDecodeTypeVLC=1,
    quadPlayerDecodeTypePrivate
}quadPlayerDecodeType;

typedef void (^quadRemovePlayer)(NSInteger removeIndex);
typedef void (^quadRetryAction)(NSInteger viewIndex);

@protocol quadPlayerDelegate <NSObject>
@optional
- (void)quadPlayerRetryAction:(NSInteger)viewIndex;
- (void)quadPlayerGotoCameraDetail:(NSInteger)viewIndex;
- (void)quadPlayerStateStop:(NSInteger)viewIndex;
- (void)quadPlayerDidHaveVideoOut:(NSInteger)viewIndex;
- (void)quadPlayermuteBtnPressed:(NSInteger)viewIndex isplayAuido:(BOOL)isplayAuido;
@optional

@end

@interface quadPlayer : UIView
@property (weak)                        id<quadPlayerDelegate>   delegate;
@property (copy, nonatomic) quadRemovePlayer removeView;

@property (copy, nonatomic) quadRemovePlayer removePlayerView;

@property (copy, nonatomic) quadRetryAction reTry;
@property (assign, nonatomic) NSInteger viewIndex;
@property (strong, nonatomic)           WVPlayerStatusView *indicator;
@property (strong, nonatomic) NSString *playCameraID;
- (instancetype)init;

- (void)stop;

- (void)play;

- (void)dismiss;

- (void)showLoadView:(NSString *)msg;
- (void)showRefreshBtn:(NSString *)msg;
- (void)hideLoadView;

- (void)showRetrtBtn;

- (void)cameraName:(NSString *)name;

- (void)playWithURL:(NSString *)URLString;

- (void)showErrorMode:(cameraError)errorType;

- (void)showPlaceHolder:(UIImage *)image;

- (void)showStopRetryView;

- (void)dismissAction;
- (void)closeAction;
-(void)closePlayerAction;
- (void)playWithCameraID:(NSString *)CameraID;

- (void)wakeUpBatteryCam:(NSString *)batteryID;
- (void)decodeType:(quadPlayerDecodeType)decodeType;
- (void)playPrivateStreamWithCameraId:(NSString *)cameraID;
-(void)playBatterySingleWithCameraID:(NSString *)cameraID;
-(void)nightMode:(BOOL)nightMode;

-(void)playAudio:(BOOL)isPlayAudio;

- (void)saveVideoSnapshotAt:(NSString *)path withWidth:(int)width andHeight:(int)height;
@end
