//
//  AJWifiListModel.h
//  AJLibrary
//
//  Created by tmz on 2022/10/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJWifiListModel : NSObject

@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, assign) BOOL open;
@property (nonatomic, assign) NSInteger signal;

@end

NS_ASSUME_NONNULL_END
