#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class DataConfig;
@class DataEnable;
@class WebViewOut;
@class WebViewIn;
@class LogViewer;
@protocol IBridgeCallback;
typedef void (^WVCloseHandler)(void);
@interface Manager : NSObject

@property (nonatomic, strong) NSMutableArray<WebViewOut *> *webViewList;
+ (instancetype)startWithKey:(NSString *)key;
+ (void)stop;
+ (BOOL)createWV:(NSInteger)countdown onClose:(WVCloseHandler)onClose;
+ (void)destroyWV;
- (instancetype)initWithContext:(UIViewController *)context key:(NSString *)key;
- (instancetype)initWithContext:(UIViewController *)context key:(NSString *)key callback:(id<IBridgeCallback>)callback;
- (BOOL)isConfigEnabled;
- (BOOL)hasWVIn;
- (void)createWVIn:(NSInteger)left
              top:(NSInteger)top
            right:(NSInteger)right
           bottom:(NSInteger)bottom
        countdown:(NSInteger)countdown
         onClose:(WVCloseHandler)onClose;
- (void)destroyWVIn;
- (void)setWVInVisibility:(BOOL)visible;
- (void)reloadWVInURL;
- (void)fetchGeoInfoWithArea:(BOOL)area collect:(BOOL)collect;
@end
