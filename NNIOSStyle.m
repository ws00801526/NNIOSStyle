//  NNIOSStyle.m
//  
//
//  Created by  XMFraker on 2017/12/12
//  Copyright © XMFraker All rights reserved. (https://github.com/ws00801526)
//  @class      NNIOSStyle
//  @version    v0.0.1
//  @discussion 简要介绍了几种定义,声明的代码样式


#import "NNIOSStyle.h"

NSString * const kNNIOSStyleChangedNotification = @"com.xxx.xxx.kNNIOSStyleChangedNotification";

/** 定义全局共享变量采用 g + 变量名(StyleGuideMode) */
static int gStyleGuideMode;

@implementation NNIOSStyle
@synthesize name = _name;
@dynamic age;

#pragma mark - Life Cycle

- (instancetype)initWithName:(NSString *)name {
    
    if (self = [super init]) {
        _name = [name copy];
    }
    return self;
}

#pragma mark - Getter

- (int)age {
    return _age;
}

@end
