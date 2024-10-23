//
//  AJDownload.h
//  AJLibrary
//
//  Created by tmz on 2023/2/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJDownload : NSObject

/**
*    单例
*/
+ (instancetype)shared;

/// 下载云存储或告警视频
/// - Parameters:
///   - deviceId: 设备ID
///   - mediasUrls: 视频URL数组，可传多个，最后会合并成一个视频
///   - downloadPath: 下载路径，若传空，则默认下载到系统相册
///   - progressHandler: 下载进度
///   - successHandler: 下载成功
///   - failureHandler: 下载失败
- (void)downloadWithDeviceId:(NSString *)deviceId
                  mediasUrls:(NSArray *)mediasUrls
                downloadPath:(NSString *)downloadPath
             progressHandler:(nullable void (^)(float))progressHandler
              successHandler:(nullable void (^)(void))successHandler
              failureHandler:(nullable void (^)(NSError *))failureHandler;

@end

NS_ASSUME_NONNULL_END
