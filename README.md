# TIoTLinkThirdPartyKit


## 安装

TIoTThridSDK is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'TIoTLinkKit_Faac'
pod 'TIoTLinkKit_IJKPlayer'
pod 'TIoTLinkKit_TPNS'
pod 'TIoTLinkKit_WechatOpenSDK'
pod 'TIoTLinkKit_XP2P'
```

产品线打包方式

```ruby
#faac-v2.2.2
#ijkplayer-v2.2.2
#tpns-v2.2.2
#wechat-v2.2.2
#xp2p-v2.2.2
#xp2p-v2.2.2-beta.1
## License
```


产品线发布

```ruby
pod lib lint --verbose --allow-warnings --use-libraries
        
pod trunk push --verbose --allow-warnings --use-libraries
```