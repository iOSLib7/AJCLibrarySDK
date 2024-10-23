//
//  WVGetPlayUrlManager.h
//  Wansview
//
//  Created by HX on 2018/10/15.
//  Copyright © 2018 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlayViewController.h"
#import <objc/runtime.h>
#import "quadPlayer.h"
#define kGetPlayUrlSuccessKey "GetPlayUrlSuccess"
#define kGetPlayUrlFailKey "GetPlayUrlFail"


typedef void(^ GetPlayUrlSuccess)(NSString *plaUrl ,playViewLiveType liveType);

typedef void(^ GetPlayUrlFail)(NSString *errorCode);


typedef void(^ cameraIsInLanSuccess)(void);
typedef void(^ cameraIsInLanFail)(void);


@interface WVGetPlayUrlManager : NSObject
//+ (WVGetPlayUrlManager *)sharedInstance;
//+ (void)reSetSharedInstance;
@property(strong,nonatomic) NSString *qualiNum;

-(void)getPlayUrlWithCameraID:(NSString *)cameraID success:(GetPlayUrlSuccess )success failed:(GetPlayUrlFail)failed;
-(void)cameraIsInLanWitHCameraID:(NSString *)cameraID timeOut:(NSTimeInterval)time success:(cameraIsInLanSuccess)success failed:(cameraIsInLanFail)failed;

-(void)changeResolutionWithCameraID:(NSString *)cameraID quality:(NSString *)quality liveType:(playViewLiveType)liveType success:(GetPlayUrlSuccess)success failed:(GetPlayUrlFail)failed;

-(void)reset;

-(void)cameraIsInLanWitHCameraID:(NSString *)cameraID success:(cameraIsInLanSuccess )success failed:(cameraIsInLanFail)failed;


@end
