//
//  WVNoDataHelpView.h
//  Wansview
//
//  Created by HX on 2018/8/16.
//  Copyright © 2018年 AJCloud. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void(^refreshAction)(void);
typedef void(^KnownAction)(void);
@interface WVNoDataHelpView : UIView
@property(copy,nonatomic) refreshAction refresh;
@property(copy,nonatomic) KnownAction Known;
-(instancetype)init;
@end

