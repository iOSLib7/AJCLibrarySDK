//
//  AJSettings.h
//  AJLibrary
//
//  Created by tmz on 2022/10/18.
//

#import <Foundation/Foundation.h>
#import "AJError.h"
#import "AJDiagnoseModel.h"
#import "AJTimezoneModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface AJSettings : NSObject

+ (instancetype)shared;

/// 修改主设备的别名 （暂不使用，修改设备名称可直接使用changeUACDeviceAliasName）
/// @param deviceId 设备 ID
/// @param aliasName 别名
/// @param success success
/// @param failure failure
- (void)changeDeviceAliasName:(NSString *)deviceId
                    aliasName:(NSString *)aliasName
                      success:(nullable void (^)(void))success
                      failure:(nullable void (^)(AJError *))failure;

/// 修改UAC服务设备的别名
/// @param deviceId 设备 ID
/// @param aliasName 别名
/// @param success success
/// @param failure failure
- (void)changeUACDeviceAliasName:(NSString *)deviceId
                       aliasName:(NSString *)aliasName
                         success:(nullable void (^)(void))success
                         failure:(nullable void (^)(AJError *))failure;

/// 固件升级
/// @param deviceId  设备 ID
/// @param version 设备当前版本号 --> camera.base.newFwVersion
/// @param success success
/// @param failure failure
- (void)firmwareUpgrade:(NSString *)deviceId
                version:(NSString *)version
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(AJError *))failure;




/// 解绑设备
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)unbindDevice:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(AJError *))failure;



/// 图像旋转设置
/// @param deviceId  设备 ID
/// @param orientation  0 - 正常, 1 - 上下倒置, 2- 左右镜像, 3 - 镜像+倒置
/// @param success success
/// @param failure failure
- (void)orientationConfig:(NSString *)deviceId
              orientation:(NSString *)orientation
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;


/// 照明频率设置
/// @param deviceId  设备 ID
/// @param freqValue  照明频率: 50Hz/60Hz,缺省值:50Hz, 北美地区-60Hz, 欧洲-50Hz
/// @param success success
/// @param failure failure
- (void)lightingFreqConfig:(NSString *)deviceId
                 freqValue:(NSInteger)freqValue
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;

/// 音频设置
/// @param deviceId 设备 ID
/// @param micEnable 麦克风开关 0 - 关，1 - 开
/// @param speakerVolume 麦克风音量 (0 - 100)
/// @param success success
/// @param failure failure
- (void)microphoneSetting:(NSString *)deviceId
                micEnable:(NSString *)micEnable
            speakerVolume:(NSString *)speakerVolume
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;


/// 夜视配置（旧设备，暂时不用）
/// @param deviceId 设备 ID
/// @param nightMode | 0 - 关闭(全为彩色模式) , 1 - 自动(缺省) |
/// @param colorWhenOff 0|1, // 当nightMode=0时，此项打开，画面是否保持彩色，若保持则1， 否则0； 当nightMode=1时，colorWhenOff=0
/// @param success success
/// @param failure failure
- (void)nightVisionConfig:(NSString *)deviceId
                nightMode:(NSString * _Nonnull)nightMode
             colorWhenOff:(NSString * _Nonnull)colorWhenOff
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;


/// 夜视配置
/// @param deviceId 设备 ID
/// @param nightMode   0-自动，1-始终黑白，2-始终彩色
/// @param ledMode       0-自动，1-始终关闭，2-始终开启
///     自动红外夜视：nightMode=0, ledMode=0
///     关闭红外夜视自动切换：nightMode=0, ledMode=1
///     全关闭：nightMode=2, ledMode=1
///
/// @param success success
/// @param failure failure
- (void)nightVision2Config:(NSString *)deviceId
                 nightMode:(NSString * _Nonnull)nightMode
                   ledMode:(NSString * _Nonnull)ledMode
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;


/// 开启关闭指示灯
/// @param deviceId 设备 ID
/// @param enable  指示灯开关 0 - 关，1 - 开
/// @param success success
/// @param failure failure
- (void)indicatorLightConfig:(NSString *)deviceId
                      enable:(NSString *)enable
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(AJError *))failure;

