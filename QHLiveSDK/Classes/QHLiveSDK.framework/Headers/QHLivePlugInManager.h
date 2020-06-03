//
//  QHLivePlugInManager.h
//  QHLiveSDK
//
//  Created by linyongbin on 2020/5/13.
//  Copyright © 2020 linyongbin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "QHLivePlugInProtocol.h"
#import "QHLiveTypeDefines.h"
NS_ASSUME_NONNULL_BEGIN

@interface QHLivePlugInManager : NSObject

- (void)removeAllPlugIn;

- (void)registerQhLivePlugInWithPositon:(QHLiveRoomPlugInType)position view:(UIView<QHLivePlugInProtocol> *)view;

- (void)renderInView:(UIView *)view positon:(QHLiveRoomPlugInType)position;
@end
NS_ASSUME_NONNULL_END
