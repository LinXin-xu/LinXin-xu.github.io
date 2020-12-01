---
title：GitHub的搭建
---

# 一、搭建GitHub Page
## 准备工作如下：
### 1.一个GitHub账号
### 2.安装Node.js
### 3.安装Git
### 4.安装Hexo
# 开始：
#### 注册一个GitHub账号并登录。（github:http://github.com)


#### 建立博客Git仓库。（首先你要有自己的博客仓库，用来生成和存放博客文章),并为此创建一个说明网页（Github Page）
假设我们都有了GitHub账号，这事首先在右上角点击“+”，选择 **New** **repository**![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201193652295.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjQ1OTM0MA==,size_16,color_FFFFFF,t_70#pic_center)
#### 注意：仓库名一定是“你的GitHub用户名”+github.io
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201193932454.png)
之后为我们的项目添加一个**说明Pages!**
建好的项目顶部最右边有个**Setting**按钮，点击进入配置界面，下滑界面，直到看到**GitHub Page**，这时你发现竟然自动生成了一个说明网页！
因为GitHub说明网页的默认地址就是“你的GitHub用户名”+github.io，其他说明网页都是基于该地址的。![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201194627270.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjQ1OTM0MA==,size_16,color_FFFFFF,t_70)
到此为止，GitHub Page的部分就结束了。
###  **搭建Hexo，把GitHub Page修改为自己的博客界面！**
**安装Git以及Node.js！**

下载安装Windows版Git
下载安装Node.js
**验证：**
“Win”+R打开运行界面，输入“cmd”打开命令行窗口。


是否安装Git：输入git version出现版本信息：

git version 2.19.1.windows.1

是否安装Node.js:输入node -v出现版本信息：
v8.12.0

#### 安装及部署Hexo
首先**创建一个文件夹**，用来放置我们的Hexo。


然后进入我们的文件夹，例如我们的文件夹路径为D：\blog,则在终端依次输入并执行D：、cd blog进入文件夹


打开命令终端，利用Node.js的npm**安装Hexo：**

nmp install hexo-cli -g

输入hexo -v验证是否安装成功

输入hexo init初始化该文件

输入nmp install安装需要的组件

输入nmp g生成静态文件

输入nmp s启动服务器，现在在浏览器输入**http://localhost:4000/**打开我们的博客界面！

我们还需要把页面推送到GitHub Pages上，步骤如下：
##### 1.设置Git的user name和email
在我们创建博客文件夹里右击，选择Git Base Here，然后在窗口中依次输入**git config --global user.name"your name"**


**git config --global user.email"your email"**
##### 2.SSH授权


打开git bash，输入ssh-keygen -t rsa, 接着回车三下。

最后得到了两个文件：id_rsa和id_rsa.pub（默认存储路径是：C:\Users\Administrator.ssh）

登录Github，点击头像下的settings，添加ssh。新建一个new ssh key，将**id_ras.pub**件里的内容复制上去



![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201202718440.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjQ1OTM0MA==,size_16,color_FFFFFF,t_70)

**更换Hexo主题**

由于默认的博客主题可能不能满足大家的需求，所以再提一下更换主题的方法。



首先到Hexo官网中选择一款喜欢的主题



首先在Hexo系统文件夹中打开终端，然后输入git clone **https://github.com/cofess/hexo-theme-“主题名”.git themes/pure**

之后在系统目录theme文件夹下你会发现多出了pure命名的一个文件夹，这就是我们主题保存的位置,其中pure文件夹下的config.yml文件就是我们博客的配置文件，在里面可以自己对博客界面进行个性化配置，详情请参看网址
![在这里插入图片描述](https://img-blog.csdnimg.cn/20201201203444836.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MjQ1OTM0MA==,size_16,color_FFFFFF,t_70)

在我们的Hexo系统配置文件config.yml中，修改theme为自己的主题
**theme：自己的主题名**

然后进入文件夹cd themes/pure把主题提交git pull
重新生成博客静态文件，然后部署到
GitHub Pages

hexo g

hexo d

这样，我们的个性化博客就搭建完成啦！

