//
//  QHLiveTypeDefines.h
//  QHLiveSDK
//
//  Created by linyongbin on 2020/5/8.
//  Copyright © 2020 linyongbin. All rights reserved.
//

#ifndef QHLiveTypeDefines_h
#define QHLiveTypeDefines_h

typedef enum : NSUInteger {
    ///主播端直播
    QHLiveRoomTypeAnchor = 1,
    ///观众观看直播
    QHLiveRoomTypeAudience = 2,
    ///观众观看回放
    QHLiveRoomTypePlayback = 3,
} QHLiveRoomType;

typedef enum : NSUInteger {
    QHLiveRoomMiddleLeftPlugIn = 1,
    QHLiveRoomMiddleRightPlugIn = 2,
    QHLiveRoomBottomPlugIn = 3,
} QHLiveRoomPlugInType;


#endif /* QHLiveTypeDefines_h */
