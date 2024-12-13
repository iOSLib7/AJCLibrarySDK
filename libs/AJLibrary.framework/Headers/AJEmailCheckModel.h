//
//  AJEmailCheckModel.h
//  AJLibrary
//
//  Created by t alaric on 2024/12/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJEmailStatusModel : NSObject

@property(nonatomic, assign) NSInteger isAccount;
@property(nonatomic, assign) NSInteger hasDevice;

@end

@interface AJEmailCheckModel : NSObject

@property(nonatomic, strong) AJEmailStatusModel * _Nullable curAccount;
@property(nonatomic, strong) AJEmailStatusModel * _Nullable emailAccount;

@end

NS_ASSUME_NONNULL_END
