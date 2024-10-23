//
//  AJMediaPlayer.h
//  AJLibrary
//
//  Created by HX on 2022/10/18.
//

#import <UIKit/UIKit.h>


typedef enum {
    AJMediaPlayerVideoRecord=1,
    AJMediaPlayerPrivate
}AJMediaPlayerDecodeType;

typedef enum {
    AJMediaPlayerTalkModeFullDuplex=1,
    AJMediaPlayerTalkModeHalfDuplex
}AJMediaPlayerTalkMode;

@protocol AJMediaPlayerDelegate <NSObject>
@optional
- (void)AJMediaPlayerTimeChange;
- (void)AJMediaPlayerTimeChange:(NSInteger)playTime;
- (void)AJMediaPlayerVideoStartPlay;
- (void)AJMediaPlayerStatusBuffering;
- (void)AJMediaPlayerVideoisNotPlay;
- (void)AJMediaPlayerVLCSPausetatus;
- (void)AJMediaPlayerBatteryRetryAction;
- (void)AJMediaPlayerNetworkChangeRetryAction;
- (void)AJMediaPlayerFullScreenAction:(BOOL)isFullscreen;
- (void)AJMediaPlayerFullScreenActionOrientation:(UIDeviceOrientation)Orientation;
- (void)AJMediaPlayerResolutionChange:(NSInteger)resolutionIndex;
- (void)AJMediaPlayerResolutionDidTap;
- (void)AJMediaPlayerWhitelightCtrl:(NSInteger)CtrlIndex;
- (void)AJMediaPlayerFastforwordRateChange:(float)forwordRate;
- (void)AJMediaPlayerFullscreenSideAction:(NSInteger)actionIndex;
- (void)AJMediaPlayerFullscreenPTZEnd;
- (BOOL)AJMediaPlayerShouldAutoRotated;
- (void)AJMediaPlayerControlViewHide:(BOOL)isHide;
- (void)AJMediaPlayerGotoLive;
- (void)AJMediaPlayerLiveSpeed:(NSInteger)Speed;

@end

typedef void (^snapShotDoneAction)(UIImage *image);
@interface AJMediaPlayer : UIView
@property (weak) id<AJMediaPlayerDelegate>   delegate;
//@property (copy, nonatomic  )snapShotDoneAction snapCallback;
-(instancetype)initWithFrame:(CGRect)frame showView:(UIView *)View deviceId:(NSString *)deviceId;

/**
 *   静音
 */
- (void)mute;
/**
 *   当前是否静音
 */
- (BOOL)isMute;
/**
 *   当前取消静音
 */
- (void)cancelMute;
/**
 *  开始对讲
 */
-(void)startTalk:(NSString *)cameraID;
/**
 *  停止对讲
 */
-(void)stopTalk:(NSString *)cameraID;
/**
 *  是否正在录像
 */
-(BOOL)isVideoRecording;
/**
 *  开始直播录像
 *  @param     filePath                录像文件路径
 */
- (int) startLocalRecordWithPath:(NSString *)filePath;
/**
 *  停止直播录像
 */
- (int) stopLocalRecord;
/**
 *  截图
 *  @param     path                截图路径
 *  @param     completion           uiimage 回调 （路径中也会保存，主要用于截图效果展示）
 */
- (void)takeSnapShot:(NSString *)path completion:(snapShotDoneAction)completion;
/**
 *  停止播放
 */
- (void)stop;
/**
 *  销毁播放器（退出界面时调用）
 */
- (void)dismiss;
/**
 *  播放网络视频
 *  @param     URLString                视频URL
 */
- (void)playWithURL:(NSString *)URLString;
/**
 *  设置视频预览封面
 *  @param     image                封面图片
 */
- (void)showPlaceHolderImage:(UIImage *)image;
/**
 *  截图动画
 *  @param     snapImage                图片
 */
- (void)showSnapAnimation:(UIImage *)snapImage;
/**
 *  设置视频预览封面URL 和 视频URL
 *  @param     imageUrl                封面图片URL
 *  @param     videoUrl                视频URL
 */
- (void)showPlaceHolderImage:(NSString *)imageUrl videoURL:(NSString *)videoUrl;
/**
 *  播放本地视频文件
 *  @param     localPath                本地视频文件路径
 */
- (void)playWithLocalPath:(NSString *)localPath;
/**
 *  开始直播
 *  @param     cameraID                设备ID
 *  @param     qualityNum              分辨率
 */
- (void)playVideoWithCameraId:(NSString *)cameraID qualityNum:(NSString *)qualityNum;
/**
 *  开始播放直播音频
 *  @param     cameraID                设备ID
 */
-(void)playAudioWithCameraId:(NSString *)cameraID;

/**
 *  以下API videoRecordTpye ONLY！！！！
 *
 */
/**
 *  videoRecord模式下 是否可以暂停
 *
 */
- (BOOL)canPause;
/**
 *  videoRecord模式下 暂停
 *
 */
- (void)pause;
/**
 *  videoRecord模式 停止播放
 *
 */
- (void)playstop;
/**
 *  videoRecord模式 有视频输出
 *
 */
- (BOOL)hasVideoOut;
/**
 *  videoRecord模式 是否正在播放
 *
 */
- (BOOL)isPlaying;
/**
 *  videoRecord模式下 开始播放
 *
 */
- (void)play;
/**
 *  videoRecord模式 播放速率
 *
 */
- (void)setRate:(float)rate;


/**
 *  position 播放进度
 *
 *  YES  设置成功
 *  NO   设置失败
 *
 */
-(BOOL)playPosition:(CGFloat)position;

/**
 *  talkMode 通话模式
 *
 *   仅在设备支持全双工的情况下设置
 *
 */
-(void)talkMode:(AJMediaPlayerTalkMode)talkMode;


@end


