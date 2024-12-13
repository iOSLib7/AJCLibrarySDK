//
//  AJAccountModel.h
//  AJLibrary
//
//  Created by t alaric on 2024/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJAllyModel : NSObject

@property (nonatomic, strong) NSString *allyName;
@property (nonatomic, strong) NSString * alias;
@property (nonatomic, strong) NSString * allyCode;
@property (nonatomic, strong) NSString * phone;
@property (nonatomic, strong) NSString * email;
@property (nonatomic, strong) NSString * createTs;
@property (nonatomic, assign) BOOL isPrivateEmail;
@property (nonatomic, strong) NSString * isVerifiedEmail;
@property (nonatomic, strong) NSString * username;

@end

@interface AJIdentModel : NSObject

@property (nonatomic, strong) NSArray<AJAllyModel *> *allies;
@property (nonatomic, strong) NSString * email;
@property (nonatomic, strong) NSString * phone;
@property (nonatomic, strong) NSString * status;
@property (nonatomic, strong) NSString * region;
@property (nonatomic, strong) NSString * uacNodeUrl;
@property (nonatomic, strong) NSString * nodeName;
@property (nonatomic, strong) NSString * continent;

@end


@interface AJAccountModel : NSObject

@property (nonatomic, assign) NSInteger accessExpiresIn;
@property (nonatomic, strong) NSString * accessToken;
@property (nonatomic, assign) NSInteger refreshExpiresIn;
@property (nonatomic, strong) NSString * refreshToken;
@property (nonatomic, strong) NSString * tokenType;
@property (nonatomic, strong) NSString * signToken;
@property (nonatomic, strong) NSString * alias;
@property (nonatomic, strong) AJIdentModel * ident;
@property (nonatomic, strong) NSString * uid;
@property (nonatomic, assign) NSInteger regTime;
@property (nonatomic, strong) NSString * scope;

@end

NS_ASSUME_NONNULL_END