/// 自动跟踪
/// @param deviceId 设备 ID
/// @param toggle  自动跟踪开关 off - 关闭，on - 开启
/// @param success success
/// @param failure failure
- (void)autoTrackConfig:(NSString *)deviceId
                 toggle:(NSString *)toggle
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(AJError *))failure;


/// 隐私模式配置 - 定时休眠
/// @param deviceId 设备 ID
/// @param enable 隐私模式总开关  0 - 关，1 - 开
/// @param wholeDayEnable 全天候开关  0 - 关，1 - 开
/// @param enable1 自定义时间1开关  0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)autoHibernateConfig:(NSString *)deviceId
                     enable:(NSString *)enable
             wholeDayEnable:(NSString *)wholeDayEnable
                    enable1:(NSString *)enable1
                 startTime1:(NSString *)startTime1
                   endTime1:(NSString *)endTime1
                  weekDays1:(NSArray<NSString *> *)weekDays1
                    enable2:(NSString *)enable2
                 startTime2:(NSString *)startTime2
                   endTime2:(NSString *)endTime2
                  weekDays2:(NSArray<NSString *> *)weekDays2
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(AJError *))failure;


/// 庭院灯灯光控制
/// @param deviceId 设备ID
/// @param toggle 开关：开 - "on"，关 - "off"
/// @param brightness 亮度 1-100
/// @param success success
/// @param failure failure
- (void)floodlightControl:(NSString *)deviceId
                   toggle:(NSString *)toggle
               brightness:(NSString *)brightness
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;


/// 声音告警监测配置
/// @param deviceId 设备 ID
/// @param enable 隐私模式总开关  0 - 关，1 - 开
/// @param susceptiveness 灵敏度等级  0 ~ 5
/// @param wholeDayEnable 全天候开关  0 - 关，1 - 开
/// @param enable1 自定义时间1开关  0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)soundMonitorConfig:(NSString *)deviceId
                    enable:(NSString *)enable
            susceptiveness:(NSString *)susceptiveness
            wholeDayEnable:(NSString *)wholeDayEnable
                   enable1:(NSString *)enable1
                startTime1:(NSString *)startTime1
                  endTime1:(NSString *)endTime1
                 weekDays1:(NSArray<NSString *> *)weekDays1
                   enable2:(NSString *)enable2
                startTime2:(NSString *)startTime2
                  endTime2:(NSString *)endTime2
                 weekDays2:(NSArray<NSString *> *)weekDays2
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;


/// 隐私区域设置
/// @param deviceId 设备 ID
/// @param enable 启用隐私区域开关 0 - 关，1 - 开
/// @param areas 隐私区域位置 ["x0,y0,x1,y1"]，区间：整体最大 --> ["0,0,10000,10000"]
/// @param success success
/// @param failure failure
- (void)privateRegionConfig:(NSString *)deviceId
                     enable:(NSString *)enable
                      areas:(NSArray<NSString *> *)areas
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(AJError *))failure;


/// 本地账号设置
/// @param deviceId 设备 ID
/// @param username 用户名
/// @param password 密码
/// @param success success
/// @param failure failure
- (void)localAccountConfig:(NSString *)deviceId
                  username:(NSString *)username
                  password:(NSString *)password
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;


/// RTSP 配置
/// @param deviceId 设备 ID
/// @param port 端口号
/// @param success success
/// @param failure failure
- (void)rtspConfig:(NSString *)deviceId
              port:(NSString *)port
           success:(nullable void (^)(void))success
           failure:(nullable void (^)(AJError *))failure;


/// ONVIF 配置
/// @param deviceId 设备 ID
/// @param enable 开关 0 - 关，1 - 开
/// @param port 端口号
/// @param verify 启用认证 0 - 关，1 - 开
/// @param success success
/// @param failure failure
- (void)onvifConfig:(NSString *)deviceId
             enable:(NSString *)enable
               port:(NSString *)port
             verify:(NSString *)verify
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(AJError *))failure;



