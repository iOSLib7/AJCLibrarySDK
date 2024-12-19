//
//  BluetoothManager.h
//  Wansview
//
//  Created by t alaric on 2023/7/3.
//  Copyright © 2023 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PeripheralInfoModel.h"
#import <BabyBluetooth/BabyBluetooth.h>



NS_ASSUME_NONNULL_BEGIN

// 设置蓝牙的channel值【开发者可不做修改】
#define AJCloudChannelOnPeropheral @"AJCloudChannelOnPeropheral"

@protocol BluetoothManageDelegate <NSObject>

@optional

/**
 蓝牙被关闭
 */
- (void)systemBluetoothClose;


/**
 蓝牙已开启
 */
- (void)sysytemBluetoothOpen;


/**
 蓝牙状态
 */
- (void)systemBluetoothState:(CBManagerState)state;


/**
 扫描到的设备回调
 
 @param peripheral 扫描到的蓝牙设备
 */
- (void)getScanResultPeripheral:(PeripheralInfoModel *)peripheral;


/**
 连接成功
 */
- (void)connectSuccess;


/**
 连接失败
 */
- (void)connectFailed;


/**
 当前断开的设备
 
 @param peripheral 断开的peripheral信息
 */
- (void)disconnectPeripheral:(CBPeripheral *)peripheral;


/**
 读取蓝牙数据
 
 @param valueData 蓝牙设备发送过来的data数据
 */
- (void)readData:(NSData *)valueData;

@end


@interface BluetoothManager : NSObject

//外设的服务UUID值
@property (nonatomic, copy) NSString *serverUUIDString;
//外设的写入UUID值
@property (nonatomic, copy) NSString *writeUUIDString;
//外设的读取UUID值
@property (nonatomic, copy) NSString *readUUIDString;
//发送sequence计数
@property (nonatomic, assign) NSUInteger sequence;

@property (nonatomic, assign) CBManagerState bleState;

//当前连接的外设设备
@property (nullable, nonatomic, strong) CBPeripheral     *currentPeripheral;

/**
 单例
 
 @return 单例对象
 */
+ (BluetoothManager *)sharedManager;


@property (nonatomic, weak) id<BluetoothManageDelegate> delegate;


/**
 开始扫描周边蓝牙设备
 */
- (void)startScanPeripheral:(int)timeout;


/**
 停止扫描
 */
- (void)stopScanPeripheral;


/**
 连接所选取的蓝牙外设
 
 @param peripheral 所选择蓝牙外设的perioheral
 */
-(void)connectPeripheral:(CBPeripheral *)peripheral;

- (void)connectToDeviceId:(NSString *)deviceId;

/**
 获取当前连接成功的蓝牙设备数组
 
 @return 返回当前所连接成功蓝牙设备数组
 */
- (NSArray *)getCurrentPeripherals;


/**
 获取设备的服务跟特征值
 当已连接成功时调用有效
 */
- (void)searchServerAndCharacteristicUUID;


/**
 断开当前连接的所有蓝牙设备
 */
- (void)disconnectAllPeripherals;


/**
 断开所选择的蓝牙设备
 
 @param peripheral 所选择蓝牙外设的perioheral
 */
- (void)disconnectLastPeripheral:(CBPeripheral *)peripheral;

/**
 向蓝牙设备发送数据
 
 @param msgData 数据data值
 */
- (void)write:(NSData *)msgData;


@end

NS_ASSUME_NONNULL_END
