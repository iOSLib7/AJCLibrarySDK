//
//  AJFeedLogsModel.h
//  AJLibrary
//
//  Created by t alaric on 2025/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface AJFeedLogModel : NSObject

@property(nonatomic, strong) NSString *_Nullable did;  // 设备ID
@property(nonatomic, strong) NSString *_Nullable cdate;  // 生成日期, 相对设备日期(如: 20180704)
@property(nonatomic, strong) NSString *_Nullable ctime;  // 生成日期, 相对设备时间(如: 20180704101231)
@property(nonatomic, strong) NSString *_Nullable cts;  // 创建时间
@property(nonatomic, strong) NSString *_Nullable pts;  // 推送时间
@property(nonatomic, strong) NSString *_Nullable ats;  // 访问时间
@property(nonatomic, strong) NSString *_Nullable feedQuantity;  // 投喂数量
@property(nonatomic, strong) NSString *_Nullable trigger;  // mechanical - 面板操作， manual - APP手动 , timing-时间计划
@property(nonatomic, strong) NSString *_Nullable feedUnit;  // 投喂单位
@property(nonatomic, strong) NSString *_Nullable performTs;  // 执行时间戳 (秒)
@property(nonatomic, strong) NSString *_Nullable performTz;  // 执行的时区名，如Asia/Shanghai
@property(nonatomic, strong) NSString *_Nullable performResult;  // 执行结果, 0 - 不成功, 1- 成功
@property(nonatomic, strong) NSString *_Nullable expireViewAt;  // 用户展示超期时间
@property(nonatomic, strong) NSString *_Nullable expireDelAt;  // 过期-删除时间时间

@end

@interface AJFeedLogsModel : NSObject

@property(nonatomic, strong) NSArray <AJFeedLogModel *>*_Nullable feedLogs;  // 喂食记录
@property(nonatomic, strong) NSString *_Nullable ctime;  // 生成日期 20211119010101

@end


NS_ASSUME_NONNULL_END
