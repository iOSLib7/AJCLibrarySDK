//
//  WVDynamicDetailVC.h
//  VideoPlayer
//
//  Created by HX on 2018/6/20.
//  Copyright © 2018年 HX. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef enum : NSUInteger {
    AlertTypeAll,
    AlertTypeMotion,
    AlertTypeHuman,
    AlertTypeFace,
    AlertTypePackage,
    AlertTypePet,
    AlertTypeVehicle,
    AlertTypeVisitor,
    AlertTamperAlarm,
} AlertType;

@interface WVAlertDetailViewController : UIViewController
-(instancetype)initWithDeviceId:(NSString *)deviceId;
-(instancetype)initWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr;
-(void)loadAlertDetailWithDevicedId:(NSString *)deviceId date:(NSString *)dateStr;
@end
