//
//  AJBinder.h
//  AJLibrary
//
//  Created by Tianbao Wang on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import "AJError.h"
#import "AJWifiListModel.h"
#import "AJDiscoverDeviceModel.h"
#import "AJDeviceInfoModel.h"
#import "PeripheralInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    AJBinderModeQR,
    AJBinderModeSoftAP,
    AJBinderModeEth,
    AJBinderModeOnlineSetWiFi,
} AJBinderMode;


typedef void(^ DisconnectPeripheral)(void);

@interface AJBinder : NSObject

// 蓝牙断开回调
@property(copy, nonatomic)DisconnectPeripheral disconnectBlock;

/**
*    单例
*/
+ (instancetype)shared;

/**
 *    加载配网流程页面
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)startBinderView:(nullable void (^)(AJDeviceInfoModel *))success
                failure:(nullable void (^)(AJError *))failure;



/**
 *    获取配网token
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)getToken:(nullable void (^)(NSString *))success
         failure:(nullable void (^)(AJError *))failure;


#pragma mark - 二维码配网
/// Create QR code string
/// @param ssid Name of route
/// @param password Password of route
/// @param token Bind Token
/// @param success success
/// @param failure failure
- (void)createQRString:(NSString *)ssid
              password:(NSString *)password
             bindToken:(NSString *)token
               success:(nullable void (^)(NSString *))success
               failure:(nullable void (^)(AJError *))failure;


/// 二维码配网
/// @param token 配网token，从getToken获取
/// @param timeout 配网超时时长 (秒)
/// @param success 回调当前绑定的设备 ID
/// @param failure failure
- (void)startQRWiFiConfig:(NSString *)token
                  timeout:(NSTimeInterval)timeout
                  success:(nullable void (^)(NSString *))success
                  failure:(nullable void (^)(AJError *))failure;



#pragma mark - SoftAP配网
/// SoftAP 配网，获取 WIFI 列表
/// @param ssid 连接的设备 SSID 名称
/// @param success 回调 WIFI 列表
/// @param failure failure
- (void)startSoftAPConfig:(NSString *)ssid
                  success:(nullable void (^)(NSArray<AJWifiListModel *> *))success
                  failure:(nullable void (^)(AJError *))failure;




/// SoftAP 配网，配网绑定
/// @param ssid SSID 名称
/// @param password SSID 密码
/// @param timeout 绑定超时时间
/// @param success success
/// @param failure failure
- (void)softAPConnect:(NSString *)ssid
             password:(NSString *)password
              timeout:(NSTimeInterval)timeout
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(AJError *))failure;


#pragma mark - 有线配网
/// 网线配网，局域网发现设备列表
/// @param success success
/// @param failure failure
- (void)startEthConfig:(nullable void (^)(NSArray<AJDiscoverDeviceModel *> *))success
               failure:(nullable void (^)(AJError *))failure;




/// 网线配网，绑定设备
/// @param deviceId 设备ID
/// @param ipAddress  设备IP 地址，从 startEthConfig -> AJDiscoverDeviceModel 获取
/// @param timeout 绑定超时时间
/// @param success success
/// @param failure failure
- (void)ethBindDevice:(NSString *)deviceId
            ipAddress:(NSString *)ipAddress
              timeout:(NSTimeInterval)timeout
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(AJError *))failure;
 

#pragma mark - 蓝牙配网
/// 蓝牙扫描（单个返回）
/// @param timeout 超时时间
/// @param success success
/// @param failure failure
- (void)bluetoothScanDevices:(NSInteger)timeout
                     success:(nullable void (^)(PeripheralInfoModel *))success
                     failure:(nullable void (^)(AJError *))failure;



/// 蓝牙停止扫描
- (void)bluetoothStopScan;


/// 蓝牙设备连接
/// @param peripheral 蓝牙设备信息
/// @param success success
/// @param failure failure
- (void)bluetoothDeviceConnectTo:(PeripheralInfoModel *)peripheral
                         success:(nullable void (^)(void))success
                         failure:(nullable void (^)(AJError *))failure;



/// 蓝牙配网
/// @param ssid ssid名称
/// @param password ssid密码
/// @param timeout 配网检查超时时间
/// @param success success
/// @param failure failure
- (void)bluetoothSendData:(NSString *)ssid
                 password:(NSString *)password
                  timeout:(NSInteger)timeout
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;

// 断开所有蓝牙连接
- (void)disconnectAllPeripherals;

// 断开当前连接
- (void)disconnectPeripheral:(PeripheralInfoModel *)peripheral;

@end

NS_ASSUME_NONNULL_END
