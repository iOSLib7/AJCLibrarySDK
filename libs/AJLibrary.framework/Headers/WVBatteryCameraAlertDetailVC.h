//
//  WVBatteryCameraAlertDetailVC.h
//  Wansview
//
//  Created by huangxin on 2019/4/1.
//  Copyright © 2019 AJCloud. All rights reserved.
//

#import <UIKit/UIKit.h>




@interface WVBatteryCameraAlertDetailVC : UIViewController
-(instancetype)initWithDeviceId:(NSString *)deviceId;
-(instancetype)initWithDeviceId:(NSString *)deviceId date:(NSString *)dateStr;
-(void)loadAlertDetailWithDevicedId:(NSString *)deviceId date:(NSString *)dateStr;
@end


