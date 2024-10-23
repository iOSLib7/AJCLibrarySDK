//
//  VLCUtils.h
//  AJLibrary
//
//  Created by Tianbao Wang on 2022/9/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VLCUtils : NSObject
+ (VLCUtils *)sharedManager;

///**
// 转换视频
// 
// @param inputPath 输入视频路径
// @param outpath 输出视频路径
// @param processBlock 进度回调
// @param completionBlock 结束回调
// */
//- (void)converWithCMD:(NSString *)CMDSTR
//               processBlock:(void (^)(float process))processBlock
//            completionBlock:(void (^)(NSError *error))completionBlock;
//
//// 转换停止
//- (void)stopRuning;
@end

NS_ASSUME_NONNULL_END
