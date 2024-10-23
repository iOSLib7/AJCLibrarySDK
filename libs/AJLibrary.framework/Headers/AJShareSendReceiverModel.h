//
//  AJShareSendReceiverModel.h
//  AJLibrary
//
//  Created by tmz on 2023/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJShareSendReceiverExtModel : NSObject

@property (nonatomic, copy) NSString * _Nullable deviceType;
@property (nonatomic, copy) NSString * _Nullable prodName;

@end

@interface AJShareSendReceiverModel : NSObject

@property (nonatomic, copy) NSString * _Nullable createTs;
@property (nonatomic, copy) NSString * _Nullable member; //昵称
@property (nonatomic, copy) NSString * _Nullable deviceId; //设备sn
@property (nonatomic, copy) NSString * _Nullable sendStatus; //发起分享状态，0-等待接受；1-分享成功；3-被接受着已删除
@property (nonatomic, copy) NSString * _Nullable senderName;
@property (nonatomic, copy) NSString * _Nullable senderUid;
@property (nonatomic, copy) NSString * _Nullable senderType;//发起方方账号类型 - email - phone
@property (nonatomic, copy) NSString * _Nullable rcvStatus; //接受分享状态，0-初始态（意义等同于“等待接受”），1-成功，2-无效状态（发起方已删除）
@property (nonatomic, copy) NSString * _Nullable receiverName; // 接受分享者的账号
@property (nonatomic, copy) NSString * _Nullable receiverUid; //接收者uid
@property (nonatomic, copy) NSString * _Nullable receiverType; //接受方账号类型 - email - phone
@property (nonatomic, copy) NSString * _Nullable inviteCode;
@property (nonatomic, copy) NSString * _Nullable optStatus; // 0 - invalid, 1 - valid, 默认为有效
@property (nonatomic, copy) NSString * _Nullable validTs;
@property (nonatomic, strong) AJShareSendReceiverExtModel * ext; //拓展数据

@end

NS_ASSUME_NONNULL_END
