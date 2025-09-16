//
//  AJTimePolicy.h
//  AJLibrary
//
//  Created by t alaric on 2025/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJTimePolicy : NSObject

@property(nonatomic, strong) NSString *_Nullable no;
@property(nonatomic, strong) NSString *_Nullable enable;
@property(nonatomic, strong) NSString *_Nullable startTime;
@property(nonatomic, strong) NSString *_Nullable endTime;
@property(nonatomic, strong) NSString *_Nullable toggle;
@property(nonatomic, strong) NSArray <NSString *>*_Nullable weekDays;

@end

NS_ASSUME_NONNULL_END
