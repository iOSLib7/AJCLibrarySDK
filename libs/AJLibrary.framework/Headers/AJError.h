//
//  AJError.h
//
//
//  Created by Tianbao Wang on 2020/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJError : NSObject

@property (nonatomic, strong) NSString *message;
@property (nonatomic, assign) NSInteger code;

+ (AJError *)errorWithMessage:(NSString *)message code:(NSInteger)code;

@end

NS_ASSUME_NONNULL_END
