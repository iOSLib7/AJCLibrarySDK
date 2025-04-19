//
//  AJAccount.h
//  AJLibrary
//
//  Created by t alaric on 2024/12/11.
//

#import <Foundation/Foundation.h>
#import "AJAccountModel.h"
#import "AJError.h"
#import "AJEmailCheckModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AJLoginStatus) {
    AJLoginExpire          = 1008,    ///登录超期（需要app退到登录页面）
    AJLoginKickout         = 1011,    ///单点登录（被踢）
};


@interface AJAccount : NSObject

/**
*    单例
*/
+ (instancetype)shared;


///用户是否已登录
@property(nonatomic,readonly) BOOL isLogin;

/**
 *    账号信息
 *
 */
- (NSString *)userAccount;


/**
 *   登录状态改变（需要返回登录页面）
 *
 */
- (void)setLoginStatusChangeBlock:(nullable void (^)(AJLoginStatus status))block;



/// 注册账号（接收验证码）
/// - Parameters:
///   - username: 用户名（邮箱 / 手机 - 国家码(4位)+ 手机号，例：008613712345678）
///   - password: 密码
///   - crCode: 国家码（例："CN"）
///   - ctCode: 洲（例："CAS"）
///   - accoutType: 登录账号类型 ("email", "phone")
///   - success: success
///   - failure: failure
- (void)regist:(NSString *)username
      password:(NSString *)password
        crCode:(NSString *)crCode
        ctCode:(NSString *)ctCode
    accoutType:(NSString *)accoutType
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(AJError *))failure;



/// 邮箱/手机激活验证码
/// - Parameters:
///   - username: 用户名称
///   - verifyCode: 验证码
///   - success: success
///   - failure: failure
- (void)accountActive:(NSString *)username
           verifyCode:(NSString *)verifyCode
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(AJError *))failure;


/// 登录
/// - Parameters:
///   - username: 用户名（邮箱 / 手机 - 国家码(4位)+ 手机号，例：008613712345678）
///   - password: 密码
///   - accoutType: 登录方式 ("email", "phone")
///   - crCode: 国家码（例："CN"）
///   - ctCode: 洲（例："CAS"）
///   - success: success
///   - failure: failure
- (void)login:(NSString *)username
     password:(NSString *)password
   accoutType:(NSString *)accoutType
       crCode:(NSString *)crCode
       ctCode:(NSString *)ctCode
      success:(nullable void (^)(void))success
      failure:(nullable void (^)(AJError *))failure;



/// 快速登录
/// - Parameters:
///   - allyName: 登录方式 ("appleid", "weixin", "line", "google")
///   - allyToken: 第三方身份验证之后，获取的ID token
///   - crCode: 国家码（例："CN"）
///   - ctCode: 洲（例："CAS"）
///   - success: success
///   - failure: failure
- (void)fastSignin:(NSString *)allyName
         allyToken:(NSString *)allyToken
            crCode:(NSString *)crCode
            ctCode:(NSString *)ctCode
           success:(nullable void (^)(AJAccountModel *))success
           failure:(nullable void (^)(AJError *))failure;




/// 邮箱账号忘记密码
/// - Parameters:
///   - username: 用户名（邮箱）
///   - password: 密码
///   - crCode: 国家码（例："CN"）
///   - ctCode: 洲（例："CAS"）
///   - success: success
///   - failure: failure
- (void)emailResetPassword:(NSString *)username
                  password:(NSString *)password
                    crCode:(NSString *)crCode
                    ctCode:(NSString *)ctCode
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;


/// 手机账号忘记密码（获取重置验证码）
/// - Parameters:
///   - username: 用户名（手机 - 国家码(4位)+ 手机号，例：008613712345678）
///   - password: 密码
///   - crCode: 国家码（例："CN"）
///   - ctCode: 洲（例："CAS"）
///   - success: success
///   - failure: failure
- (void)phoneResetPassword:(NSString *)username
                  password:(NSString * _Nonnull)password
                    crCode:(NSString *)crCode
                    ctCode:(NSString *)ctCode
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(AJError *))failure;


/// 修改密码
/// - Parameters:
///   - username: 用户名（邮箱 / 手机 - 国家码(4位)+ 手机号，例：008613712345678）
///   - oldPsw: 旧密码
///   - newPsw: 新密码
///   - success: success
///   - failure: failure
- (void)changePassword:(NSString *)username
                oldPsw:(NSString *)oldPsw
                newPsw:(NSString *)newPsw
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(AJError *))failure;


/// 检查email账号是否存在
/// - Parameters:
///   - email: 邮箱
///   - success: success
///   - failure: failure
- (void)emailCheck:(NSString *)email
           success:(nullable void (^)(AJEmailCheckModel *))success
           failure:(nullable void (^)(AJError *))failure;



/// 账号合并 email
/// - Parameters:
///   - curUsername: 当前账号用户名称
///   - bindEmail: 需要合并的邮箱
///   - identType: 当前账号的登录类型，'email'，'phone'，'allies'
///   - allyCode: 当identType为'allies'时，allyCode生效，取AJAccountModel.allies.allyCode。
///   - needVerify: 是否需要发送验证码。0-不需要，1-需要
///   - needPwd: 是否需要存储密码。0-不需要，1-需要
///   - password: 所合并的账号密码，当needPwd为1时传值
///   - success: success
///   - failure: failure
- (void)emailBindRequest:(NSString *)curUsername
               bindEmail:(NSString *)bindEmail
               identType:(NSString *)identType
                allyCode:(NSString *)allyCode
              needVerify:(NSString *)needVerify
                 needPwd:(NSString *)needPwd
                password:(NSString *)password
                 success:(nullable void (^)(AJAccountModel *))success
                 failure:(nullable void (^)(AJError *))failure;



/// 合并账号添加email（验证码确认)
/// - Parameters:
///   - email: 所绑定的邮箱
///   - verifyCode: 验证码
///   - success: success
///   - failure: failure
- (void)emailBindVerify:(NSString *)email
             verifyCode:(NSString *)verifyCode
                success:(nullable void (^)(AJAccountModel *))success
                failure:(nullable void (^)(AJError *))failure;


/// 退出登录
/// - Parameters:
///   - success: success
///   - failure: failure
- (void)signout:(nullable void (^)(void))success
        failure:(nullable void (^)(AJError *))failure;



/// 注销账号
/// - Parameters:
///   - username: 用户名
///   - password: 密码
///   - success: success
///   - failure: failure
- (void)logout:(NSString *)username
      password:(NSString *)password
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(AJError *))failure;


@end

NS_ASSUME_NONNULL_END
