//
//  AJCloud.h
//  AJLibrary
//
//  Created by iOS on 2023/11/20.
//

#import <Foundation/Foundation.h>
#import "AJCloudOrderModel.h"
#import "AJError.h"

NS_ASSUME_NONNULL_BEGIN

@interface AJCloud : NSObject
/**
*    单例
*/
+ (instancetype)shared;

/**
 *    获取云存套餐状态
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudOrderStatus:(NSString *)deviceId
                      success:(nullable void (^)(AJCloudOrderStatusModel *))success
                      failure:(nullable void (^)(AJError *))failure;


/**
 *    获取云存套餐列表
 *
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)queryCloudOrderList:(nullable void (^)(NSArray<AJCloudOrderModel *> *))success
                    failure:(nullable void (^)(AJError *))failure;
@end

NS_ASSUME_NONNULL_END
