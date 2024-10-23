//
//  CameraConnectionModel.h
//  Wansview
//
//  Created by huangxin on 2019/1/23.
//  Copyright © 2019 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVGetPlayUrlManager.h"
#import "PlayViewController.h"
NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, ConnectionStatus) {
    ConnectionStatusConnecting = 1,
    ConnectionStatusConnected = 2,
    ConnectionStatusFailed = 3,
    ConnectionStatusOffline = 4,
    ConnectionStatusDefault = 5,
    ConnectionStatusDisconnected = 6,
};


typedef enum{
    ConnectionTypeLocal = 1,
    ConnectionTypeUPNP = 2,
    ConnectionTypeP2PR = 3,
    ConnectionTypeNone = 4,
}ConnectionType;

typedef void(^ WVConnectionResultSuccess)(NSString *plaUrl);
typedef void(^ WVConnectionResultFail)(NSString *errorMsg);



@interface CameraConnectionModel : NSObject
{
    BOOL _needChangeQuality;
    playViewLiveType _LiveType;
}
@property(strong,nonatomic) NSString *cameraID;
@property(strong,nonatomic) NSString *playUrl; //only avaliable when type is P2P and Relay
@property(assign,nonatomic) ConnectionStatus status;
@property(assign,nonatomic) ConnectionType type;
@property(assign,nonatomic) BOOL  isPlaying;
@property(assign,nonatomic) BOOL  isInLAN;
@property(assign,nonatomic) BOOL  autoReconnectEnable;
@property(strong,nonatomic) WVGetPlayUrlManager *urlManager;
@property(assign,nonatomic) BOOL  isSharedBatteryGateway;
@property(strong,nonatomic) NSString *subDevID;

-(void)connect;
-(void)disConnect;
-(void)getPlayUrlWithQualityNum:(NSString *)qualityNum success:(WVConnectionResultSuccess )success failed:(WVConnectionResultFail)failed;

@property(strong,nonatomic) NSString *currentQuality;

-(void)successBlock:(WVConnectionResultSuccess)resultSuccess;
-(void)failedBlock:(WVConnectionResultFail)resultFailed;

-(void)cleanBlock;
@end


NS_ASSUME_NONNULL_END
