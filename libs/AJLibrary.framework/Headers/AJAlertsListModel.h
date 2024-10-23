//
//  AJAlertsListModel.h
//  AJLibrary
//
//  Created by tmz on 2022/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJCognitiveModel : NSObject

@property (nonatomic, strong) NSString *value;
//@property (nonatomic, strong) NSString *confidence;
@property (nonatomic, strong) NSString *type;

@end

@interface AJAvsModel : NSObject

@property (nonatomic, strong) NSString *tags;
@property (nonatomic, strong) NSString *url;

@end

@interface AJAlertModel : NSObject

@property (nonatomic, strong) NSString *did;
@property (nonatomic, strong) NSString *ats;
@property (nonatomic, strong) NSString *ctime;
@property (nonatomic, strong) NSArray<AJAvsModel *> *avs;
@property (nonatomic, strong) NSArray<AJCognitiveModel *> *cognitives;
@property (nonatomic, strong) NSString *cts;
@property (nonatomic, strong) NSString *duration;
@property (nonatomic, strong) NSArray<AJAvsModel *> *images;
@property (nonatomic, strong) NSString *tsStart;
@property (nonatomic, strong) NSString *tsEnd;
@property (nonatomic, strong) NSString *groupId;

@end


@interface AJAlertsListModel : NSObject

@property (nonatomic, strong) NSArray<AJAlertModel *> *alarms;
@property (nonatomic, strong) NSString *cts;
@property (nonatomic, strong) NSString *ctime;

@end

NS_ASSUME_NONNULL_END
