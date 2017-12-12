

# Objective-C 代码规范





## 示例

千言万语不及demo [示例代码]()



## 间距与样式



### 空格 vs. 制表符

* 一个缩减使用4个空格, 不推荐使用制表符(tab)缩进.
* 可在`Xcode-Perferences-Text Editing-Indentation`中进行设置,使用制表符时使用4个空格进行替代



### 单行代码长度

* `Xcode`单行代码长度推荐不超过100
* 可在`Xcode-Perferences-Text Editing-Editing`中进行设置



### 垂直空白留行

*   有目的性的使用空白留行, 尽量是当前屏幕内显示更对代码
*   避免函数,方法括号内使用无意义的空白留行
*   在函数之间,方法之间, 逻辑组之间使用空白留行



### 方法,函数长度

*   方法,函数的功能尽量小而集中。
*   函数,方法长度并没有严格限制,因为有时长函数,方法是可行的。如果一个函数超过了40行，考虑它是否可以在不破坏程序结构的情况下被分解。
*   即时长函数现在工作的很好, 但是经过版本迭代, 可能会导致难以找到bug
*   尽量保持功能简单,通俗易懂,让他人能够轻易理解和修改你的代码
*   重构代码时,考虑拆分长函数



### 方法声明及实现

* 在方法签名中，在 -/+ 符号后应该有一个空格。方法片段之间也应该有一个空格。
* 方法参数`*`号前添加空格, 保持统一样式
* 方法有多个参数时, 进行每个参数`:`对齐操作
* 方法第二个参数或者后续参数长度远超过第一个参数时, 使用4个空格进行间隔
* 方法声明采用驼峰方式命名
* 方法声明尽量体现方法功能

```objective-c
// GOOD:
- (void)doSomethingWithString:(NSString *)string {
    ...    
}

- (void)doSomethingWithFoo:(NNFoo *)foo
  					  rect:(CGRect)rect
                  interval:(NSTimeInterval)interval {
    ...
}

- (void)short:(NNFoo *)foo
      longKeyword:(NSString *)longKeyword
  longlongKeyword:(NSString *)longlongKeyword
  			error:(NSError **)error {
    ....			
}

// AVOID:
- (void)dosomethingWithString:(NSString *)string {
...    
}
```



### 条件判断

*   方法的大括号和其他的大括号（`if`/`else`/`switch`/`while` 等等）始终和声明在同一行开始，在新的一行结束。
*   当条件语句或循环语句适合单行显示时,可以使用单行样式
*   条件语句存在`else`时, 不允许使用单行模式, 语句必须使用`{}`进行包裹
*   当switch条件可能影响其他语句时, 需要特别注明

```objective-c
// GOOD:
if (hasNickName) printNickName();

if (hasNickName) {
    printNickName();
    doSomethind();
}

for (int i = 0; i < 100; i++) {
    printSomething();
}

if (hasNickName) {
    printNickName();
} else {
	printOtherNickName();
}

switch(i) {
  case 1:
    ...
    break;
  case 2:
    j++;
    // Falls through.
  case 3:
  case 4:
    ...
    break;
}

//AVOID:
if (hasNickName)
    printNickName();	// AVOID

for (int i = 0; i < 100; i++)
    printSomething();   //AVOID

if (hasNickName) printNickName();
else printOtherNickName();

if (hasNickName) {
  printNickName();
} else printOtherNickName();
```



### 表达式

*   二进制运算符与赋值运算符使用一个空格进行分割, 括号两个不需要添加空格

```objective-c
// GOOD:
x = 0;
v = w * x + y / z;
v = -y * (x + z);
v = w*z + y/z;
  
// AVOID:
v = x+3;
v = ( x + 3);
```



### 方法调用

*   方法调用的格式应该与方法声明的格式一致
*   当有多种样式可选择时, 优先考虑源文件中给出的示例样式
*   当后续参数命名过长时, 至少保持4个空格缩进, 保证后续的参数对齐

