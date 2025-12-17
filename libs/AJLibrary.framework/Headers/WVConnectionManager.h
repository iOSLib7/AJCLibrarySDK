//
//  WVConnectionManager.h
//  Wansview
//
//  Created by huangxin on 2019/1/23.
//  Copyright © 2019 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVGetPlayUrlManager.h"
#import "CameraConnectionModel.h"
#import "hyBaseType.h"
#import "WVCameraControlView.h"
#import <OpenAL/al.h>
#import <OpenAL/alc.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/ExtendedAudioFile.h>
NS_ASSUME_NONNULL_BEGIN

// 日志宏定义 - 通过 AJDevice.logEnable 属性控制
#define AJCLOG(fmt, ...) do { \
    if ([AJDevice shared].logEnable) { \
        NSLog(@"[AJCLOG] %s[%d] %@", __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat:fmt, ##__VA_ARGS__]); \
    } \
} while (0)

typedef void(^didReceiveMsgData)(HCHAR *pSN,HUINT32 nMsgType,HCHAR *pMsg,HUINT32 nMsgSize, HCHAR *pSubDevID,HUINT32 nSubDevIDIndex);
typedef void(^didReceiveAVData)(HCHAR *pSN,HCHAR *pData,HUINT32 nDataSize);

typedef void(^BatterySingleCallBack)(NSInteger localPort);



@interface WVConnectionManager : NSObject
+(instancetype) shareInstance;
-(void)connectWithCameraID:(NSString *)cameraID;
-(void)forceReConectedWithCameraID:(NSString *)cameraID;
-(void)resetConnection;
-(void)networkChangeAction;
-(void)reConnection;
-(void)Clean;
-(void)loadCameras;
-(ConnectionStatus)statusForCamera:(NSString *)deviceId;
-(WVGetPlayUrlManager *)urlManagerWithCamerID:(NSString *)cameraID;
-(CameraConnectionModel *)modelFoeCameraID:(NSString *)cameraID;
@property(assign,nonatomic) BOOL networkChange;
-(void)playPrivateStreamWithCameraID:(NSString *)cameraID resution:(NSString *)qualNum;
-(void)stopPlayPrivateStreamWithCameraID:(NSString *)cameraID;
-(void)startAudio:(NSString *)cameraID;
-(void)stopAudio:(NSString *)cameraID;
-(void)updateLocalPlayUrl:(NSString *)cameraID isInLAN:(BOOL)isLan localUrl:(NSString *)url;
-(void)startTalk:(NSString *)cameraID;
-(void)stopTalk:(NSString *)cameraID;
-(void)disConnectedWithCamID:(NSString *)cameraID;
-(void)batterySingleBeginConnect:(NSString *)cameraId;

- (void)addAVObserver:(id)observer callback:(didReceiveAVData)callback;
- (void)addMsgObserver:(id)observer callback:(didReceiveMsgData)callback;
- (void)cameraPtzControl:(NSString *)cameraID direction:(controlViewDirection)direct;
- (void)cameraPtzContinueControl:(NSString *)cameraID direction:(controlViewDirection)direct;
- (void)cameraPtzControlEnd:(NSString *)cameraID;
- (void)cameraPtzResetControl:(NSString *)cameraID;
- (void)changeResolution:(NSString *)cameraID Quilt:(NSString *)resoNum;

-(void)wakeUpBCam:(NSString *)cameraID;
-(void)BcamSleep:(NSString *)cameraID;
//-(void)removeDataCallBack;
-(void)removeDataCallBack:(id)observer;

-(void)batterySingleConnectWithCmaeraId:(NSString *)cameraID;
-(void)batterySingleDisconenct:(NSString *)cameraID;

- (void)batterySingleUpgagrade:(NSString *)cameraID;
- (void)batterySingleRefactory:(NSString *)cameraID;
- (void)batterySingleSnapshot:(NSString *)cameraID;

- (void)FocusInStartDeviceId:(NSString *)cameraID;
- (void)FocusOutStartDeviceId:(NSString *)cameraID;
- (void)ZoomInStartDeviceId:(NSString *)cameraID;
- (void)ZoomOutStartDeviceId:(NSString *)cameraID;
- (void)ZoomFocusStopDeviceId:(NSString *)cameraID;

-(void)remoteTFCardToggleWithCameraID:(NSString *)cameraID;

-(void)tempFlagTrigleCameraID:(NSString *)cameraID;
-(void)closeRemoteTFTcpConnection:(NSString *)cameraID;
-(void)openRemoteTFTcpConnection:(NSString *)cameraID;
-(NSInteger)RecoveryLocalRelayWithCameraID:(NSString *)cameraID;
-(NSInteger)TFRecoveryLocalRelayWithCameraID:(NSString *)cameraID;

-(void)batteryTaskRecoveryCallBack:(BatterySingleCallBack)callback;
-(void)voiceDidChange:(NSInteger )type;
-(void)resetVoiceChnage;
-(void)forceDisconenct:(NSString *)cameraID;


-(void)SwitchToSFocus:(NSString *)cameraID;
-(void)SwitchToLFocus:(NSString *)cameraID;
-(void)getCurrentLensWiththDeviceID:(NSString *)cameraID;
-(int)sendVideoData:(NSData *)videoEncodeData index:(NSInteger)videoIndex cameraID:(NSString *)cameraID isIframe:(BOOL)isIframe;



@property (nonatomic) ALCdevice     *m_alDevice;
@property(strong,nonatomic) NSMutableDictionary *resolutionDIC;

@end

NS_ASSUME_NONNULL_END
/******

 todo:
 1、账号被踢出 需要断开链接 重置manager       v
 2、quadScreen 播放                v
 3、网络变化  重置链接 和 重新链接    v
 4、播放分辨率的同步   判断是否同一个resolution             v
 
 *******/



