//
//  QHLiveManager.h
//  QHLiveDemo
//
//  Created by 林勇彬 on 2020/3/9.
//  Copyright © 2020 林勇彬. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QHLivePlugInManager.h"
#import "QHLiveTypeDefines.h"

NS_ASSUME_NONNULL_BEGIN
@class QHLiveManager;

@protocol QHLiveManagerDelegate <NSObject>

/// 进入直播间前调用
/// @param manager manager
/// @param role 身份
- (void)liveManager:(QHLiveManager *)manager onCreateLiveRoomWithRole:(QHLiveRoomType)role;

@end

@interface QHLiveManager : NSObject

/// 单例
+ (QHLiveManager *)sharedManager;

@property (nonatomic, weak) id<QHLiveManagerDelegate> delegate;

/// 初始化青火直播SDK
/// @param key key
/// @param secret secret
- (void)initWithKey:(NSString *)key masterSecret:(NSString *)secret;

/* 向微信终端程序注册第三方应用。
 *
 * @param appid 微信开发者ID
 * @param universalLink 微信开发者Universal Link
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)registerApp:(NSString *)appid universalLink:(NSString *)universalLink;

/// 进入青火直播列表
/// @param currentController 当前控制器
- (void)pushQHLiveListWithCurrentController:(UIViewController *)currentController;

/// 进入青火直播间
/// @param currentController 当前控制器
/// @param liveId 直播ID
- (void)pushQHLiveRoomWithCurrentController:(UIViewController *)currentController liveId:(NSString *)liveId;

/// 创建直播间
/// @param title 直播标题       必须传
/// @param liveImage 直播图片   默认为空
/// @param startTime 开始时间  默认为“当前时间”
/// @param forecastTime 预告时间 默认为空
/// @param livePassword 房间密码 默认为空
/// @param currentController 当前控制器
- (void)createQHLiveRoomWithTitle:(NSString *)title liveImage:(NSString *)liveImage startTime:(NSString *)startTime forecastTime:(NSString *)forecastTime livePassword:(NSString *)livePassword WithCurrentController:(UIViewController *)currentController;

- (void)loginWithUserAccount:(NSString *)account pwd:(NSString *)pwd;

/// 插件管理器
@property (nonatomic, strong) QHLivePlugInManager *plugInManager;

/// 是否显示带货按钮
@property (nonatomic, assign) BOOL isShowProduct;
/// 是否显示分享按钮
@property (nonatomic, assign) BOOL isShowShare;
/// 是否显示活动按钮
@property (nonatomic, assign) BOOL isShowActivity;

#pragma mark - 获取青火直播数据
/// 获取直播列表
/// @param title 搜索时使用，不传默认全部返回
/// @param memberId 查询自己的直播列表时，传本身的memberId，不传返回全部
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 返回直播列表<QHLiveListModel>
- (void)getQHLiveListWithTitle:(NSString *)title memberId:(NSString *)memberId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 获取直播推荐列表
/// @param block 返回直播推荐列表<QHLiveListRecommendModel>
- (void)getQHLiveRecommendWithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 获取直播详情
/// @param liveId 直播ID
/// @param block 返回直播详情<QHLiveListModel>
- (void)getQHLiveDetailWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 直播间相关
/// 创建直播间
/// @param title 直播标题       必须传
/// @param liveImage 直播图片   默认为空
/// @param startTime 开始时间  默认为“当前时间”
/// @param forecastTime 预告时间 默认为空
/// @param livePassword 房间密码 默认为空
/// @param block 返回直播详情<QHLiveListModel>
- (void)createQHLiveRoomWithTitle:(NSString *)title liveImage:(NSString *)liveImage startTime:(NSString *)startTime forecastTime:(NSString *)forecastTime livePassword:(NSString *)livePassword WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 开始直播
/// @param liveId 直播ID
- (void)startQHLiveWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;
/// 结束直播
/// @param liveId 直播ID
- (void)stopQHLiveWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 获取主播信息
/// @param memberId 主播ID
/// @param block 返回主播信息<QHLiveAnchorInfoModel>
- (void)getAnchorInfoWithMemberId:(NSString *)memberId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 关注主播
/// @param anchorMemberId 主播ID
- (void)followQHLiveAnchorWithAnchorMemberId:(NSString *)anchorMemberId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 取消关注主播
/// @param anchorMemberId 主播ID
- (void)cancelFollowQHLiveAnchorWithAnchorMemberId:(NSString *)anchorMemberId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 点赞直播
/// @param liveId 直播ID
/// @param block 回调结果
- (void)likeQHLiveWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;



/// 直播统计接口
/// @param liveId 直播ID
/// @param block 回到结果
- (void)getQHLiveCountWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;


/// 删除直播
/// @param liveId 直播ID
/// @param block 回调结果
- (void)deleteQHLiveBroadcastWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;


/// 获取直播预告时间
/// @param liveId 直播ID
/// @param block 回调结果
- (void)getQHLiveStartTimeWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

/// 更新直播间上下架
/// @param liveId 直播ID
/// @param onlineStatus 上下架状态<1：上架，2：下架>
/// @param block 回调结果
- (void)updateQHLiveBroadcastWithLiveId:(NSString *)liveId onlineStatus:(NSNumber *)onlineStatus WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

/// 清除直播间密码
/// @param liveId 直播ID
/// @param block 回调结果
- (void)clearQHLivePasswordWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

/// 直播定时播报
/// @param liveId 直播ID
/// @param block 回调结果
- (void)sendOutLineWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

#pragma mark - 直播观众相关

/// 观众进入直播间
/// @param liveId 直播ID
/// @param block 回调结果
- (void)joinQHLiveWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 观众离开直播间
/// @param liveId 直播ID
/// @param block 回调结果
- (void)outQHLiveWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 青火获取直播观众
/// @param liveId 直播ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getLiveAudienceListWithLiveId:(NSString *)liveId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 直播产品相关

/// 添加直播推荐产品
/// @param liveId 直播ID
/// @param skuId 产品skuId
/// @param block 回调结果
- (void)addLiveSkuRelationWithLiveId:(NSString *)liveId skuId:(NSString *)skuId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 删除直播推荐产品
/// @param liveId 直播ID
/// @param skuId 产品skuId
/// @param block 回调结果
- (void)removeLiveSkuRelationWithLiveId:(NSString *)liveId skuId:(NSString *)skuId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 获取直播间推荐产品列表
/// @param liveId 直播ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 返回直播产品列表<QHLiveProductSkuModel>
- (void)getQHLiveSkusWithLiveId:(NSString *)liveId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 分享和商品点击次数接口
/// @param quantity 点击次数
/// @param skuId 产品skuId
/// @param block 回调结果
- (void)clickShareOrGoodsWithQuantity:(NSString *)quantity skuId:(NSString *)skuId WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

#pragma mark - 刷新拉、推流地址

/// 刷新推流地址
/// @param liveId 直播ID
/// @param block 回调结果
- (void)refreshPushUrlWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 刷新拉流地址
/// @param liveId 直播ID
/// @param block 回调结果
- (void)refreshPullUrlWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 禁言相关

/// 查看当前禁言状态
/// @param liveId 直播ID
/// @param block 回调结果
- (void)getBanningMessageStatusWithLiveId:(NSString *)liveId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 禁止用户发言
/// @param liveId 直播ID
/// @param forbiddenMemberId 被禁言用户的ID
/// @param block 回调结果
- (void)banningMessageWithLiveId:(NSString *)liveId forbiddenMemberId:(NSString *)forbiddenMemberId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 解除用户发言
/// @param liveId 直播ID
/// @param forbiddenMemberId 被解除的用户ID
/// @param block 回调结果
- (void)unbanningMessageWithLiveId:(NSString *)liveId forbiddenMemberId:(NSString *)forbiddenMemberId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 禁言用户列表
/// @param liveId 直播ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getBanningMessageListWithLiveId:(NSString *)liveId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 优惠券相关

/// 获取直播优惠券列表
/// @param block 回调结果
- (void)getAllLiveCouponWithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 获取直播发放优惠券记录
/// @param liveId 直播ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getLiveCouponListWithLiveId:(NSString *)liveId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

/// 获取直播优惠券领取详情记录
/// @param liveId 直播ID
/// @param sendId 发放优惠券ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getLiveCouponDetailListWithLiveId:(NSString *)liveId sendId:(NSString *)sendId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 直播发放优惠券
/// @param liveId 直播ID
/// @param sendNum 发放数量
/// @param couponId 优惠券ID
/// @param block 回调结果
- (void)sendLiveCouponWithLiveId:(NSString *)liveId sendNum:(NSNumber *)sendNum couponId:(NSString *)couponId  WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 获取指定直播优惠券详情
/// @param couponId 优惠券ID
/// @param block 回调结果
- (void)getLiveCouponWithCouponId:(NSString *)couponId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 领取优惠券
/// @param liveId 直播ID
/// @param sendId 发放优惠券ID
/// @param block 回调结果
- (void)receiveLiveCouponWithLiveId:(NSString *)liveId sendId:(NSString *)sendId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 红包相关

/// 主播发放红包
/// @param liveId 直播ID
/// @param sendNum 红包个数
/// @param sendMoney 红包总金额
/// @param password 用户密码
/// @param block 回调结果
- (void)sendRedEnvelopesWithLiveId:(NSString *)liveId sendNum:(NSNumber *)sendNum sendMoney:(NSNumber *)sendMoney password:(NSString *)password WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 领取直播间红包
/// @param liveId 直播ID
/// @param redEnvelopesId 红包ID
/// @param block 回调结果
- (void)receiveRedEnvelopesWithLiveId:(NSString *)liveId redEnvelopesId:(NSString *)redEnvelopesId WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 红包记录
/// @param liveId 直播ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getLiveRedEnvelopesListWithLiveId:(NSString *)liveId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;


/// 红包领取明细
/// @param liveId 直播ID
/// @param redEnvelopesId 红包ID
/// @param pageOffset 页码   默认 1
/// @param pageSize 每页条数大小 默认 15
/// @param block 回调结果
- (void)getLiveRedEnvelopesDetailListWithLiveId:(NSString *)liveId redEnvelopesId:(NSString *)redEnvelopesId pageOffset:(NSNumber *)pageOffset pageSize:(NSNumber *)pageSize WithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;

#pragma mark - 直播间举报

/// 获取举报标题列表
/// @param block 回调结果
- (void)getAllReportTitleWithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;

/// 举报直播间
/// @param liveId 直播ID
/// @param reportTitleListIds 举报类型ID
/// @param reportImageUrls 图片数组
/// @param reportReasonDesc 举报内容
/// @param block 回调结果
- (void)reportRecordWithLiveId:(NSString *)liveId reportTitleListIds:(NSString *)reportTitleListIds reportImageUrls:(NSArray *)reportImageUrls reportReasonDesc:(NSString *)reportReasonDesc WithBlock:(void (^)(id  _Nullable responseObject, NSError *error))block;
#pragma mark - 消息token

/// 获取青火直播消息token
/// @param block 回调结果
- (void)getMessageTokenWithBlock:(void (^)(id  _Nullable responseObject, NSError * error))block;
@end

NS_ASSUME_NONNULL_END
