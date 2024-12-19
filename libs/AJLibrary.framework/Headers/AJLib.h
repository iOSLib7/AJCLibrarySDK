//
//  AJLib.h
//  AJLibrary
//
//  Created by Tianbao Wang on 2022/9/13.
//

#import <Foundation/Foundation.h>
#import <AJLibrary/DiagnoseTCPManager.h>
#import <AJLibrary/ObjcUtils.h>
#import <AJLibrary/PlayViewController.h>
#import <AJLibrary/HXCacheFileViewController.h>
#import <AJLibrary/HXCacheFileManager.h>
#import <AJLibrary/WVAlertDetailViewController.h>
#import <AJLibrary/WVBatteryCameraAlertDetailVC.h>
#import <AJLibrary/MWPhotoBrowser.h>
#import <AJLibrary/MWPhoto.h>
#import <AJLibrary/quadScreentVC.h>
#import <AJLibrary/CameraStatusManager.h>
#import <AJLibrary/TCPManager.h>
#import <AJLibrary/NetworkUtility.h>

#import <AJLibrary/WVNoDataHelpView.h>
#import <AJLibrary/ChatViewController.h>
#import <AJLibrary/WVConnectionManager.h>
#import <AJLibrary/hardWareType.h>
#import <AJLibrary/TelnetClient.h>
#import <AJLibrary/HostEntry.h>
#import <AJLibrary/StepSlider.h>
#import <AJLibrary/CalenderUtil.h>
#import <AJLibrary/LMJVerticalScrollText.h>
#import <AJLibrary/CustomAVPlayerViewController.h>
#import <AJLibrary/WKWebViewJavascriptBridge.h>
#import <AJLibrary/SimplePingHelper.h>
#import <AJLibrary/AlbumManager.h>
#import <AJLibrary/DACircularProgressView.h>
#import <AJLibrary/FeedRecordVC.h>
#import <AJLibrary/FFmpegManager.h>
#import <AJLibrary/AJError.h>
#import <AJLibrary/AJBinder.h>
#import <AJLibrary/AJDevice.h>
#import <AJLibrary/AJMessage.h>
#import <AJLibrary/AJDownload.h>
#import <AJLibrary/AJSettings.h>
#import <AJLibrary/AJMediaPlayer.h>
#import <AJLibrary/AJWifiListModel.h>
#import <AJLibrary/AJDiscoverDeviceModel.h>
#import <AJLibrary/AJAlertsCalendarModel.h>
#import <AJLibrary/AJAlertsListModel.h>
#import <AJLibrary/AJCloudStorageModel.h>
#import <AJLibrary/AJAlarmListModel.h>
#import <AJLibrary/AJCloudStorageDeleteModel.h>
#import <AJLibrary/AJShare.h>
#import <AJLibrary/AJShareSendReceiverModel.h>
#import <AJLibrary/AJCocoaSecurity.h>
#import <AJLibrary/AJCloud.h>
#import <AJLibrary/AJCloudStorageModel.h>
#import <AJLibrary/AJTimezoneModel.h>
#import <AJLibrary/AJAccount.h>
#import <AJLibrary/AJAccountModel.h>
#import <AJLibrary/AJEmailCheckModel.h>
#import <AJLibrary/BleResponseModel.h>
#import <AJLibrary/BleCmdInfoModel.h>
#import <AJLibrary/BleTaskSender.h>
#import <AJLibrary/BluetoothManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface AJLib : NSObject

/**
*    单例
*/
+ (instancetype)shared;


/**
 *    核心库必须调用的方法，通过SDK发布方提供的供应商码正常完成初始化
 *
 *    @param     vendorCode          供应商授权码
 */
+ (void)asyncInit:(NSString *)vendorCode;

@end

NS_ASSUME_NONNULL_END