/// 卸载SD卡
/// @param deviceId 设备 ID
/// @param label label
/// @param success success
/// @param failure failure
- (void)unmountTfCard:(NSString *)deviceId
                label:(NSString *)label
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(AJError *))failure;


/// 时区配置
/// @param deviceId 设备 ID
/// @param tzName 地区名称 例: 'Asia/Shanghai'
/// @param tzValue 时区时间 例: -480
/// @param autoAdjust 若从设备配置选择时区进行配置, 则autoAdjust = 0;  若绑定时, app获取手机操作系统时区(tzName,tzValue)对设备进行配置, 需autoAdjust = 1
/// @param tzDistrict 地区或城市, 统一使用城市: en 名称; app上按本地语言名称, 存储使用en名
/// @param success success
/// @param failure failure
- (void)timezoneConfig:(NSString *)deviceId
                tzName:(NSString *)tzName
               tzValue:(NSString *)tzValue
            autoAdjust:(NSString *)autoAdjust
            tzDistrict:(NSString *)tzDistrict
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(AJError *))failure;

/// 时区列表
/// @param success success
/// @param failure failure
- (void)getTimezonelist:(nullable void (^)(NSArray<AJTimezoneModel *> *))success
                failure:(nullable void (^)(AJError *))failure;



/// 移动检测灵敏度等级和检测区域配置langge
/// @param deviceId 设备 ID
/// @param susceptiveness 灵敏度等级  0 ~ 5
/// @param fullViewport 是否全屏 0 - 是，1 - 否
/// @param areas 检测区域  ["'x0,y0,x1,y1"]，区间：整体最大 --> ["0,0,10000,10000"]
/// @param success success
/// @param failure failure
- (void)detectionsConfig:(NSString *)deviceId
          susceptiveness:(NSString *)susceptiveness
            fullViewport:(NSString *)fullViewport
                   areas:(NSArray<NSString *> *)areas
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(AJError *))failure;


/// 人形侦测
/// @param deviceId 设备ID
/// @param humanoid 人形 0 - 关闭，1 - 开启
/// @param package  包裹 0 - 关闭，1 - 开启
/// @param pet 宠物  0 - 关闭，1 - 开启
/// @param vehicle  车辆 0 - 关闭，1 - 开启
/// @param pnmO1 其他  0 - 关闭，1 - 开启
/// @param success success
/// @param failure failure
- (void)alarmRekConfig:(NSString *)deviceId
              humanoid:(NSString *)humanoid
               package:(NSString *)package
                   pet:(NSString *)pet
               vehicle:(NSString *)vehicle
                 pnmO1:(NSString *)pnmO1
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(AJError *))failure;


/// 移动告警 设置
/// @param deviceId 设备 ID
/// @param enable 0 - 关，1 - 开
/// @param genAlarmThumb 富文本通知，0 - 关，1 - 开
/// @param wholeDayEnable 全天候时间开关 0 - 关，1 - 开
/// @param wholeStartTime 全天候开始时间 ( 000000 )
/// @param wholeEndTime 全天候结束时间 ( 235959 )
/// @param wholeWeekDays 全天候星期配置 ( [1, 2, 3, 4, 5, 6, 7] - > 每天 )
/// @param wholeFormat localStorConfig.policies[0].format
/// @param enable1 自定义时间表1开关 0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)moveMonitorConfig:(NSString *)deviceId
                   enable:(NSString *)enable
            genAlarmThumb:(NSString *)genAlarmThumb
           wholeDayEnable:(NSString *)wholeDayEnable
           wholeStartTime:(NSString *)wholeStartTime
             wholeEndTime:(NSString *)wholeEndTime
            wholeWeekDays:(NSArray<NSString *> *)wholeWeekDays
              wholeFormat:(NSString *)wholeFormat
                  enable1:(NSString *)enable1
               startTime1:(NSString *)startTime1
                 endTime1:(NSString *)endTime1
                weekDays1:(NSArray<NSString *> *)weekDays1
                  enable2:(NSString *)enable2
               startTime2:(NSString *)startTime2
                 endTime2:(NSString *)endTime2
                weekDays2:(NSArray<NSString *> *)weekDays2
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;



