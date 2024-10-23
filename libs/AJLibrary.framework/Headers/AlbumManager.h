//
//  AlbumManager.h
//  Wansview
//
//  Created by tmz on 2022/6/2.
//  Copyright © 2022 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

typedef void(^SaveToPhotoLibraryBlock)(BOOL success, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface AlbumManager : NSObject

+ (instancetype)shareInstance;

- (void)photoLibraryRequestAuthorization:(void(^)(PHAuthorizationStatus status))handler;

- (void)saveVideoWithVideoURL:(NSURL *)videoURL
                    completed:(SaveToPhotoLibraryBlock)completedBlock;

- (void)saveImageWithImage:(UIImage *)image
                 completed:(SaveToPhotoLibraryBlock)completedBlock;

@end

NS_ASSUME_NONNULL_END
