
## WechatOpenSDK_NoPay(1.8.7.1)

* WechatOpenSDK_NoPay官方发的pod版本太低了，官方不建议使用。
* 来源 ：https://developers.weixin.qq.com/community/develop/doc/0000e6f99cc890999e79ca21951800
        https://developers.weixin.qq.com/doc/oplatform/Downloads/iOS_Resource.html
* 代码无修改


## TPNS-iOS(1.2.5.4)

* TPNS, 官方提供的地址是oa地址，需要oa账号验证，pod集成不好交互输入账号
* 来源： 官网下载地址 https://cloud.tencent.com/document/product/548/36663
* 代码无修改


## IJKPlayer-iOS(36912acc)

* 添加了追帧策略
* 来源：https://git.code.oa.com/zhilizhao/ijkplayer/commits/lowlatency
* 构建说明：参考仓库readme指引文档, 修改 compile-ffmpeg.sh 中 FF_ALL_ARCHS_IOS8_SDK="arm64" 只保留arm64

## XP2P-iOS

* 来源 tencentyun/iot-p2p
* 构建说明：参考github action


## Faac-iOS

* 来源：https://github.com/hardman/AWLive/tree/master/clibs/3th-party
* 用于 pcm 软编码为 aac ，实现音频对讲