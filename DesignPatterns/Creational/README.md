# 创建型模式

## 使用设计模式解决问题
### 原始需求
我要用一台电脑工作。
正常工作的电脑需要有：显示器、主机、键盘。
我需要去买显示器、主机、键盘才能开始使用电脑工作。

Creational.cpp

缺点：
每次使用电脑的时候，都需要亲自买显示器、主机、键盘，很繁琐。

### 设计模式解决发展过程：
没有工厂 ==> 简单工厂 ==> 工厂 ==> 抽象工厂 

## 简单工厂模式
为了解决上面的缺点，不用每次使用电脑都要亲自购买显示器、主机、键盘。
我觉得找工厂购买主机，拿到就能直接使用。
目前工厂生产两款电脑，我可以根据电脑的型号购买电脑。
然后直接使用电脑，不需要管显示器、主机、键盘。

SimpleFactory.cpp

缺点：
1、每次有人购买产品，工厂都要对一对一去匹配产品，不方便管理。
2、工厂增加新的产品时，需要修改原有的生产线，存在隐患。

### 简单工厂模式拓展-动态创建
为了解决上面缺点，更方便管理越来越多的产品，工厂要求目前生产的产品都要注册什么产品在哪生产；
以后就直接在注册表中查找产品生产线。

SimpleFactorySync.cpp

## 工厂方法模式
由于目前的电脑无法满足我现有的要求；
需要找工厂生产新的电脑满足要求。
工厂生产新的产品都要改造原有的生产。不想每次都冒风险修改原有的生产线，所以工厂干脆建立一个工厂模型，每次要生产新产品都按照这个模型新建一间工厂生产。
有客户购买电脑时，按照型号找对应的生产工厂生产就性。

Factory.cpp

缺点：
1、每添加一个新产品，就需要创建一个新的工厂专门生产这个产品。
2、购买电脑时，每次都需要自己亲自去找对应的工厂购买。

### 拓展-IOC 控制反转
建立一个自动化生产工厂，客户只需要提供一个有注册的产品型号，工厂就能生产出这个产品。

FactoryIOC.cpp

## 抽象工厂模式
为了进一步提高产品的市场竞争力，工厂为不同的产品配备了不同的鼠标配件赠品。
鼠标品质不一样，制作成本不一样；
如果低**成本**的产品配了高**成本**的赠品，会亏钱。
所以不同的鼠标，由产品的工厂生产，配套出售。
抽象工厂针对的是**产品簇，产品之间时有关联的**，比如高成本产品和高成本赠品。

缺点：
增加新产品时需要修改原有的代码，或者是新建一个工厂做处理，新工厂和旧工厂部分重复。

## 建造者模式
定义：将一个复杂对象的构建与其表示相分离，使得同样的构建过程(稳定)可以创建不同的表示(变化)。

建造者模式将产品的内部零件和生产过程分离,从而使得产品有不同的形态。
建造者模式侧重于生产过程，这里是跟工厂模式不一样的。

生产 一间房子，先有地基，然后是轮廓，最后是内部装饰。
顺序是不能改的，地基、轮廓、和装饰都可以修改，石头房子可以是石头地基，石头轮廓，木头房子也可以是木头地基、木头轮廓。

Builder.cpp

缺点：
每次定制电脑，都要我主动去找指挥者和建造者才能得到我要的电脑；

### 拓展-链式
链式将导演角色功能放到建造者最后生成的接口中，生成零件和过程不分离。

BuilderChained.cpp

没有将构建和表示相分离，跟定义不符。

缺点：
建造者生成零件过程中，需要做逻辑判断是否往下执行。

链式跟原型模式更适合。

## 
## 原型模式
提供clone接口，用于实现对象的浅拷贝或者深拷贝；

工厂生产电脑的时候，为了满足不同的用户，设置了高中低配置和的电脑可以选择。

电脑除了内存和硬盘之外其它都一样
低配 内存：8G  硬盘：250GB
标配 内存：16G 硬盘：500GB
高配 内存：32G 硬盘：1TB

可以将标配的作为原型，克隆出低配和高配的产品

Prototype.cpp

## 单例模式
当对象在系统中只能存在一个实例，才能确保它的逻辑正确性和效率时，请使用单例模式。

### 饿汉式
SingletonEager.cpp

### 懒汉式-加锁、双重判断、reorder问题处理
SingletonEager.cpp

### 懒汉式 Magic static
SingletonClassicLazy