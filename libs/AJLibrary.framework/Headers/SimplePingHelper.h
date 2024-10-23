//
//  SimplePingHelper.h
//  PingTester
//
//  Created by Chris Hulbert on 18/01/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SimplePingHelper : NSObject

- (instancetype) initWithHostName:(NSString*)address target:(id)_target sel:(SEL)_sel;
- (void)go;
+ (void)ping:(NSString*)address target:(id)target sel:(SEL)sel;

@end
