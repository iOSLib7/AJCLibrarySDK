//
//  AJDevice.h
//  AJLibrary
//
//  Created by Tianbao Wang on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AJError.h"
#import "AJDeviceInfoModel.h"
#import "AJCloudStorageModel.h"
#import "AJAlarmListModel.h"
#import "AJCloudStorageDeleteModel.h"
#import "AJQualityModel.h"
#import "AJFeedLogsModel.h"
#import "AJUploadNotifyModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^tfSuccess)(NSString* portNum);

typedef void(^tfFailure)(AJError *error);

typedef enum {
    AJDeviceConnectStatusConnecting=1,
    AJDeviceConnectStatusConnected,
    AJDeviceConnectStatusDisConnected,
    AJDeviceConnectStatusFailed,
    AJDeviceConnectStatusOffline
}AJDeviceConnectStatus;


typedef enum : NSUInteger {
    AJDevicePTZControlDirectionUp,
    AJDevicePTZControlDirectionLeft,
    AJDevicePTZControlDirectionDown,
    AJDevicePTZControlDirectionnRight,
    AJDevicePTZControlDirectionCenter,
} AJDevicePTZControlDirection;

@protocol AJDeviceDelegate <NSObject>
@optional
/**
 *  设备连接P2P状态回调
 *  @param     deviceId              摄像头id
 *  @param     status                连接状态
 */
- (void)AJDeviceConnectStatusDeviceId:(NSString *)deviceId status:(AJDeviceConnectStatus)status;

@end





@interface AJDevice : NSObject
@property (weak)                        id<AJDeviceDelegate>   delegate;
/**
*    单例
*/
+ (instancetype)shared;


/**
 *    获取设备列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryDevices:(nullable void (^)(NSArray<AJDeviceInfoModel *> *))success
             failure:(nullable void (^)(AJError *))failure;


/**
 *    获取单个设备详情
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryDeviceInfo:(NSString *)deviceId
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(AJError *))failure;


/**
 *    加载摄像头页面
 *    @param     deviceId              摄像头id
 */
- (void)startCameraView:(NSString *)deviceId;



/**
 *    初始化Connection
 *
 */
-(void)loadCameras;

/**
 *  对设备进行P2P连线（状态回掉请注册AJDeviceDelegate）
 *  @param     deviceId              摄像头id
 */
-(void)ConnectedWithDeviceId:(NSString *)deviceId;


/**
 *    强制重联设备
 *    @param     deviceId              摄像头id
 */
-(void)forceReConectedWithCameraID:(NSString *)deviceId;


/**
 *    重置所有P2P连接
 *
 */
-(void)resetConnection;


- (void)connectionShouldEncrypt:(BOOL)ShouldEncrypt DeviceId:(NSString *)deviceId;


/**
 *    网络环境发生变化请调用
 *
 */
-(void)networkChangeAction;
/**
 *    查询设备连接状态
 *
 */
-(AJDeviceConnectStatus)statusForCamera:(NSString *)deviceId;

/**
 *    断开设备连接
 *    @param     deviceId              摄像头id
 */
-(void)disConnectedWithCamID:(NSString *)deviceId;

/**
 *    连接电池设备
 *    @param     deviceId              摄像头id
 */
-(void)batterySingleBeginConnect:(NSString *)deviceId;

/**
 *    PTZControl单步移动云台
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzControl:(NSString *)deviceId direction:(AJDevicePTZControlDirection)direct;

/**
 *    PTZControl连续移动开始
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzContinueControl:(NSString *)deviceId direction:(AJDevicePTZControlDirection)direct;

/**
 *    PTZControl连续移动结束
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzControlEnd:(NSString *)deviceId;

/**
 *    PTZControl回正
 *    @param     deviceId              摄像头id
 */
- (void)cameraPtzResetControl:(NSString *)deviceId;



/**
 *    改变视频分辨率
 *    @param     deviceId              摄像头id
 *    @param     resoNum              分辨率参数
 */
- (void)changeResolution:(NSString *)deviceId Quilt:(NSString *)resoNum;



/**
 *    初始化远程TF卡
 *    @param     deviceId              摄像头id
 *    YES :成功
 *    NO: 失败
 */
- (void)initRemoteTF:(NSString *)deviceId
             success:(nullable void (^)(NSString *))success
             failure:(nullable void (^)(AJError *))failure;

/**
 *    强制断开设备
 *    @param     deviceId              摄像头id
 */
- (void)forceDisconenct:(NSString *)deviceId;


