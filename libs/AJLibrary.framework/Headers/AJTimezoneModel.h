//
//  AJTimezoneModel.h
//  AJLibrary
//
//  Created by iOS on 2023/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJTimezoneModel : NSObject
@property (nonatomic, strong) NSString * tzGmt;
@property (nonatomic, strong) NSString * tzName;
@property (nonatomic, strong) NSString * tzString;
@property (nonatomic, strong) NSString * tzUtc;
@property (nonatomic, strong) NSString * tzValue;

// from TZDistrictModel
@property (nonatomic, strong) NSString * en;
@property (nonatomic, strong) NSString * zh;
@property (nonatomic, strong) NSString * fr;
@property (nonatomic, strong) NSString * de;
@property (nonatomic, strong) NSString * es;
@property (nonatomic, strong) NSString * pt;
@property (nonatomic, strong) NSString * jp;
@property (nonatomic, strong) NSString * it;
@property (nonatomic, strong) NSString * ko;
@property (nonatomic, strong) NSString * tr;
@end

NS_ASSUME_NONNULL_END
