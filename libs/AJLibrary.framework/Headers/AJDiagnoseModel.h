//
//  AJDiagnoseModel.h
//  AJLibrary
//
//  Created by tmz on 2022/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJDiagnoseServiceModel : NSObject

@property (nonatomic, strong) NSString *serviceUrl;

@end

@interface AJDiagnoseModel : NSObject

@property (nonatomic, strong) NSArray<AJDiagnoseServiceModel *> *services;

@end

NS_ASSUME_NONNULL_END
