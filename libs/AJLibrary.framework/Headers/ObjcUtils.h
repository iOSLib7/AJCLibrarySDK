//
//  ObjcUtils.h
//  Wansview
//
//  Created by TMZ on 2018/6/25.
//  Copyright © 2018年 AJCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "MJEncryptString.h"

#define Localized(key) [ObjcUtils localizedStringKey:key]
#define CameraStringKey(key, comment)   [ObjcUtils localizedStringKey:key]
#define CommonCameraStringKey(key, comment)   [ObjcUtils CommonlocalizedStringKey:key]
#define CameraStringKeyNoComment(key)   [ObjcUtils localizedStringKey:key]

#define DLog(x, ...) [ObjcUtils debugLog:[NSString stringWithFormat:@"%s", __FILE__] \
                            methodName:[NSString stringWithFormat:@"%s", __func__] \
                            lineNumber:__LINE__ \
                            message:x, ## __VA_ARGS__]








typedef enum : NSUInteger {
    WVCDeviceTypeCamera=1,
    WVCDeviceTypeLock=2,
    WVCDeviceTypeBatteryCamera=3,
    WVCDeviceTypeBatterySingle=4,
    WVCDeviceTypeSingleRing=5,
    WVCDeviceTypeDoorbell=6,
    WVCDeviceTypeGateway=8,
} WVCDeviceType;


typedef enum : NSUInteger {
    DeviceCustomTypeDomeCamera=1,
    DeviceCustomTypeIndoorCamera,
    DeviceCustomTypeOutdoorCamera,
    DeviceCustomTypeOutdoorPTZCamera,
    DeviceCustomTypeBatteryCamera,
    DeviceCustomTypePTCamera,
    DeviceCustomTypeBulletCamera,
    DeviceCustomTypeBabyCare,
    DeviceCustomTypeSpaceView,
    DeviceCustomTypeFloodLightCamera,
    DeviceCustomTypeDoorBellSingle,
    DeviceCustomTypeFeedDevice,
} DeviceCustomType;

typedef NSString *KCognitiveType NS_STRING_ENUM;

static KCognitiveType const KCognitiveType_HUMAN = @"humanoid";
static KCognitiveType const KCognitiveType_FACE = @"face";
static KCognitiveType const KCognitiveType_PACKAGE = @"package";
static KCognitiveType const KCognitiveType_PET = @"pet";
static KCognitiveType const KCognitiveType_VEHICLE = @"vehicle";

typedef NSString *KMotionType NS_STRING_ENUM;

static KMotionType const KMotionType_ALERT = @"alert";
static KMotionType const KMotionType_VISITOR  = @"visitor";
static KMotionType const KMotionType_TAMPER = @"tamper";




@interface ObjcUtils : NSObject

extern const MJEncryptStringData * const alsAjcloudBridge;

extern const MJEncryptStringData * const alAjcloudBridge;

extern const MJEncryptStringData * const fromScheme;

extern const MJEncryptStringData * const wxAjcloudBridge;

extern const MJEncryptStringData * const openAlAjcloudBridge;

extern const MJEncryptStringData * const wxAjcloudTenBridge;


+ (void)cleanVideoGroupManagerVideoMapCache;

