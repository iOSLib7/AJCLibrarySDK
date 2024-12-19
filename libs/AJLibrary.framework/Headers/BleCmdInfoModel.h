//
//  BleCmdInfoModel.h
//  Wansview
//
//  Created by t alaric on 2023/7/6.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleSendInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface BleCmdInfoModel : NSObject

@property (nonatomic, assign) BleNetCmd cmd;
@property (nullable, nonatomic, copy) NSString *dataString;   // 单个 cmd 发送的数据

- (NSMutableArray *)sliceDatasArray;     // 一个指令大于20字节后拆分的包

@end

NS_ASSUME_NONNULL_END
