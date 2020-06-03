//
//  QHLivePlugInConfigModel.h
//  QHLiveSDK
//
//  Created by linyongbin on 2020/5/26.
//  Copyright © 2020 linyongbin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface QHLivePlugInConfigModel : NSObject
/// 插件本身
@property (nonatomic, strong) UIView *view;
/// 在容器的位置
@property (nonatomic, assign) NSInteger position;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

/// 插件距容器顶部的距离，且只有注册在QHLiveRoomMiddleLeftPlugIn和QHLiveRoomMiddleRightPlugIn有用
@property (nonatomic, assign) CGFloat topMargin;
/// 插件距容器底部的距离，且只有注册在QHLiveRoomMiddleLeftPlugIn和QHLiveRoomMiddleRightPlugIn，最后一个才有用
@property (nonatomic, assign) CGFloat bottomMargin;
/// 插件距容器底部的距离，且只有注册在QHLiveRoomBottomPlugIn有用
@property (nonatomic, assign) CGFloat leftMargin;
/// 插件距容器底部的距离，且只有注册在QHLiveRoomBottomPlugIn，最后一个才有用
@property (nonatomic, assign) CGFloat rightMargin;
@end

NS_ASSUME_NONNULL_END
