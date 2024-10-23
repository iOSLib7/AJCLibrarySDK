//
//  HXCacheFileViewController.h
//  HX
//
//  Created by HX on 17/6/27.
//  Copyright © 2017年 HX. All rights reserved.
//  https://github.com/potato512/HXCacheFileViewController

#import <UIKit/UIKit.h>

@interface HXCacheFileViewController : UIViewController

/// 导航栏标题（默认缓存目录）
@property (nonatomic, strong) NSString *cacheTitle;
/// 数据源（默认home目录）
@property (nonatomic, strong) NSMutableArray *cacheArray;

@end
