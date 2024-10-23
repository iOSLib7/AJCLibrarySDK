//
//  CmaeraStatusManager.h
//  Wansview
//
//  Created by HX on 2018/11/2.
//  Copyright © 2018 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CameraStatusManager : NSObject
+(instancetype) shareInstance;
-(void)loadCameraStatus;

-(NSString *)readResolutionWithDid:(NSString *)did;

-(void)updateResolution:(NSString *)NewQuliNum cameraId:(NSString *)cameraId;

-(NSArray *)LoadLocalQuadScreenDevices;

-(void)updateQuadScreenDevices:(NSArray *)DidList;
-(void)cleanLocalData;
@end
