//
//  TRAESoundTouch.h
//  TRAESoundTouch
//
//  Created by eagleychen on 2023/2/22.
//

#import <Foundation/Foundation.h>

//! Project version number for TRAESoundTouch.
FOUNDATION_EXPORT double TRAESoundTouchVersionNumber;

//! Project version string for TRAESoundTouch.
FOUNDATION_EXPORT const unsigned char TRAESoundTouchVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TRAESoundTouch/PublicHeader.h>


@interface TRAESoundTouch : NSObject
//1 萝莉 2大叔
+ (int)voice_handle_open:(int)mode channels:(int)channels; //返回-1初始化错误，0成功
+ (void)voice_handle_process:(short *)input output:(short *)output frames:(int)frames;
@end
