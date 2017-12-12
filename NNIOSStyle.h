//  NNIOSStyle.h
//  
//
//  Created by  XMFraker on 2017/12/12
//  Copyright © XMFraker All rights reserved. (https://github.com/ws00801526)
//  @class      NNIOSStyle
//  @version    v0.0.1
//  @discussion 简要介绍了几种定义,声明的代码样式


#import <Foundation/Foundation.h>

/** 定义NNIOSStyleGuide.mode */
typedef NS_ENUM(NSUInteger, NNIOSStyleGuideMode) {
    /** 默认 */
    NNIOSStyleGuideModeDefault = 0,
    /** 红色系 */
    NNIOSStyleGuideModeRed,
    /** 蓝色系 */
    NNIOSStyleGuideModeBlue,
};

/** 定义常量采用 k + 项目前缀(NN) + 常量名(IOSStyleChanged) + 具体标识(Notification) */
FOUNDATION_EXPORT NSString * const kNNIOSStyleChangedNotification;

@interface NNIOSStyle : NSObject {
    @protected
    NSString *_name;
    @private
    int _age;
}

/** style.name */
@property (copy, nonatomic)   NSString *name;
/** style.age [0,130]*/
@property (assign, nonatomic, readonly) int age;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

/** 输出Hello World */
- (void)printHellWorld;

/** 输出Hello World,I am \(name) */
- (void)printHellWorldWithName:(NSString *)name;

/** 输出Hello World, I am \(name), \(age) years old*/
- (void)printHellWorldWithName:(NSString *)name age:(int)age;

/**
 单行无法显示所有参数, 使用换行参数对齐方式

 @param name                name
 @param longlongName        longlongName
 @param longlonglongName    longlonglongName
 */
- (void)printShort:(NSString *)name
      longlongName:(NSString *)longlongName
  longlonglongName:(NSString *)longlonglongName;

@end

@interface NNIOSStyle (NNIOSStyleGuideMode)
@property (assign, nonatomic) NNIOSStyleGuideMode mode;
/** 类别中的方法, 尽量使用项目前缀(nn_)进行区分, 防止命名冲突 */
- (void)nn_printStyleGuideMode;
@end
