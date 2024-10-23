//
//  FFmpegManager.h
//  Wansview
//
//  Created by HX on 2022/9/6.
//  Copyright © 2022 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FFmpegManager : NSObject
+ (FFmpegManager *)sharedManager;
/**
 转换视频

 @param command 需要执行的FFMpeg完整命令 不包含“ffmpeg” 使用空格分隔
 @param completionBlock 执行结果 error 为nil时成功
 */
-(void)executeCommand:(NSString *)command completionBlock:(void (^)(NSError *_Nullable error))completionBlock;
    
-(void)stopRuning;

//-(MediaInformation *)videoFileIsH265Hevc:(NSString *)videoPath;

- (NSArray *)getStreams:(NSString *)videoPath;
@end

NS_ASSUME_NONNULL_END
