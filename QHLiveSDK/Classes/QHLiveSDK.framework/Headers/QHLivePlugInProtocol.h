//
//  QHLivePlugInProtocol.h
//  QHLiveSDK
//
//  Created by linyongbin on 2020/5/13.
//  Copyright © 2020 linyongbin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHLivePlugInConfigModel.h"
NS_ASSUME_NONNULL_BEGIN

@protocol QHLivePlugInProtocol <NSObject>

- (instancetype)initWithConfig:(QHLivePlugInConfigModel *)config;

- (QHLivePlugInConfigModel *)render;
@end

NS_ASSUME_NONNULL_END
