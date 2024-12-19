//
//  BleTaskSender.h
//  Wansview
//
//  Created by t alaric on 2023/7/6.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BleCmdInfoModel.h"
#import "BleResponseModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface BleTaskSender : NSObject

- (instancetype)initWithBleCmdInfo:(BleCmdInfoModel *)bleCmdInfo
                           success:(nullable void (^)(BleResponseModel *reponse))success
                           failure:(nullable void (^)(BleResponseModel *reponse))failure;

- (void)write;

@end

NS_ASSUME_NONNULL_END
