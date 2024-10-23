//
//  AJAlarmListModel.h
//  AJLibrary
//
//  Created by HX on 2022/11/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJAlarmInfoModel : NSObject
@property (nonatomic, copy) NSString * _Nullable did;
@property (nonatomic, copy) NSString * _Nullable ats;
@property (nonatomic, copy) NSString * _Nullable ctime;
@property (nonatomic, copy) NSString * _Nullable videoURL;
@property (nonatomic, copy) NSString * _Nullable cdate;
@property (nonatomic, copy) NSString * _Nullable cts;
@property (nonatomic, copy) NSString * _Nullable duration;
@property (nonatomic, copy) NSString * _Nullable imageURL;
@property (nonatomic, copy) NSString * _Nullable tsStart;
@property (nonatomic, copy) NSString * _Nullable tsEnd;
@property (nonatomic, copy) NSString * _Nullable groupId;
@end

@interface AJAlarmListModel : NSObject
@property (nonatomic, copy) NSArray<AJAlarmInfoModel *> * _Nullable alarms;
@property (nonatomic, copy) NSString * _Nullable cts;
@property (nonatomic, copy) NSString * _Nullable ctime;
@end


NS_ASSUME_NONNULL_END
