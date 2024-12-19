//
//  BleResponseModel.h
//  Wansview
//
//  Created by t alaric on 2023/7/12.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BleResponseModel : NSObject

@property (nonatomic, assign) NSInteger control;
@property (nonatomic, assign) NSInteger sequence;
@property (nonatomic, assign) NSInteger cmd;
@property (nonatomic, assign) NSInteger ack;

@end

NS_ASSUME_NONNULL_END
