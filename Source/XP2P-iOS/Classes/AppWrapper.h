#ifndef __APPWRAPPER_H_
#define __APPWRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_SIZE_OF_PARAMS 3000

static const char * VIDEOSDKVERSION = "2.3.x+git.12c8dce1";

typedef enum
{
    XP2PTypeClose       = 1000,  //数据传输完成
    XP2PTypeLog         = 1001,  //日志输出
    XP2PTypeCmd         = 1002,  // command json
    XP2PTypeDisconnect  = 1003,  // p2p链路断开
    XP2PTypeDetectReady = 1004,  // p2p链路初始化成功
    XP2PTypeDetectError = 1005,  // p2p链路初始化失败
    XP2PTypeSaveFileOn  = 8000,  //获取保存音视频流开关状态
    XP2PTypeSaveFileUrl = 8001   //获取音视频流保存路径
} XP2PType;

typedef enum
{
    XP2PVoiceServiceClose  = 2000,  //语音对讲服务关闭
    XP2PStreamServiceClose = 2001   //音视频流接收服务关闭
} XP2PCloseSubType;

typedef enum
{
    XP2P_ERR_NONE         = 0,          //成功
    XP2P_ERR_INIT_PRM     = -1000,      //入参为空
    XP2P_ERR_GET_XP2PINFO = -1001,      // SDK内部请求xp2p info失败
    XP2P_ERR_PROXY_INIT   = -1002,      //本地p2p代理初始化失败
    XP2P_ERR_UNINIT       = -1003,      //数据接收/发送服务未初始化
    XP2P_ERR_ENCRYPT      = -1004,      //数据加密失败
    XP2P_ERR_TIMEOUT      = -1005,      //请求超时
    XP2P_ERR_REQUEST_FAIL = -1006,      //请求错误
    XP2P_ERR_VERSION      = -1007,      //设备版本过低，请升级设备固件
    XP2P_ERR_APPLICATION  = -1008,      // application初始化失败
    XP2P_ERR_REQUEST      = -1009,      // request初始化失败
    XP2P_ERR_DETECT_NOTREADY  = -1010,  // p2p探测未完成
    XP2P_ERR_P2P_ININED       = -1011,  //当前id对应的p2p已完成初始化
    XP2P_ERR_P2P_UNININ       = -1012,  //当前id对应的p2p未初始化
    XP2P_ERR_NEW_MEMERY       = -1013,  //内存申请失败
    XP2P_ERR_XP2PINFO_RULE    = -1014,  //获取到的xp2p info格式错误
    XP2P_ERR_XP2PINFO_DECRYPT = -1015,  //获取到的xp2p info解码失败
    XP2P_ERR_PROXY_LISTEN     = -1016,  //本地代理监听端口失败
    XP2P_ERR_CLOUD_EMPTY      = -1017,  //云端返回空数据
    XP2P_ERR_JSON_PARSE       = -1018,  // json解析失败
    XP2P_ERR_SERVICE_NOTRUN = -1019,  //当前id对应的服务(语音、直播等服务)没有在运行
    XP2P_ERR_CLIENT_NULL = -1020      //从map中取出的client为空
} XP2PErrCode;

typedef const char *(*msg_handle_t)(const char *id, XP2PType type, const char *msg);
typedef void (*av_recv_handle_t)(const char *id, uint8_t *recv_buf, size_t recv_len);

/**
 * @brief 设置回调函数
 *
 * @param recv_handle: 音视频数据回调
 * @param msg_handle: 控制类消息回调
 * @return 无返回值
 */
void setUserCallbackToXp2p(av_recv_handle_t recv_handle, msg_handle_t msg_handle);

/**
 * @brief 发送信令消息给camera设备并等待回复，同步阻塞方式
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param command:
 * 可以为任意格式字符或二进制数据，长度由cmd_len提供，建议在16KB以内，否则会影响实时性
 * @param cmd_len: command长度
 * @param recv_buf:
 * 用于存放camera回复的数据，内存由接口内部申请外部释放，实际数据长度根据recv_len获取
 * @param recv_len: camera回复的数据长度
 * @param timeout_us: 命令超时时间，单位为微秒，值为0时采用默认超时(7500ms左右)
 * @return 0 为成功
 */
