//
//  PlayViewController.h
//  Wansview
//
//  Created by via on 2018/5/29.
//  Copyright © 2018年 AJCloud. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum{
    playViewTabConsole = 1,
    playViewTabView = 2,
    playViewTabMotion = 3,
    playViewTabReplay = 4,
    playViewTabVoiceChange = 6

}playViewTab;

typedef enum{
    playViewLiveTypeLocal = 1,
    playViewLiveTypeUPNP = 2,
    playViewLiveTypeP2P = 3
    
}playViewLiveType;

typedef enum{
    RemoteTFTypecellular = 1,
    RemoteTFTypeLan = 2,
    RemoteTFTypeNull = 3,
    RemoteTFTypeOFFLINE = 4
}remoteTFType;



@interface PlayViewController : UIViewController
    
@property (nonatomic, copy) NSString *cameraId;
@property (assign, nonatomic) BOOL backNeedDissmiss;
@property (assign, nonatomic) BOOL isComingFromQuadScreen;
@property (assign, nonatomic) BOOL shouldAutoOpenDuplexAudio;

- (instancetype)initWithCameraId:(NSString *)cameraId;

- (instancetype)initWithReplayViewCameraId:(NSString *)cameraId;

- (instancetype)initWithUnbindedCameraId:(NSString *)cameraId;

- (instancetype)initWithCallInCameraId:(NSString *)cameraId;

@end