```objective-c
// GOOD:
[oneObject doSomethingWithString:arg1 timeInterval:arg2 error:arg3];
[oneObject doSomethingWithString:arg1
 					timeInterval:arg2
						   error:arg3];
[twoObject short:arg1
	     longKeyword:arg2
	 longlongKeyword:arg3];

// AVOID:
[oneObject doSomethingWithString:arg1
					timeInterval:arg2 error:arg3]; // 单行超过2个参数
[oneObject doSomethingWithString:arg1 timeInterval:arg2  // 单行超过2个参数
 						   error:arg3];
[oneObject doSomethingWithString:arg1 
 				timeInterval:arg2 
 						    error:arg3]; // 应该参数对齐
```



### 函数调用

*   函数调用多个参数应该尽量保持在同一行内实现, 或者依据文档内格式进行格式化
*   多行参数可以依据开括号进行对齐, 或者使用4个空格进行缩进对齐

```objective-c
// GOOD:
CFArrayRef array = CFArrayCreate(kCFAllocatorDefault, objects, numberOfObjects,
                                 &kCFTypeArrayCallBacks);
NSString *string = NSLocalizedStringWithDefaultValue(@"FEET", @"DistanceTable",
    resourceBundle,  @"%@ feet", @"Distance for multiple feet");

UpdateTally(scores[x] * y + bases[x],  // Score heuristic.
            x, y, z);

TransformImage(image,
               x1, x2, x3,
               y1, y2, y3,
               z1, z2, z3);

double scoreHeuristic = scores[x] * y + bases[x];
UpdateTally(scoreHeuristic, x, y, z);
```



## 命名

-   命名规则遵循[Objective-C naming rules](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/CodingGuidelines/CodingGuidelines.html), 尽可能在合理范围内做到可描述性
-   避免无意义的缩写规则
-   任何class,category,method,function 或者 variable 命名时, 首字母缩略词应该使用全大写形式. 例如苹果标准中使用全大写的首字母缩略词 `URL,ID,TIFF,EXIF,...`
-   C函数以及typedef 命名时首字母大写, 并使用驼峰命名规则



```objective-c
// GOOD:

// Good names.
int numberOfErrors = 0;
int completedConnectionsCount = 0;
tickets = [[NSMutableArray alloc] init];
userInfo = [someObject object];
port = [network port];
NSDate *gAppLaunchDate;

// AVOID:

// Names to avoid.
int w;
int nerr;
int nCompConns;
tix = [[NSMutableArray alloc] init];
obj = [someObject object];
p = [network port];
```



### 文件名

-   文件名应该能体现出它们所包含的类实现的名称
-   文件名后缀应该遵循项目规则,如下表所示

| Extension | Type                              |
| --------- | --------------------------------- |
| .h        | C/C++/Objective-C header file     |
| .m        | Objective-C implementation file   |
| .mm       | Objective-C++ implementation file |
| .cc       | Pure C++ implementation file      |
| .c        | C implementation file             |

-   项目中每个文件应该都有一个明确的唯一名称, 通常规则**(项目名 or 类前缀) + 文件名 + 文件所包含的类实现名称 + 文件后缀**
-   `category`文件别名应该包含原类名



```objective-c
// GOOD: 类前缀统一为NN

NNFooBarController.h
NNFooBarController.m
@interface NNFooBarController : UIViewController
@end
  
NNFooBarController+Utils.h
NNFooBarController+AutoCompleted.h
```



### 类名

-   类名(以及类别,协议名称)应该首字母大写
-   推荐使用**(项目名 or 类前缀) + 文件名 + 文件所包含的类实现名称**



### 类别名

*   类别名应该是用2-3个字母前缀来区分类别作用于工程内,还是开放给所有人使用
*   类名与类别名之间应该以空格隔开
*   为了避免`Objective-C`命名冲突, 类别中的方法可以使用**类别前缀_方法名**形式

```objective-c
// GOOD:
/** A category that adds parsing functionality to NSString. */
@interface NSString (GTMParsing)
/** 为了避免 */
- (NSString *)gtm_parsedString;
@end
```



### Objective-C 方法名

