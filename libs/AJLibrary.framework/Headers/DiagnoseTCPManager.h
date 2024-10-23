//
//  DiagnoseTCPManager.h
//  Wansview
//
//  Created by tmz on 2020/3/9.
//  Copyright © 2020 AJCloud. All rights reserved.
//

#import "TCPManager.h"
#import <CocoaAsyncSocket/GCDAsyncSocket.h>

NS_ASSUME_NONNULL_BEGIN

@interface DiagnoseTCPManager : NSObject

@property(strong, nonatomic) GCDAsyncSocket *asyncsocket;
@property(copy, nonatomic) SocketSuccess connectSuccess;
@property(copy, nonatomic) SocketFailed connectFailed;
@property(copy, nonatomic) ReceviceResponse response;

+(DiagnoseTCPManager *)Share;

- (BOOL)isConnected;

-(void)connectToHost:(NSString *)host onPort:(uint16_t)port success:(SocketSuccess)success failed:(SocketFailed)failed;

- (void)sendData:(NSData *)data timeout:(NSTimeInterval)timeout tag:(long)tag response:(ReceviceResponse)response;

-(void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag;

-(BOOL)destroy;

@end

NS_ASSUME_NONNULL_END
