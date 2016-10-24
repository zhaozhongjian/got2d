# got2d

got2d是一个“兴趣使然”的2d游戏渲染框架。

框架的初衷是用于2d游戏的制作，并有可能会随着莫须有的游戏开发而演变成为一个2d游戏引擎。

框架将向ubi的引擎看齐，与之有区别的是，got2d应该不会打开深度缓存，而单纯的使用画家算法进行2d渲染。


## 初步规划特性

got2d应该有如下简单的功能。但是有可能会在任何时候产生“兴趣丢失”的情况，并终止开发。

- [ ] 渲染系统，能自定义渲染顺序
- [ ] 拥有材质相关的抽象，并支持一些2d常用的材质，并希望材质系统支持用户自定义材质
- [ ] 场景系统，拥有摄像机抽象，能进行可见性剔除，希望支持可拓展的场景节点
- [ ] 配乐系统，能播放背景音乐、音效
- [ ] 资源系统，能进行异步加载资源
- [ ] 2d特效系统：粒子、mesh、帧动画
- [ ] 2d骨骼动画与编辑器
- [ ] 自动FFD-sprite扭曲动画
- [ ] 自定义的Mesh、Texture格式

- - -

后期规划中，got2d或许会衍生如下功能：

- [ ] 跨平台的渲染接口，分别支持dx11、opengl 4、opengl es 3
- [ ] SpriteMesh生成：能自动处理超大的半透明纹理
- [ ] UI框架与编辑器
- [ ] 脚本系统：支持Lua或者Python动态脚本
- [ ] 场景编辑器：可拓展的编辑器
- [ ] 2D光照、阴影支持

## 内容简介

got2d使用c++编写，使用了部分c++ 11的语法。

现阶段got2d在vs2015下编写测试，所有的项目都在 got2d.sln 解决方案里。

got2d 为了配置简单，原则是尽量不使用第三方库和其他(如cmake)依赖。现在分为三部分：

* got2d 这个是框架实现
* testbed 用来测试的win32程序
* extern 这个是第三方依赖库的目录，现在包括
 * gml 一个简单的数学运算库，你需要通过submodule初始化并下载它。
 * img 一个简单的图像读取库

 
## 另外

由于经验有限，欢迎各位来搞，多提宝贵意见。