+ (void)debugLog:(NSString *)filename methodName:(NSString *)methodName  lineNumber:(NSInteger)lineNumber message:(NSString *)message, ...;
+ (NSString *)getMilliStamp;
+ (NSInteger)daysToNowDays;
+(NSInteger)daysToNowDays:(NSString *)dateStr;
+ (NSString *)currentTimeStamp;
+ (NSString *)currentDateString;
+ (NSString *)FeedDateStringWithTimeInterval:(NSTimeInterval)TimeInterval;
+ (NSString *)feedTimeStampWithMins:(NSString *)timeStr;
+ (NSDateFormatter *)GMTDateFormatter;
+ (NSString *)currentDateStringWithsep;
+ (NSString *)weekStrWith:(NSDate *)date;
+ (NSString *)getImagePath:(UIImage *)Image;
//+ (NSString *)getTimeDesc:(NSString *)timeStr;
+ (NSString *)dateStringWithDate:(NSDate *)date;
//+ (NSString *)getTimeDescNoDay:(NSString *)timeStr;
+ (NSDate *)dateBeforeCurrentDateDay:(NSInteger)day;
+(NSInteger)MonthBetweenTwoDate:(NSString *)begin end:(NSString *)end;
+ (NSString *)mimeTypeForFileAtPath:(NSString *)path;
+ (NSString *)dateStrBeforeCurrentDateDay:(NSInteger)day;
+ (NSTimeInterval)timeIntervalMsWithDateString:(NSString *)dateStr;
+ (NSTimeInterval )timeIntervalWithDateString:(NSString *)dateStr;
+ (NSString *)dateStringWithTimeInterval:(NSTimeInterval)TimeInterval;
+ (NSString *)localizedStringKey:(NSString *)key;
+ (NSString *)CommonlocalizedStringKey:(NSString *)key;
+ (NSString *)timeStampWithTimeStr:(NSString *)inputTimeStr;
+(NSString *)timeStringWithSeconds:(NSTimeInterval)timeInterval tzValue:(NSInteger)mins;
+ (NSDateFormatter *)DateFormatterWithOffset:(NSInteger)mins formarter:(NSString *)formarter;
+ (NSString *)dateDetailStringWithTimeInterval:(NSTimeInterval)TimeInterval deviceId:(NSString *)deviceID;
+ (NSString *)dateDetailStringWithTimeInterval:(NSTimeInterval)TimeInterval deviceId:(NSString *)deviceID format:(NSString *)format;
+ (int)compareDate:(NSString*)date01 withDate:(NSString*)date02;
+ (NSString *)timeWithTimeIntervalString:(NSString *)tmpStr formatter:(NSString *)formatterStr;
+ (BOOL)is12HourFormat;
+(NSString *)timeStrWith12Format:(NSString *)timeStr;
//+(NSString *)weekStrWitHWeekDay:(NSInteger )weekDay;
+ (NSString *)stringFromHexString:(NSString *)hexString;
+ (NSString *)hexStringFromString:(NSString *)string;
+ (NSUInteger)asciiLengthOfString:(NSString *)text;
+ (NSString *)convertDataToHexStr:(NSData *)data;
+ (NSArray *)getLinesArrayOfStringInLabel:(UILabel *)label;
+ (NSInteger)textNumberOfLinesWith:(NSString *)text withTextFont:(NSInteger)count withWidth:(CGFloat)width;
+ (DeviceCustomType)CustomTypeWithProductName:(NSString *)ProductName;
+(NSString *)nameWithDeviceCustomType:(DeviceCustomType)type;
+(BOOL)TalkModeIsDupleVoice:(NSString *)cameraID;
+ (NSString *)getCurrentDeviceModel;
+ (NSMutableArray *)localDNS:(NSString *)hostName;
+ (void)clearWebCache;
+ (void)objcLog:(NSString *)logStr;
+ (void)redirectNSLogToDocumentFolder;
+(NSDate *)dateBeforeCurrentDateDay:(NSInteger)day offset:(NSInteger)mins;
+ (NSString *)resolutionDisplayNameWithQualityNum:(NSString *)QualityNum;
+ (void)postNotificationSaveToAlbumFilePath:(NSString *)filePath;

+ (NSString *)toTimeStamp:(NSString *)time format:(NSString *)format;
+ (NSString *)toDate:(NSString *)time format:(NSString *)format;
+ (NSString *)toyyyymmddStr:(NSString *)time;
+ (NSTimeInterval )timeIntervalWithDateString:(NSString *)dateStr cameraId:(NSString *)cameraId;

+(void)saveDebugImage:(UIImage *)image;
@end
