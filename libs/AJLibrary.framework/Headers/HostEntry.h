//
//  HostEntry.h
//  Wansview
//
//  Created by TMZ on 2020/2/10.
//  Copyright © 2020 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HostEntry : NSObject

@property (nonatomic, copy) NSString *host;
@property (nonatomic, copy) NSString *port;
@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *password;

@end

NS_ASSUME_NONNULL_END
