//
//  TelnetClient.h
//  BryanYuan
//
//  Created by Bryan Yuan on 28/12/2016.
//  Copyright © 2016 Bryan Yuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HostEntry.h"

typedef void(^ TelnetSuccess)(void);
typedef void(^ TelnetFailed)(void);

@protocol TelnetDelegate <NSObject>

- (void)didReceiveMessage:(NSString *)msg;
- (void)shouldEcho:(BOOL)echo;

@end

@interface TelnetClient : NSObject <NSStreamDelegate>

@property (nonatomic, weak) id<TelnetDelegate> delegate;
@property (nonatomic, copy) TelnetSuccess success;
@property (nonatomic, copy) TelnetFailed failed;

- (void)setup:(HostEntry *)entry;
- (void)writeMessage:(NSString *)msg;

@end
