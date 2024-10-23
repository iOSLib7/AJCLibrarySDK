//
//  AJCloudOrderModel.h
//  AJLibrary
//
//  Created by iOS on 2023/11/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN




@interface AJCloudOrderProductModel : NSObject
@property(strong,nonatomic) NSString *buyMode;
@property(strong,nonatomic) NSString *unit;
@property(strong,nonatomic) NSString *serviceMonths;

@end


@interface AJCloudOrderDeviceModel : NSObject
@property(strong,nonatomic) NSString *did;
@property(strong,nonatomic) NSString *devGatewayUrl;
@property(strong,nonatomic) NSString *devCloudStorUrl;
@property(strong,nonatomic) NSString *devTzName;
@property(strong,nonatomic) NSString *devTzValue;
@property(strong,nonatomic) NSString *devVendorCode;

@end

@interface AJCloudOrderModel : NSObject
///云储套餐状态  1: inUse  2:canceled 3:expired 4:suspended 5:resumed
@property(strong,nonatomic) NSString *status;
///套餐绑定的设备
@property(strong,nonatomic) NSArray<AJCloudOrderDeviceModel*> *devices;
///开始时间
@property(strong,nonatomic) NSString *validTsStart;
///结束时间
@property(strong,nonatomic) NSString *validTsEnd;
@property(strong,nonatomic) AJCloudOrderProductModel *product;
@property(strong,nonatomic) NSString *name;
@property(strong,nonatomic) NSString *payMode;
@property(strong,nonatomic) NSString *trialPeriod;
@end


@interface AJCloudOrderStatusModel : NSObject

///0-无套餐； 1-套餐正常  5-套餐暂停
@property(strong,nonatomic) NSString *status;

@end

NS_ASSUME_NONNULL_END
