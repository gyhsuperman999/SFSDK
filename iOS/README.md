# SDK 使用指南

## 1️⃣ 引入SDK

将 `sfsdk.framework` 拖拽至您的 Xcode 项目中：

- 勾选 **“Copy items if needed”**
- 点击 **“Finish”** 完成导入
- 打开「Build Phases」→ 找到 **Embed Frameworks**
- 点击 + 添加 sfsdk.framework（如果已经有，跳过）

## 2️⃣ 代码部分

直接在工程入口的地方添加以下代码：

```
// 在要用的地方，一般是工程的启动入口调用就行。
// 引入头文件
#import <sfsdk/Manager.h>
// 代码调用
[Manager startWithKey:@"key"];  //key值由我方提供
//明展配置，判断是否已经获取配置，商店审核期不显示
[Manager isConfig];
//创建明展，time为广告位展示秒数(建议15秒)，onClose为关闭回调
[Manager createWV:time onClose:^{}]
```
## 3️⃣ 屏幕方向为竖屏应用