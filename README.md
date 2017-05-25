# olsrd
version olsrd 0.6.5.4

## 两个分支：

- release-0.6.5.4：主分支，linux/android的编译，android的编译脚本需要修改
- ios， ios/osx的编译，armv7和arm64的编译脚本不一样，olsrd/make/Makefile.ios.armv7和Makefile.ios.armv7两个编译脚本

## 编译方法：

### android编译

ndk版本r8以下，make OS=android NDK_BASE=/path/to/your/android-ndk-r8 build_all

### ios编译 

ios分支可以参考iOS的PATCH补丁进行修改。[Add support for building for iOS](https://github.com/qhyuan1992/WifiMultiHop_for_iOS/blob/master/include/%5BOlsr-dev%5D%20%5BPATCH%5D%20Add%20support%20for%20building%20for%20iOS)

使用ios分支代码，make OS=ios build_all

根据需求使用include/Makefile.ios.armv7或Makefile.ios.arm64覆盖项目中的makefile文件，两个编译脚本使用的编译器不一样，使用时，去掉cpu类型后缀。



### iphone手机架构

>  arm64：iPhone6s | iphone6s plus｜iPhone6｜ iPhone6 plus｜iPhone5S | iPad Air｜ iPad mini2(iPad mini with Retina Display)

>  armv7s：iPhone5｜iPhone5C｜iPad4(iPad with Retina Display)

> armv7：iPhone4｜iPhone4S｜iPad｜iPad2｜iPad3(The New iPad)｜iPad mini｜iPod Touch 3G｜iPod Touch4

> armv7架构都是用的旧版本的xcode，使用编译器为llvm-4.2，我使用xcode4.6进行编译.

> arm64的cpu架构要使用高版本的xcode，4.6的xcode还是使用的llvm编译器，llvm编译器不支持arm7s和arm64，将编译程序设置为使用clang来编译。

