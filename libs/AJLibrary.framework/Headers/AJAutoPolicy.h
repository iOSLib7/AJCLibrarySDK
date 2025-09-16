//
//  AJAutoPolicy.h
//  AJLibrary
//
//  Created by t alaric on 2025/9/16.
//

#import <Foundation/Foundation.h>

@interface AJAutoPolicy : NSObject

@property(nonatomic, strong) NSString *_Nullable enable;    /// 1 - 开启，0 - 关闭
@property(nonatomic, strong) NSString *_Nullable lightingDur;   /// 延迟多少秒后自动关闭（最大60s）
/**
 自动灯光模式
 "action-detect", 智能灯光模式
 "night-mode"   夜晚全彩模式
 "timing"   定时灯光模式
 "infrared"  自动红外夜视
 "lightOff"  全关闭模式
 "AutoLightModeAutoSwitchNightVision"  /// 关闭红外灯，夜视自动切换
 */
@property(nonatomic, strong) NSArray <NSString *>*_Nullable triggersOn;

@end
