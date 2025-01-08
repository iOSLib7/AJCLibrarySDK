//
//  AJFeedTonesConfigModel.h
//  AJLibrary
//
//  Created by t alaric on 2025/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJCustomSoundDesModel : NSObject

@property(nonatomic, strong) NSString *_Nullable name;  // 名称(MAX: 32字节)
@property(nonatomic, strong) NSString *_Nullable autype;// 音频格式(如g711, amr, mp3等)
@property(nonatomic, strong) NSString *_Nullable url;   // 文件下载链接
@property(nonatomic, strong) NSString *_Nullable memo;  // 描述
@property(nonatomic, strong) NSString *_Nullable rects; // 录制时间戳(builtins 一般设置为0；customs 设置音频录制时间戳)
@property(nonatomic, strong) NSString *_Nullable lang;  // 语言(customs - "")

@end

@interface AJFeedTonesConfigModel : NSObject

@property(nonatomic, strong) NSString *_Nullable curToneGroup;  // 当前tone group(值域: customs 缺省 customs)
@property(nonatomic, strong) NSString *_Nullable curToneName;   // 当前tone name(声音名称)
@property(nonatomic, strong) NSArray<AJCustomSoundDesModel *> *_Nullable customs;   // 自定义组

@end


NS_ASSUME_NONNULL_END
