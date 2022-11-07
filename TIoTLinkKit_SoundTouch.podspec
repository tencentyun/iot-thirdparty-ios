Pod::Spec.new do |s|
  s.name             = 'TIoTLinkKit_SoundTouch'
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

#  s.source_files          = 'Source/SoundTouch-iOS/Classes/**/*'
#  s.vendored_libraries    = 'Source/SoundTouch-iOS/*.a'
  s.vendored_frameworks   = 'Source/SoundTouch-iOS/SoundTouchiOS.framework'
#  s.frameworks            = "NetworkExtension", "CoreGraphics", "SystemConfiguration", "Foundation", "UIKit"
#  s.libraries             = 'c++', 'sqlite3', 'z'
    
    s.user_target_xcconfig = {
        'GENERATE_INFOPLIST_FILE' => 'YES',
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }

    s.pod_target_xcconfig = {
        'GENERATE_INFOPLIST_FILE' => 'YES',
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }
end
