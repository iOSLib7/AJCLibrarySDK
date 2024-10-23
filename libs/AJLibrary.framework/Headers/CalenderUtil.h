//
//  CalenderUtil.h
//  Wansview
//
//  Created by hx on 2018/12/14.
//  Copyright © 2018年 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CalenderUtil : NSObject

+(NSString *)dateDescAll:(NSString *)timeString;

+(NSString *)dateMonAndYear:(NSString *)timeString;

+(NSString *)daysWithNumber:(NSInteger )weekDay;

+(NSString *)daysShortWithNumber:(NSInteger )weekDay;

+(NSString *)monthWithNumber:(NSInteger)month;

+(NSString *)monthShortWithNumber:(NSInteger)month;

+(NSArray *)currentMonList;

+(NSArray *)daysListShort;

+(NSString *)dateDescMonAndDay:(NSString *)timeString;

+(NSString *)getNextDayDateString:(NSString *)dateString;
@end
