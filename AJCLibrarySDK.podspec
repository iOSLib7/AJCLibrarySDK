#
#  Be sure to run `pod spec lint AJCLibrarySDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "AJCLibrarySDK"
  s.version      = "1.2.38"
  s.summary      = "A short description of AJLibrary."
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC
                       
  s.static_framework = true
  s.homepage     = "https://github.com/iOSLib7/AJCLibrarySDK"
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Talaric' => 'alaric.tmz@gmail.com' }
  s.source           = { :git => 'https://github.com/iOSLib7/AJCLibrarySDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '13.0'
  s.swift_versions = ['5.0']
  s.default_subspec     = 'Core'
s.platform     = :ios, '13.0'

 s.subspec 'Core' do |ss|
  
  ss.vendored_frameworks = "libs/*.{framework}"
  ss.resources           = 'AJBundle.bundle'
  ss.preserve_paths      = 'AJLibrary.framework/*', 'AJBundle.bundle'

  ss.frameworks   = 'OpenGLES','Foundation','SystemConfiguration','OpenAL','Security','MediaPlayer','AVFoundation','CoreVideo','CoreAudio','CoreMedia','VideoToolbox','AudioToolbox','AdSupport','NetworkExtension','GLKit'
  
  ss.libraries = "c++.1", "iconv", "z", "bz2.1.0"

  ss.dependency 'Alamofire', '5.9.1'
  #ss.dependency 'Firebase/Crashlytics'
  #ss.dependency 'Firebase/Core'
  #ss.dependency 'Firebase/Analytics'
  ss.dependency 'MBProgressHUD'
  ss.dependency 'SnapKit', '~> 5.7.1'
  ss.dependency 'CocoaAsyncSocket', '7.6.5'
  ss.dependency 'UICKeyChainStore', '>= 2.1.0', '< 3.0.0'
  ss.dependency 'MJRefresh'
  ss.dependency 'Material', '~> 3.1.8'
  ss.dependency 'lottie-ios','2.5.0'
  ss.dependency 'SDWebImage', "~> 5.11.0"
  ss.dependency 'AFNetworking', "~> 4.0.1"
  ss.dependency 'Sodium', '0.9.1'
  ss.dependency 'AliyunOSSiOS'
  ss.dependency 'Masonry'
  ss.dependency 'SDVersion'
  ss.dependency 'SocketRocket'
  ss.dependency 'XCGLogger', '~> 7.0.1'
  ss.dependency 'ZipArchive'
  ss.dependency 'LSTCategory'
  ss.dependency 'CHIPageControl'
  ss.dependency 'ZKCycleScrollView'
  ss.dependency 'MobileVLCKit', "~> 3.6.0"
  ss.dependency 'BabyBluetooth'
  ss.dependency 'ffmpeg-kit-ios-full-gpl-ajc'
  ss.dependency 'QCloudCOSXML', '~> 6.4.4'
  ss.dependency 'Qiniu'

  
 end


end

