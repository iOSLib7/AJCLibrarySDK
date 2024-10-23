//
//  AJDiscoverDeviceModel.h
//  AJLibrary
//
//  Created by tmz on 2022/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJDiscoverDeviceModel : NSObject

@property (nonatomic, strong) NSString *deviceType;
@property (nonatomic, strong) NSString * deviceId;
@property (nonatomic, strong) NSString * deviceIp;
@property (nonatomic, strong) NSString * deviceMask;
@property (nonatomic, strong) NSString * bindStatus;
@property (nonatomic, strong) NSString * bindAuthCode;
@property (nonatomic, strong) NSString * szProductName;

@end

NS_ASSUME_NONNULL_END
