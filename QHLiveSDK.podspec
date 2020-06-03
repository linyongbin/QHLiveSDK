#
# Be sure to run `pod lib lint QHLiveSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'QHLiveSDK'
  s.version          = '1.0.0'
  s.summary          = '直播 QHLiveSDK.'
  s.homepage     = "https://github.com/linyongbin/QHLiveSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  
  s.author  = { "林勇彬" => "447000693@qq.com" }
  s.platform     = :ios, "9.0"
  
  s.source       = { :git => "https://github.com/linyongbin/QHLiveSDK.git", :tag => s.version }
  
  s.resource  = "QHLiveSDK/Classes/*.bundle"
  
  s.vendored_framework = 'QHLiveSDK/Classes/*.framework'

  s.requires_arc = true
  
  #依赖包
  s.dependency 'AFNetworking', '~> 4.0'
  s.dependency 'Masonry'
  s.dependency 'YYModel'
  s.dependency 'MJRefresh'
  s.dependency 'SDWebImage'
  s.dependency 'MBProgressHUD'
  #七牛播放器SDK
  s.dependency 'PLPlayerKit'
  #七牛直播SDK
  s.dependency 'PLMediaStreamingKit', '~> 2.3.5'
  #融云
  s.dependency 'RongCloudIM/IMLib', '~> 2.10.4'
  #微信
  s.dependency 'WechatOpenSDK'
  #相芯科技美颜
  s.dependency 'Nama-lite'
end