/**
 *    获取云存储日历列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudStorageCalendarMasterUid:(NSString*)masterUid
                                  deviceId:(NSString *)deviceId
                                   success:(nullable void (^)(NSArray<NSString *> *))success
                                   failure:(nullable void (^)(AJError *))failure;

/**
 *    获取云存储列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudStorageVideoListMasterUid:(NSString*)masterUid
                                   deviceId:(NSString *)deviceId
                                 dayStartTs:(double)dayStartTs
                                   dayEndTs:(double)dayEndTs
                                    success:(nullable void (^)(NSArray<AJCloudStorageModel *> *))success
                                    failure:(nullable void (^)(AJError *))failure;


/**
 *    获取TFCard日历列表
 *     !!!!只有当remoteTFCardInit 成功后才有效
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryTFCardCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(AJError *))failure;


/**
 *    获取TFCard视频列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryTFCardVideoListDeviceId:(NSString *)deviceId
                          dayStartTs:(double)dayStartTs
                            dayEndTs:(double)dayEndTs
                             success:(nullable void (^)(NSArray<AJCloudStorageModel *> *))success
                             failure:(nullable void (^)(AJError *))failure;



/**
 *    获取告警日历列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryAlarmCalendarDeviceId:(NSString *)deviceId
                            success:(nullable void (^)(NSArray<NSString *> *))success
                            failure:(nullable void (^)(AJError *))failure;

/**
 *    获取告警列表
 *
 *     @param     cdate                日期
 *     @param     limit                获取数量 -1:全部
 *     @param     isToday               是否为今天   0 or 1
 *     @param     isTodayFirst          是否今天第一次请求 0 or 1
 *     @param     ctime          当前日期的结束 eg:2022116235959
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
-(void)queryAlarmListWithDeviceId:(NSString *)deviceId
                            cdate:(NSString * _Nonnull)cdate
                            limit:(NSInteger)limit
                          isToday:(NSInteger)isToday
                     isTodayFirst:(NSInteger)isTodayFirst
                            ctime:(NSInteger)ctime
                          success:(nullable void (^)(AJAlarmListModel *))success
                          failure:(nullable void (^)(AJError *))failure;

/**
 *    删除云存储视频
 *云存储时间格式：20221116235959000 精度到毫秒
 *     @param     start                开始
 *     @param     end                结束
 *     @param     relDays               整天删除的开始和结束
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleteCloudVideoList:(NSString * _Nonnull)deviceId
                       start:(AJCloudStorageDeleteModel * _Nonnull)start
                         end:(AJCloudStorageDeleteModel * _Nonnull)end
                     relDays:(AJCloudStorageDeleteRealDayModel * _Nonnull)relDays
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(AJError *))failure;


/**
 *    删除TF卡视频
 *TF卡时间格式：20221116235959 精度到秒
 *     @param     start                开始
 *     @param     end                结束
 *     @param     relDays               整天删除的开始和结束
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleteLocalVideoList:(NSString * _Nonnull)deviceId
                       start:(AJCloudStorageDeleteModel * _Nonnull)start
                         end:(AJCloudStorageDeleteModel * _Nonnull)end
                     relDays:(AJCloudStorageDeleteRealDayModel * _Nonnull)relDays
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(AJError *))failure;



/**
 *    添加视角
 *     @param     image                预览图
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */

- (void)viewAngleAdd:(NSString *)deviceId
        previewImage:(UIImage *)image
             success:(void (^)(void))success
             failure:(void (^)(AJError * _Nonnull))failure;

/**
 *    删除视角
 *     @param     angleIndex           需要删除的视角的索引
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleViewAngle:(NSString *)deviceId
           angleIndex:(NSString *)angleIndex
              success:(void (^)(void))success
              failure:(void (^)(AJError * _Nonnull))failure;


/**
 *    转向指定视角
 *     @param     angleIndex           需要转向的视角的索引
 *
 */
- (void)moveToViewAngle:(NSString *)deviceId
             angleIndex:(NSString *)angleIndex;


/**
 *    删除告警
 *     @param     cdate           日期
 *     @param     ctss           需要删除告警的cts 数组
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 *
 */
- (void)deleteAlarms:(NSString *)deviceId
              cdate:(NSString *)cdate
               ctss:(NSArray *)ctss
            success:(void (^)(void))success
            failure:(void (^)(AJError * _Nonnull))failure;



/// 喂食器-喂食记录查询
/// @param deviceId 设备ID
/// @param ctime 20211120000000  (2021.11.20 00:00:00)
/// @param limit 每页数量
/// @param success success
/// @param failure failure
- (void)fetchFeedLogs:(NSString *)deviceId
                ctime:(NSString *)ctime
                limit:(NSInteger)limit
              success:(void (^)(AJFeedLogsModel * _Nonnull))success
              failure:(void (^)(AJError * _Nonnull))failure;




/// 上传文件至云端
/// @param deviceId 设备ID
/// @param resourceType 资源类型 - （自定义安抚音、自定义喂食语音、自定义警铃音、视角图片）
/// @param filePath 文件路径
/// @param success success
/// @param failure failure
- (void)uploadFile:(NSString *)deviceId
      resourceType:(AJUploadResourceType)resourceType
          filePath:(NSString *)filePath
           success:(void (^)(AJUploadNotifyModel * _Nonnull))success
           failure:(void (^)(AJError * _Nonnull))failure;


@end


NS_ASSUME_NONNULL_END
