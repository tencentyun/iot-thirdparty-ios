Pod::Spec.new do |s|
  s.name             = 'TIoTLinkThirdPartyKit'
  s.version          = ENV['LIB_VERSION'] || '1.0.0'
  s.summary          = '该仓库为方便个人仓库构建使用，如有其他需求还请从官网下载原SDK'

  s.description      = <<-DESC
在CI构建中，有些SDK没有提供供方便pod集成使用，在此仓库提供个聚合SDK以便更好的支持CI。
                       DESC
                       
  s.homepage         = 'https://github.com/tencentyun/iot-thirdparty-ios'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'tonychanchen@gmail.com' => 'tonychanchen@gmail.com' }
  s.source           = { :git => 'https://github.com/tencentyun/iot-thirdparty-ios.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'     
#  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-all_load' }
#  s.static_framework = true
  s.default_subspec = 'Default'
  
  s.subspec 'Default' do |ss|
    ss.source_files          = 'Source/TIoTLinkThirdPartyKit.h'
  end
     
  s.subspec 'TPNS-iOS' do |ss|
    ss.source_files          = 'Source/TPNS-iOS/Classes/**/*'
    ss.vendored_libraries    = 'Source/TPNS-iOS/libXG-SDK-Cloud.a', 'Source/TPNS-iOS/libxgidfa.a', 'Source/TPNS-iOS/libXGExtension.a'
    ss.vendored_frameworks   = 'Source/TPNS-iOS/XGMTACloud.framework'
    ss.frameworks            = "CFNetwork", "SystemConfiguration", "CoreTelephony", "CoreGraphics", "Foundation", "UserNotifications", "CoreData"
    ss.libraries             = "z", "sqlite3"
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end

  s.subspec 'WechatOpenSDK_NoPay' do |ss|
    ss.source_files          = 'Source/WechatOpenSDK_NoPay/Classes/**/*'
    ss.vendored_libraries    = 'Source/WechatOpenSDK_NoPay/libWeChatSDK.a'
    ss.frameworks            = "Security", "CoreGraphics", "WebKit", "SystemConfiguration", "CoreTelephony", "Foundation", "UIKit"
    ss.libraries             = 'c++', 'sqlite3', 'z'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
  s.subspec 'XP2P-iOS' do |ss|
    ss.source_files          = 'Source/XP2P-iOS/Classes/**/*'
    ss.vendored_libraries    = 'Source/XP2P-iOS/*.a'
    ss.frameworks            = "NetworkExtension", "CoreGraphics", "SystemConfiguration", "Foundation", "UIKit"
    ss.libraries             = 'c++', 'sqlite3', 'z'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
  s.subspec 'Faac-iOS' do |ss|
    ss.source_files          = 'Source/Faac-iOS/Classes/**/*'
    ss.vendored_libraries    = 'Source/Faac-iOS/*.a'
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
  s.subspec 'IJKPlayer-iOS' do |ss|
    ss.vendored_libraries    = 'Source/IJKPlayer-iOS/libcrypto.a', 'Source/IJKPlayer-iOS/libssl.a'
    ss.vendored_frameworks   = 'Source/IJKPlayer-iOS/IJKMediaFramework.framework'
    ss.frameworks  = "AudioToolbox", "AVFoundation", "CoreGraphics", "CoreMedia", "CoreVideo", "MobileCoreServices", "OpenGLES", "QuartzCore", "VideoToolbox", "Foundation", "UIKit", "MediaPlayer"
    ss.libraries   = "bz2", "z", "stdc++"
    ss.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  end
  
end