int postCommandRequestSync(const char *id, const unsigned char *command, size_t cmd_len,
                           unsigned char **recv_buf, size_t *recv_len, uint64_t timeout_us);

/**
 * @brief 发送信令消息给camera设备，camera回复的数据由注册的回调函数返回，异步非阻塞方式
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param command:
 * 可以为任意格式字符或二进制数据，长度由cmd_len提供，建议在16KB以内，否则会影响实时性
 * @param cmd_len: command长度
 * @return 0 为成功
 */
int postCommandRequestWithAsync(const char *id, const unsigned char *command, size_t cmd_len);

/**
 * @brief 向camera设备请求媒体流，异步回调方式
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param params: 直播(`action=live`)或回放(`action=playback`)参数
 * @param crypto: 是否开启传输层加密，如果关闭(crypto=false)，则建议用户在应用层加密，否则有安全风险
 * @return 请求句柄
 */
void *startAvRecvService(const char *id, const char *params, bool crypto);

/**
 * @brief 关闭媒体流传输
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param req: 接口`startAvRecvService`的返回值，当前版本可传入null
 * @return 0 为成功
 */
int stopAvRecvService(const char *id, void *req);

/**
 * @brief 初始化xp2p服务
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param product_id: 产品ID
 * @param device_name: 设备名称
 * @return 0 为成功
 */
int startService(const char *id, const char *product_id, const char *device_name);

/**
 * 延迟设置xp2pinfo,节省start时间
 */
int setDeviceXp2pInfo(const char *id, const char *xp2p_info);
/**
 * @brief 获取本地代理url
 *
 * @param id: 目标camera在app端的唯一标识符
 * @return 本地代理url
 */
const char *delegateHttpFlv(const char *id);

/**
 * @brief 启动向camera设备发送语音或自定义数据服务，异步非阻塞方式
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param params: 请求参数采用 key1=value&key2=value2
 * 格式，key不允许以下划线_开头，且key和value中间不能包含&/+=特殊字符
 * @param crypto: 是否开启传输层加密，如果关闭(crypto=false)，则建议用户在应用层加密，否则有安全风险
 * @return 请求句柄
 */
void *runSendService(const char *id, const char *params, bool crypto);

/**
 * @brief 关闭语音发送传输
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param req: 接口`runSendService`的返回值，当前版本可传入null
 * @return 请求句柄
 */
int stopSendService(const char *id, void *req);

/**
 * @brief 设置云api信息，若不用sdk获取xp2p信息，该接口可不用设置
 *
 * @param sec_id: 云API secrct_id
 * @param sec_key: 云API secrct_key
 * @return 0 为成功
 */
int setQcloudApiCred(const char *sec_id, const char *sec_key);

/**
 * @brief 向camera设备发送语音或自定义数据
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param data: 要发送的数据内容
 * @param len: 要发送的数据长度
 * @return 0 为成功
 */
int dataSend(const char *id, uint8_t *data, size_t len);

/**
 * @brief 停止xp2p服务
 *
 * @param id: 目标camera在app端的唯一标识符
 * @return 0 为成功
 */
void stopService(const char *id);

/*================================废弃接口=======================================*/
/**
 * @brief 发送信令消息给camera设备并等待回复，同步阻塞方式
 *
 * @param id: 目标camera在app端的唯一标识符
 * @param command: 字符格式命令
 * @param buf: 用于存放camera回复的数据，内存由接口内部申请外部释放，实际数据长度根据len获取
 * @param len: camera回复的数据长度
 * @param timeout_us: 命令超时时间，单位为微秒，值为0时采用默认超时(7500ms左右)
 * @return 0 为成功
 */
int getCommandRequestWithSync(const char *id, const char *command, char **buf, size_t *len,
                              uint64_t timeout_us);

/**
 * @brief 发送信令消息给camera设备，camera回复的数据由注册的回调函数返回，异步非阻塞方式
 *
 * @param id:目标camera在app端的唯一标识符
 * @param command:字符格式命令
 * @return 0 为成功
 */
int getCommandRequestWithAsync(const char *id, const char *command);


/**
 * @brief 调试接口，便于通过播放器请求httpflv时，保存拉取的原始流数据就行分析
 * @param id:目标camera在app端的唯一标识符
 */
void startRecordPlayerStream(const char *id);

#ifdef __cplusplus
}
#endif

#endif