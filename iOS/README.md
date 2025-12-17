# SDK 使用指南

## 接入方式

将 `sfsdk_dist` 拖拽至您的 Xcode 项目中：

- 勾选 **“Copy items if needed”**
- 点击 **“Finish”** 完成导入
- Target → Build Phases → Link Binary With Libraries 点击 +，把 libsfsdk.a 加进来
- Target → Build Settings → Search Paths → Header Search Paths 加上头文件目录 $(SRCROOT)/sfsdk_dist/include

## 工程配置
- 打开项目的 Podfile，并将下面这行代码添加到应用的 target build 配置中：
```ruby
pod 'Google-Mobile-Ads-SDK'
```
- 在终端运行：
```ruby
pod install --repo-update
```
- Info.plist 已配置 GADApplicationIdentifier 忽略下方配置
  Info.plist 未配置 GADApplicationIdentifier 则需要更新 Info.plist 文件添加以下键和字符串值
```xml
<key>GADIntegrationManager</key>
<string>webview</string>
```
## 代码部分

直接在工程入口的地方添加以下代码：

```objective-c
// 在要用的地方，一般是工程的启动入口调用就行。
// 引入头文件
#import "Manager.h"
// 代码调用
[Manager startWithKey:@"key"];  //key值由我方提供

/*
 * =============================================
 * 前端展示功能（可选）
 * 以下方法为接入 SDK 的展示控制接口
 * 如不需要展示，到此 SDK 接入即完成
 * =============================================
 */
// 判断是否已加载完配置，游戏启动10秒后开始获取配置信息
[Manager isConfig];
// 创建明展，time为广告位展示秒数(建议15秒)，onClose为关闭回调，在商店审核阶段不要调用显示
[Manager createWeb:time onClose:^{}]
```

## 3️⃣ 注意
### 1.屏幕方向为竖屏应用 
### 2.需发提供下App的BundleVersion用于控制SDK生效的App版本
### 3.LOG输出中搜索 SFSDK 出现 initialized 初始化成功