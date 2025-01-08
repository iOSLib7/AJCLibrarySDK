//
//  AJFeedTimingConfigModel.h
//  AJLibrary
//
//  Created by t alaric on 2025/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJFeedTimingModel : NSObject

@property(nonatomic, strong) NSString *_Nullable no;  // 编号(从1开始)
@property(nonatomic, strong) NSString *_Nullable enable;// 启用(0或1)
@property(nonatomic, strong) NSString *_Nullable type;   // 类型(once一次, repeat重复)
@property(nonatomic, strong) NSString *_Nullable startTime;  // 开始时间(格式如 080000)
@property(nonatomic, strong) NSString *_Nullable repeatWeeks; // 周期-周(1,2,3...7)
@property(nonatomic, strong) NSString *_Nullable onceTimestamp;  // 一行执行时间戳(秒）
@property(nonatomic, strong) NSString *_Nullable feedQuantity;  // 喂食数量
@property(nonatomic, strong) NSString *_Nullable feedUnit;  // 喂食数量单位(缺省:piece)

@end



@interface AJFeedTimingConfigModel : NSObject

@property(nonatomic, strong) NSArray<AJFeedTimingModel *> *_Nullable timings;   // 时间策略

@end

NS_ASSUME_NONNULL_END