/// 灯光与夜视配置
/// @param deviceId 设备ID
/// @param toggle 'on' | 'off', // 此值，从 floodlightConfig.toggle 获取
/// @param brightness 亮度
/// @param enable 自动夜视是否开启  0 - 关，1 - 开
/// @param lightingDur 延迟 后自动关闭时间
/// @param triggersOn action-detect(智能灯光模式)，night-mode(夜晚全彩模式)，timing(定时灯光模式)， infrared(自动红外模式)，lightOff(全关闭模式)
/// 定时灯光模式下配置时间
/// @param enable1 时间段1开关  0 - 关，1 - 开
/// @param toggle1  'on' | 'off',从 floodlightConfig.timePolicies[0].toggle 获取
/// @param startTime1 时间段1开始时间
/// @param endTime1 时间段1结束时间
/// @param weekDays1 时间段1重复天
/// @param enable2 时间段2开关  0 - 关，1 - 开
/// @param toggle2 'on' | 'off',从 floodlightConfig.timePolicies[1].toggle 获取
/// @param startTime2 时间段2开始时间
/// @param endTime2 时间段2结束时间
/// @param weekDays2 时间段2重复天
/// @param success success
/// @param failure failure
- (void)floodlightConfig:(NSString *)deviceId
                  toggle:(NSString *)toggle
              brightness:(NSString *)brightness
                  enable:(NSString *)enable
             lightingDur:(NSString *)lightingDur
              triggersOn:(NSArray<NSString *> *)triggersOn
                 enable1:(NSString *)enable1
                 toggle1:(NSString *)toggle1
              startTime1:(NSString *)startTime1
                endTime1:(NSString *)endTime1
               weekDays1:(NSArray<NSString *> *)weekDays1
                 enable2:(NSString *)enable2
                 toggle2:(NSString *)toggle2
              startTime2:(NSString *)startTime2
                endTime2:(NSString *)endTime2
               weekDays2:(NSArray<NSString *> *)weekDays2
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(AJError *))failure;



/// 本地存储配置
/// @param deviceId 设备ID
/// @param enable 本地存储总开关  0 - 关，1 - 开
/// @param nasPath nas 路径 localStorage.nasPath
/// @param playUrlRoot  localStorage.playUrlRoot (http://{netwowrkConfig.local_ip}/api)
/// @param quality 视频质量
/// @param storageType localStorage.storageType
/// @param triggerMode  0 - 缺省(移动或声音侦测), 1-24H
/// @param writeMode 当空间存满时，存储模式 ( 1 - 覆盖最早存储，2 - 停止存储 )
/// @param wholeDayEnable 全天候时间开关 0 - 关，1 - 开
/// @param wholeStartTime 全天候开始时间 ( 000000 )
/// @param wholeEndTime 全天候结束时间 ( 235959 )
/// @param wholeWeekDays 全天候星期配置 ( [1, 2, 3, 4, 5, 6, 7] - > 每天 )
/// @param wholeFormat localStorConfig.policies[0].format
/// @param enable1 自定义时间表1开关 0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param format1 传 localStorConfig.policies[1].format
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param format2 传 localStorConfig.policies[2].format
/// @param ecoRecordDurationLimit 仅电池供电时最长录制时长 ( [10, 20, 30, 40, 50, 60] ) 秒
/// @param success success
/// @param failure failure
- (void)localStorageSetting:(NSString *)deviceId
                     enable:(NSString *)enable
                    nasPath:(NSString *)nasPath
                playUrlRoot:(NSString *)playUrlRoot
                    quality:(NSString *)quality
                storageType:(NSString *)storageType
                triggerMode:(NSString *)triggerMode
                  writeMode:(NSString *)writeMode
             wholeDayEnable:(NSString *)wholeDayEnable
             wholeStartTime:(NSString *)wholeStartTime
               wholeEndTime:(NSString *)wholeEndTime
              wholeWeekDays:(NSArray<NSString *> *)wholeWeekDays
                wholeFormat:(NSString *)wholeFormat
                    enable1:(NSString *)enable1
                 startTime1:(NSString *)startTime1
                   endTime1:(NSString *)endTime1
                  weekDays1:(NSArray<NSString *> *)weekDays1
                    format1:(NSString *)format1
                    enable2:(NSString *)enable2
                 startTime2:(NSString *)startTime2
                   endTime2:(NSString *)endTime2
                  weekDays2:(NSArray<NSString *> *)weekDays2
                    format2:(NSString *)format2
     ecoRecordDurationLimit:(NSInteger)ecoRecordDurationLimit
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(AJError *))failure;



