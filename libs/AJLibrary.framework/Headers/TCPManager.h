//
//  TCPManager.h
//  Wansview
//
//  Created by HX on 2018/10/15.
//  Copyright © 2018 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CocoaAsyncSocket/GCDAsyncSocket.h>

typedef void(^ SocketSuccess)(void);
typedef void(^ SocketFailed)(NSError *error);
typedef void(^ ReceviceResponse)(NSString *jsonString);

@interface TCPManager : NSObject

@property(strong, nonatomic) GCDAsyncSocket *asyncsocket;
@property(copy, nonatomic) SocketSuccess connectSuccess;
@property(copy, nonatomic) SocketFailed connectFailed;
@property(copy, nonatomic) ReceviceResponse response;
@property(nonatomic) BOOL haveHeader;

+(TCPManager *)Share;

- (BOOL)isConnected;

-(void)connectToHost:(NSString *)host onPort:(uint16_t)port success:(SocketSuccess)success failed:(SocketFailed)failed;

- (void)sendData:(NSData *)data timeout:(NSTimeInterval)timeout tag:(long)tag response:(ReceviceResponse)response;

-(BOOL)destroy;

@end
