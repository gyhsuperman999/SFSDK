#import <Foundation/Foundation.h>

@protocol IBridgeCallback;
typedef void (^WebCloseHandler)(void);
@interface Manager : NSObject

+ (instancetype)startWithKey:(NSString *)key;
+ (void)stop;
+ (BOOL)createWeb:(NSInteger)countdown onClose:(WebCloseHandler)onClose;
+ (BOOL)isConfig;
+ (void)destroyWeb;

@end
