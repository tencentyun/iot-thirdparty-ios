Pod::Spec.new do |s|
  s.name             = 'IoTVideoCloud'
  s.version          = ENV['LIB_VERSION'] || '1.0.1'
  s.summary          = '腾讯连连Video SDK是腾讯云物联网平台提供，应用开发厂商可通过该 SDK 快速搭建起 OEM 版本 APP，进行物联网音视频业务开发'

  s.description      = <<-DESC
在腾讯云物联网开发平台中，APP通过接入Video SDK来实现与智能IPC设备的连接，和通过物联网平台对智能IPC设备进行管理。
                       DESC

  # 修改为GitHub仓库地址
  s.homepage         = 'https://github.com/tencentyun/iot-thirdparty-ios'
  s.license          = { :type => 'Apache-2.0', :file => 'LICENSE' }
  s.author           = { 'Tencent IoT Team' => 'iot-support@tencent.com' }

  # 关键修改：使用GitHub仓库中的预编译framework
  # 注意：podspec文件应该放在 Specs/IoTVideoCloudKit/1.0.0/ 目录下
  s.source           = {
    :http => "https://github.com/tencentyun/iot-thirdparty-ios/raw/master/Source/IoTVideoCloud-iOS/IoTVideoCloudKit-#{s.version}.zip",
    :type => 'zip'
  }

  s.ios.deployment_target = '9.0'
  s.static_framework = true
  s.requires_arc = true

  # 预编译框架配置 - 使用IoTVideoCloud.framework
  s.vendored_frameworks = 'IoTVideoCloud.framework'
  # s.preserve_paths = 'IoTVideoCloud.framework'
  # s.source_files = 'IoTVideoCloud.framework/Headers/*.h'
  # s.public_header_files = 'IoTVideoCloud.framework/Headers/*.h'
  s.user_target_xcconfig = { 'HEADER_SEARCH_PATHS' => '"IoTVideoCloud.framework/Headers"' }
#  s.user_target_xcconfig = { 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/IoTVideoCloud/IoTVideoCloud.framework/Headers"' }
  
  # 关键配置：添加module_map以支持双引号引入头文件
  # s.module_map = 'IoTVideoCloud.framework/Modules/module.modulemap'

  # 依赖配置
  s.dependency 'CocoaAsyncSocket', '7.6.5'
  s.dependency 'TXLiteAVSDK_TRTC', '11.1.14143'
  s.dependency 'YYModel'
  s.dependency 'CocoaLumberjack'

  # 系统框架依赖
  # s.frameworks = 'Foundation', 'UIKit', 'AVFoundation', 'CoreTelephony', 'SystemConfiguration'
  # s.libraries = 'c++', 'sqlite3', 'z'

  # 添加资源文件（如果有）
  # s.resource_bundles = {
  #   'IoTVideoCloud' => ['Resources/*.png', 'Resources/*.xib']
  # }
end