*   方法名和参数通常采用首字母小写的驼峰命名方式
*   首字母缩写全大写形式也是可行的
*   如果可能的话，方法名应该像一个句子一样读，这意味着你选择的参数名应该符合方法名。Objective-C方法名字往往很长，但这样做的好处，一个代码块几乎可以像读散文，可以省略很多不必要的注释。
*   必要时使用介词连接参数名 例如 `with,in,to,from,...`
*   返回对象的方法应该以一个返回对象的名词开头
*   getter方法应该命名与属性名一致，不需要添加`get`前缀。
*   点语法只适用于属性, 不适用于方法, 不要使用点语法访问方法
*   以下命名规则仅适用于**Objective-C**方法, 更多规则可以查看[Apple's Guide to Naming Methods](https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/CodingGuidelines/Articles/NamingMethods.html#//apple_ref/doc/uid/20001282-BCIGIJJF)

```objective-c
// GOOD:
- (NSURL *)URLWithString:(NSString *)URLString;
- (void)addTarget:(id)target action:(SEL)action;
- (CGPoint)convertPoint:(CGPoint)point fromView:(UIView *)view;
- (void)replaceCharactersInRange:(NSRange)aRange
            withAttributedString:(NSAttributedString *)attributedString;
- (SandSwitch *)sandSwitch;
- (id)delegate
  
@property(nonatomic, getter=isGlorious) BOOL glorious;
- (BOOL)isGlorious;

BOOL isGood = object.glorious;      // GOOD.
BOOL isGood = [object isGlorious];  // GOOD.
NSArray<Frog *> *frogs = [NSArray<Frog *> arrayWithObject:frog];
NSEnumerator *enumerator = [frogs reverseObjectEnumerator];  // GOOD.

// AVOID:
- (Sandwich *)makeSandwich;  // 避免使用无意义的介词,谓词
- (id)getDelegate; 		     // getter 方法无需添加get

NSEnumerator *enumerator = frogs.reverseObjectEnumerator;  // 避免使用点语法访问方法函数
```



### 函数名

*   采用首字母大写的驼峰命名
*   因为Objective-C 没有命名空间管理, 推荐使用 **前缀+首字母大写的函数名** 

```objective-c
// GOOD:

static void AddTableEntry(NSString *tableEntry);
static BOOL DeleteFile(char *filename);
extern NSTimeZone *GTMGetDefaultTimeZone();
extern NSString *GTMGetURLScheme(NSURL *URL);
```



### 变量名

*   采用首字母小写的驼峰命名
*   实例变量添加下划线
*   全局变量或文件作用域内变量 应该添加g
*   常量应该首字母大写的驼峰命名,并且添加统一项目前缀
*   全局静态变量添加k开头

```objective-c
// GOOD:
static int gGlobalCounter;

extern NSString *const GTLServiceErrorDomain;

typedef NS_ENUM(NSInteger, GTLServiceError) {
  GTLServiceErrorQueryResultMissing = -3000,
  GTLServiceErrorWaitTimedOut       = -3001,
};

static const int kFileCount = 12;
static NSString *const kUserKey = @"kUserKey";

@implementation NNFooBarController {
    NSString *_name;
}
- (void)printMethod {
    NSString *tempValue;
}
@end
```



## 书写和声明



### 本地变量

*   本地变量声明时,没必要显式的设置为nil
*   变量声明的作用域尽可能小
*   同样的适当的时候变量作用域大于他的使用范围也是可行的, 例如在循环等情况下

```objective-c
// GOOD:
CLLocation *location = [self lastKnownLocation];
for (int meters = 1; meters < 10; meters++) {
  reportFrogsWithinRadius(location, meters);
}

CLLocation *location;

// AVOID

CLLocation *location = nil; // 没必要

int meters;                                         // 不符合命名规则1
for (meters = 1; meters < 10; meters++) {
  CLLocation *location = [self lastKnownLocation];  // 没必要调用多次lastKnownLocation方法
  reportFrogsWithinRadius(location, meters);
}
```



### 无符号整数

*   代码中尽量避免使用无符号整数, 除非对接系统接口返回的类型
*   减法运算无符号整形可能会产生越界问题, 需要注意
*   无符号整形更多的使用在`NS_ENUM`或者`NS_OPTIONS`中

```objective-c
// GOOD: 
NSUInteger numberOfObjects = array.count;
for (NSInteger counter = numberOfObjects - 1; counter > 0; --counter)
// AVOID:
for (NSUInteger counter = numberOfObjects - 1; counter > 0; --counter)  // 可能越界
```



### 32-bit And 64-bit

*   由于32-bit和64-bit区别, 避免long与NSInteger,NUInteger,CGFloat, 除非对接系统接口函数返回的类型
*   对接系统接口时, 使用long,NSInteger,NSUInteger,CGFloat是合适的, 但是大多数计算情况下依然需要避免
*   文件以及缓存大小经常超过32-bit限制, 所以使用`int64_t`而不是long,NSInteger,NSUInteger



```objective-c
// GOOD;
int32_t scalar1 = proto.intValue;

int64_t scalar2 = proto.longValue;

NSUInteger numberOfObjects = array.count;

CGFloat offset = view.bounds.origin.x;

int64_t fileSize;
// AVOID:

NSInteger scalar2 = proto.longValue;  // AVOID.
long fileSize; // 可能大小超过限制
```



## 注释

注释对于保持代码可读性至关重要。下面的规则描述了你应该评论什么以及在哪里。但是请记住：虽然注释很重要，但最好的代码是自文档化。给类型和变量赋予合理的名称要比使用晦涩的名字更好，然后通过注释来解释它们。

注意标点符号、拼写和语法；写得好的注释比写得差的容易。

注释应该和叙事文本一样易读，恰当的大写和标点符号。在许多情况下，完整的句子比句子片段更易读。较短的注释，比如代码行结尾处的注释，有时可以不那么正式，但使用一致的样式。当你写注释的时候，为你的读者写下：下一个需要理解你代码的人。慷慨大方，下一个可能是你！



### 文件注释

每个文件都有对其内容的描述注释, 通常包括下列几项

*   版权说明
*   基础内容说明



### 声明注释

*   每个有意义的接口，不论公共的还是私有的，都应该有一个附带的注释来描述它的用途。
*   类，属性，该函数，类，协议声明，和枚举的注释都应该可以文档化。
*   Doxygen风格的注释可以解析成Xcode的格式化文档。有各种各样的doxygen的命令；使用它们始终在一个项目。
*   如果您已经在文件顶部的注释中详细地描述了一个接口，可以简单地声明，“在文件顶部看到注释以获得完整的描述”，但一定要有一些注释。
*   每个方法都应该注释, 来说明他的功能,参数,返回值,多线程可能产生的副作用等等
*   声明注释更侧重描述功能, 而不是解释函数到底做了什么, 函数如何实现可以在实现中进行注释
*   对于属性的一些边界值, 需要在注释中进行体现



### 实现注释

*   为一些复杂的,难懂的代码段提供注释
*   注释可以于代码处于同一行以便于更好理解阅读, 注意至少预留4个空格 进行隔开

```objective-c
// GOOD:

// Set the property to nil before invoking the completion handler to
// avoid the risk of reentrancy leading to the callback being
// invoked again.
CompletionHandler handler = self.completionHandler;
self.completionHandler = nil;
handler();

[self doSomethingWithALongName];  // Two spaces before the comment.
[self doSomethingShort];          // More spacing to align the comment.
```



## C特性



### 宏

*   能使用`const`常量,枚举, 代码块或者C语言时, 就不要使用宏, 只有在没有其他解决办法时才采用宏定义
*   使用全局唯一的名称来避免编译符号冲突, 如果可能, 先使用`#undef`后在定义自己的宏
*   宏定义采用全大写字母形式,类似C语言. 不要使用C,Objective-C的关键字定义宏
*   避免宏捕获上下文环境的变量
*   避免使用宏定义`class,property,method,...`
*   避免使用宏生成方法的实现



```objective-c
// GOOD:

#define GTM_EXPERIMENTAL_BUILD ...      // GOOD

// Assert unless X > Y
#define GTM_ASSERT_GT(X, Y) ...         // GOOD, macro style.

// Assert unless X > Y
#define GTMAssertGreaterThan(X, Y) ...  // GOOD, function style.

// AVOID:

#define kIsExperimentalBuild ...        // AVOID

#define unless(X) if(!(X))              // AVOID


#define ARRAY_ADDER(CLASS) \
  -(void)add ## CLASS ## :(CLASS *)obj toArray:(NSMutableArray *)array

ARRAY_ADDER(NSString) {
  if (array.count > 5) {              // AVOID -- where is 'array' defined?
    ...
  }
}
```



## Cocoa Objective-C 特性

### 指定初始化方法



*   明确标识初始化方法, 使用`NS_DESIGNATED_INITIALIZER`宏
*   如果使用了`NS_DESIGNATED_INITIALIZER`宏, 对于其他的使用`NS_UNAVAILABLE`宏进行标识



### 重写初始化方法

*   重写初始化方法时,确保调用了父类的指定初始化方法



### 重写NSObject方法



*   将`NSObject`的重写方法置于`@implementation`最顶部, 例如`init,copyWithZone:,dealloc,...`
*   工厂类创建方法放置位置优先于`NSObject`的重写方法



### 头文件中的变量作用域

*   在头文件中声明的变量, 应该显示使用`@protected,@private`

```objective-c
// GOOD:

@interface MyClass : NSObject {
 @protected
  id _myInstanceVariable;
}
@end
```



### #import vs. #include

`#import`引入 Objective-C和Objective-C++ 头文件

`#include`引入C/C++ 头文件



### 头文件引入顺序

1.  相关联的头文件
2.  系统头文件
3.  语言类库相关头文件
4.  其他依赖头文件

```objective-c
// GOOD:

#import "BazViewController.h" // 相关联的头文件

@import UIKit;
#import <Foundation/Foundation.h> // 系统头文件

#include <unistd.h>   // 其他c,c++底层类库头文件
#include <vector>

#include "basictypes.h"  // 其他c语言模块 头文件

#import "BazModel.h" 	// 其他模块头文件

// AVOID
#import <Foundation/NSArray.h>  
#import <Foundation/NSString.h>

```



### 初始化, dealloc 陷阱

代码的初始化和释放应该避免调用实例方法。

父类的初始化会比子类初始化先完成。直到所有`classes`初始化完成之前,调用实例方法, 可能会导致访问到未实例化的状态属性。

在dealloc存在类似的问题，其中一个方法调用可能会导致调用一个已释放操作。

在一种情况下这是不太明显的是属性访问器。这些可以像任何其他选择器一样被重写。实际上，直接分配和释放该在初始化和释放，而不是依赖于访问器。



```objective-c
// GOOD:

- (instancetype)init {

  if (self = [super init]) {
    _bar = 23;  // GOOD.
  }
  return self;
}

- (void)dealloc {
  [_notifier removeObserver:self]; 
}

// AVOID:

- (instancetype)init {

  if (self = [super init]) {
    self.bar = 23;  // AVOID.
    [self sharedMethod];  // AVOID. Fragile to subclassing or future extension.
  }
  return self;
}

- (void)dealloc {
  [self removeNotifications]; 
}
```



### 对包含类型使用轻量级泛型

```objective-c
// GOOD:

@property(nonatomic, copy) NSArray<Location *> *locations;
@property(nonatomic, copy, readonly) NSSet<NSString *> *identifiers;

NSMutableArray<MyLocation *> *mutableLocations = [otherObject.locations mutableCopy];

typedef NSSet<NSDictionary<NSString *, NSDate *> *> TimeZoneMappingSet;
TimeZoneMappingSet *timeZoneMappings = [TimeZoneMappingSet setWithObjects:...];

```



### BOOL陷阱

```objective-c
// GOOD:

- (BOOL)isBold {
  return ([self fontTraits] & NSFontBoldTrait) ? YES : NO;
}
- (BOOL)isValid {
  return [self stringValue] != nil;
}
- (BOOL)isEnabled {
  return [self isValid] && [self isBold];
}

BOOL great = [foo isGreat];
if (great) {         // GOOD.
  // ...be great!
}

// AVOID:

- (BOOL)isBold {
  return [self fontTraits] & NSFontBoldTrait;  // AVOID.
}

- (BOOL)isValid {
  return [self stringValue];  // AVOID.
}

BOOL great = [foo isGreat];
if (great == YES) {  // AVOID.
  // ...be great!
}
```





# 其他 Objective-C 风格指南

如果感觉我们的不太符合你的口味，可以看看下面的风格指南：

-   [Google](https://google.github.io/styleguide/objcguide.xml)
-   [GitHub](https://github.com/github/objective-c-conventions)
-   [Adium](https://trac.adium.im/wiki/CodingStyle)
-   [Sam Soffes](https://gist.github.com/soffes/812796)
-   [CocoaDevCentral](http://cocoadevcentral.com/articles/000082.php)
-   [Luke Redpath](http://lukeredpath.co.uk/blog/my-objective-c-style-guide.html)
-   [Marcus Zarra](http://www.cimgf.com/zds-code-style-guide/)