/// 云存储配置
/// @param deviceId 设备 ID
/// @param enable 本地存储总开关  0 - 关，1 - 开
/// @param wholeDayEnable  全天候时间开关 0 - 关，1 - 开
/// @param wholeStartTime wholeStartTime 全天候开始时间 ( 000000 )
/// @param wholeEndTime 全天候结束时间 ( 235959 )
/// @param wholeWeekDays 全天候星期配置 ( [1, 2, 3, 4, 5, 6, 7] - > 每天 )
/// @param enable1 自定义时间表1开关 0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param expireAt 云存储到期时间(时间戳)；若不在云存储套餐内则填写：-1
/// @param ecoRecordDurationLimit 仅电池供电时最长录制时长 ( [10, 20, 30, 40, 50, 60] ) 秒
/// @param success success
/// @param failure failure
- (void)cloudStorageSetting:(NSString *)deviceId
                     enable:(NSString *)enable
             wholeDayEnable:(NSString *)wholeDayEnable
             wholeStartTime:(NSString *)wholeStartTime
               wholeEndTime:(NSString *)wholeEndTime
              wholeWeekDays:(NSArray<NSString *> *)wholeWeekDays
                    enable1:(NSString *)enable1
                 startTime1:(NSString *)startTime1
                   endTime1:(NSString *)endTime1
                  weekDays1:(NSArray<NSString *> *)weekDays1
                    enable2:(NSString *)enable2
                 startTime2:(NSString *)startTime2
                   endTime2:(NSString *)endTime2
                  weekDays2:(NSArray<NSString *> *)weekDays2
                   expireAt:(NSString *)expireAt
     ecoRecordDurationLimit:(NSInteger)ecoRecordDurationLimit
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(AJError *))failure;



/// 格式化 TF 卡
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)formatTfCard:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(AJError *))failure;



/// 设备截取画面
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)setSnapshot:(NSString *)deviceId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(AJError *))failure;



/// 摄像机开关 ON/OFF
/// @param deviceId 设备 ID
/// @param enable 开关 0 - 关，1 - 开
/// @param success success
/// @param failure failure
- (void)hibernateConfig:(NSString *)deviceId
                 enable:(NSString *)enable
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(AJError *))failure;



/// 恢复出厂设置
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)retoreFactory:(NSString *)deviceId
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(AJError *))failure;



/// 重启设备
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)restart:(NSString *)deviceId
        success:(nullable void (^)(void))success
        failure:(nullable void (^)(AJError *))failure;


/// 报警开关控制
/// @param deviceId 设备 ID
/// @param isOn  0:关 1:开
/// @param success success
/// @param failure failure
- (void)sirenControl:(NSString *)deviceId
                isOn:(NSString *)isOn
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(AJError *))failure;



/// 移动触发报警开关控制
/// @param deviceId 设备 ID
/// @param isOn  0:关 1:开
/// @param success success
/// @param failure failure
- (void)sirenByMotionCtrl:(NSString *)deviceId
                     isOn:(NSString *)isOn
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(AJError *))failure;


/// 加载诊断服务器地址
- (NSArray<AJDiagnoseModel *>*)loadDiagnoseServiceUrls;

@end

NS_ASSUME_NONNULL_END
