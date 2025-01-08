//
//  AJUploadNotifyModel.h
//  AJLibrary
//
//  Created by t alaric on 2025/1/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AJUploadResourceTypeViewAngle,  // 视角图片
    AJUploadResourceTypeSirenSound, // 自定义警铃音
    AJUploadResourceTypeFeedTone,   // 自定义喂食语音
    AJUploadResourceTypeSoothingTone// 自定义安抚音
} AJUploadResourceType;


@interface AJUploadNotifyModel : NSObject

@property(nonatomic, strong) NSString *_Nullable resourceUrl;  // 上传后的资源URL

@end

NS_ASSUME_NONNULL_END
