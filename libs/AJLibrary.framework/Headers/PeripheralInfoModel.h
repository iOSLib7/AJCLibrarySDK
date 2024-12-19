//
//  PeripheralInfModel.h
//  Wansview
//
//  Created by t alaric on 2023/7/3.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSInteger, BleNetCmd) {
    BleNetCmdSsid         = 0x01,        // SSID 设置
    BleNetCmdPassword     = 0x02,        // Password 设置
    BleNetCmdToken        = 0x03,        // Token 设置
    BleNetCmdLanguage     = 0x04,        // Language 设置
    BleNetCmdRegion       = 0x05,        // Region 设置
    BleNetCmdKeepAlive    = 0x11,        // 保活
    BleNetCmdEnd          = 0xEE         // 结束
};

// ServiceUUID
#define ConfigNetUUID        @"FAC1" // WiFi配网
#define WriteUUID            @"FAC2"
#define ReadUUID             @"FAC3"


#define COMPANYID            @"FACD"


NS_ASSUME_NONNULL_BEGIN

@interface PeripheralInfoModel : NSObject

@property (nonatomic, strong) NSNumber     *RSSI;
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, strong) NSDictionary *advertisementData;

- (NSString *)devVendor;

- (BOOL)isValidDev;

- (NSString *)companyId;

- (NSString *)sn;

- (NSString *)deviceVersion;

- (BOOL)support2Point4G;

- (BOOL)support5G;

- (NSString *)productName;

@end

NS_ASSUME_NONNULL_END
