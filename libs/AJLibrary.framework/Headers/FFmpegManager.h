//
//  FFmpegManager.h
//  Wansview
//
//  Created by HX on 2022/9/6.
//  Copyright © 2022 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <ffmpegkit/FFmpegKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FFmpegManager : NSObject
+ (FFmpegManager *)sharedManager;
/**
 转换视频

 @param command 需要执行的FFMpeg完整命令 不包含“ffmpeg” 使用空格分隔
 @param completionBlock 执行结果 error 为nil时成功
 */
-(void)executeCommand:(NSString *)command completionBlock:(void (^)(NSError *_Nullable error))completionBlock;
- (void)executeCommand:(NSString *)command
           inputPath:(NSString *)inputPath
         progressBlock:(void (^)(float progress))progressBlock
       completionBlock:(void (^)(NSError * _Nullable error))completionBlock;
-(void)stopRuning;

- (NSString *)getCodecName:(NSString *)videoPath;

//-(MediaInformation *)videoFileIsH265Hevc:(NSString *)videoPath;
@end

NS_ASSUME_NONNULL_END
