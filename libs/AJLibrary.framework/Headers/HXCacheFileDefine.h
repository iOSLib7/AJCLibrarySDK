//
//  HXCacheFileDefine.h
//  HX
//
//  Created by HX on 17/6/28.
//  Copyright © 2017年 HX. All rights reserved.
//

#ifndef HXCacheFileDefine_h
#define HXCacheFileDefine_h


static NSString *const HXCacheFileTitle = @"缓存文件";

static NSString *const HXCacheFileAudioDurationValueChangeNotificationName = @"AudioDurationValueChangeNotificationName";
static NSString *const HXCacheFileAudioStopNotificationName = @"AudioStopNotificationName";

/**
 *  默认显示文件
 *  视频：.avi、.dat、.mkv、.flv、.vob、.mp4、.m4v、.mpg、.mpeg、.mpe、.3pg、.mov、.swf、.wmv、.asf、.asx、.rm、.rmvb
 *  音频：.wav、.aif、.au、.mp3、.ram、.wma、.mmf、.amr、.aac、.flac、.midi、.mp3、.oog、.cd、.asf、.rm、.real、.ape、.vqf
 *  图片：.jpg、.png、.jpeg、.gif、.bmp
 *  文档：.txt、.sh、.doc、.docx、.xls、.xlsx、.pdf、.hlp、.wps、.rtf、.html、@".htm", .iso、.rar、.zip、.exe、.mdf、.ppt、.pptx
 */

/// 视频文件
#define HXCacheFileVideoArray @[@".avi", @".dat", @".mkv", @".flv", @".vob", @".mp4", @".m4v", @".mpg", @".mpeg", @".mpe", @".3pg", @".mov", @".swf", @".wmv", @".asf", @".asx", @".rm", @".rmvb"]
/// 音频文件
#define HXCacheFileAudioArray @[@".wav", @".aif", @".au", @".mp3", @".ram", @".wma", @".mmf", @".amr", @".aac", @".flac", @".midi", @".mp3", @".oog", @".cd", @".asf", @".rm", @".real", @".ape", @".vqf"]
/// 图片文件
#define HXCacheFileImageArray @[@".jpg", @".png", @".jpeg", @".gif", @".bmp"]
/// 文档文件
#define HXCacheFileDocumentArray @[@".txt", @".sh", @".doc", @".docx", @".xls", @".xlsx", @".pdf", @".hlp", @".wps", @".rtf", @".html", @".htm", @".iso", @".rar", @".zip", @".exe", @".mdf", @".ppt", @".pptx"]

/// 不能删除系统文件及文件夹
#define HXCacheFileSystemArray @[@"/tmp", @"/Library/Preferences", @"/Library/Caches/Snapshots", @"/Library/Caches", @"/Library", @"/Documents"]


/// 文件类型
typedef NS_ENUM(NSInteger, HXCacheFileType)
{
    /// 文件类型 0未知
    HXCacheFileTypeUnknow = 0,
    
    /// 文件类型 1视频
    HXCacheFileTypeVideo = 1,
    
    /// 文件类型 2音频
    HXCacheFileTypeAudio = 2,
    
    /// 文件类型 3图片
    HXCacheFileTypeImage = 3,
    
    /// 文件类型 4文档
    HXCacheFileTypeDocument = 4,
};

#endif /* HXCacheFileDefine_h */
