//
//  GVoiceSEiOS.h
//  GVoiceSEiOS
//
//  Created by Eagle Chan on 2024/1/23.
//

#import <Foundation/Foundation.h>

//! Project version number for GVoiceSEiOS.
FOUNDATION_EXPORT double GVoiceSEiOSVersionNumber;

//! Project version string for GVoiceSEiOS.
FOUNDATION_EXPORT const unsigned char GVoiceSEiOSVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GVoiceSEiOS/PublicHeader.h>


@interface GVoiceSE : NSObject
//model_path 传入模型文件路径
+ (int)voice_handle_open:(const char*)model_path; //返回-1初始化错误，0成功
+ (void)voice_handle_process:(char *)pcmlocal ref:(char *)pcmref;
@end
