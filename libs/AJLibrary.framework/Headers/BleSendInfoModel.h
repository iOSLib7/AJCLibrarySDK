//
//  BleSendInfoModel.h
//  Wansview
//
//  Created by t alaric on 2023/7/5.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PeripheralInfoModel.h"

NS_ASSUME_NONNULL_BEGIN


// 蓝牙单包发送最大 20 字节，超出部分拆包
@interface BleSendInfoModel : NSObject

@property (nullable, nonatomic, strong) NSString *dataString;     // 单个包数据
@property (nonatomic, assign) BleNetCmd cmd;
@property (nonatomic, assign) NSUInteger sequence;  // 从 1 开始，每次发送时加 1，发送帧和确认帧的 Sequence 相同
@property (nonatomic, assign) NSUInteger control;   // 0:代表 Payload 没有进行加密处理
@property (nullable, nonatomic, strong) NSData *payloadData;

- (NSData *)data;

@end

NS_ASSUME_NONNULL_END
