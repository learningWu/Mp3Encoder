# 《音视频权威指南》系列学习 —— Mp3Encoder

### 《第二章》音视频基础，转码 mp3

将书中 Eclipse 项目在 AS 中实现。可直接运行。
简化老师的 jni 分包，减少复杂度

### 环境

* AndroidStudio : 3.4  
* NDK : AS 中下载
* .pcm 格式测试文件可在 /resource 目录下获得，encode 后会生成一段小音乐的 .mp3 文件（我自己生成的已放置在 /resource 下）

### 权限

<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />  
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
    
### 坑

1. 模拟器没跑起来，真机可行（猜测是 CPU 问题）
2. 交叉编译出的 lame 是 x CPU版本，就需要指定 Application.mk 文件中 APP_ABI := armeabi-v7a (x CPU版本) ；否则，ndk-build 编译报错
3. Application.mk 中 APP_PLATFORM := android-9 指定的是最低兼容版本。可同理 build.gradle 文件中 minSdkVersion





