//
//  QHViewController.m
//  QHLiveSDK
//
//  Created by 林 勇彬 on 06/03/2020.
//  Copyright (c) 2020 林 勇彬. All rights reserved.
//

#import "QHViewController.h"
#import <QHLiveSDK/QHLiveSDK.h>
@interface QHViewController ()<UITableViewDelegate,UITableViewDataSource,QHLiveManagerDelegate>
@property (nonatomic,strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataList;
@end

@implementation QHViewController

- (UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        _tableView.backgroundColor = [UIColor whiteColor];
    }
    return _tableView;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.tableView];
    [[QHLiveManager sharedManager] initWithKey:@"18888888888" masterSecret:@"123456"];
    [[QHLiveManager sharedManager] registerApp:@"wx63db6cd11138635b" universalLink:@"https://wx.create-chain.net/"];
    
    [QHLiveManager sharedManager].delegate = self;
    
    self.dataList = @[@[@"17777777777",@"18888888888",@"19999999999"],@[@"直播间列表",@"创建直播",@"观看直播"]];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return self.dataList.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSArray *sectionArray = self.dataList[section];
    return sectionArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 65;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifierH = @"TableViewCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifierH];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifierH];
    }
    NSArray *sectionArray = self.dataList[indexPath.section];
    cell.textLabel.text = sectionArray[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.section == 0) {
        NSArray *sectionArray = self.dataList[indexPath.section];
        [[QHLiveManager sharedManager] loginWithUserAccount:sectionArray[indexPath.row] pwd:@"123456"];
    }else{
        if (indexPath.row == 0) {
            [[QHLiveManager sharedManager] pushQHLiveListWithCurrentController:self];
        }else if(indexPath.row == 1){
            [[QHLiveManager sharedManager] createQHLiveRoomWithTitle:@"直播间测试" liveImage:@"https://goss3.cfp.cn/creative/vcg/800/new/VCG211167562512.jpg?x-oss-process=image/format,jpg/interlace,1" startTime:@"" forecastTime:@"" livePassword:@"" WithCurrentController:self];
        }else if (indexPath.row == 2){
            [[QHLiveManager sharedManager] pushQHLiveRoomWithCurrentController:self liveId:@"bfe89b7f10f44efb839357464a1d433c"];
        }
    }
}

- (void)liveManager:(QHLiveManager *)manager onCreateLiveRoomWithRole:(QHLiveRoomType)role{
    switch (role) {
        case QHLiveRoomTypeAnchor:
        {
            NSLog(@"主播端");
        }
            break;
        case QHLiveRoomTypeAudience:
        {
            NSLog(@"观众观看直播");
        }
            break;
        case QHLiveRoomTypePlayback:
        {
            NSLog(@"观众观看回放");
//            [[QHLiveManager sharedManager].plugInManager registerQhLivePlugInWithPositon:QHLiveRoomBottomPlugIn view:self.button];
        }
            break;
            
        default:
            break;
    }
}

@end
