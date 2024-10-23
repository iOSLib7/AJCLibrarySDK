//
//  AJAlertSurveyModel.h
//  AJLibrary
//
//  Created by tmz on 2022/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJAlertSurveyModel : NSObject

@property (nonatomic, strong) NSString *coverImageUrl;  // 告警概览图片URL
@property (nonatomic, strong) NSString *ctime;          // 当前告警概览最新一天有告警视频的时间
@property (nonatomic, strong) NSString *deviceId;       // 设备 ID

@end

NS_ASSUME_NONNULL_END
