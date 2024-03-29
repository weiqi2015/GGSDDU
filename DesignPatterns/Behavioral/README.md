# 创建型模式

## 观察者模式

## 策略模式
定义对象间的一种一对多（变化）的依赖关系，以便当一个对象(Subject)的状态发生改变时，所有依赖于它的对象都得到通知并自动更新。

优点：
- 降低了目标与观察者之间的耦合关系，两者之间是抽象耦合关系。符合依赖倒置原则
- 目标与观察者之间建立了一套触发机制

缺点：
- 目标与观察者之间的依赖关系并没有完全解除，而且有可能出现循环引用
- 当观察者对象很多时，通知的发布会花费很多时间，影响程序的效率

### 拓展-同步回调和异步回调
同步回调：Subject调用Observer的update接口；
异步回调：Observer的Update是在工作线程中完成。

## 命令模式
将一个请求(行为)封装成一个对象，从而使你可以用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。

优点：
- 降低了系统耦合度
- 新的命令可以很容易添加到系统中去

缺点：
- 使用命令模式可能会导致某些系统有过多的具体命令类
  
## 模板方法模式
定义一个操作中的算法的骨架 **(稳定)** ，而将一些步骤延迟 **(变化)** 到子类中。
Template Method使得子类可以不改变(复用)一个算法的结构即可重定义(override 重写)该算法的某些特定步骤。

优点：
- 封装不变部分，扩展可变部分
- 提取公共代码，便于维护
- 行为由父类控制，子类实现

缺点：
- 每一个不同的实现都需要一个子类来实现，导致类的个数增加，使得系统更加庞大
  
## 责任链模式
使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成**一条链**，并沿着这条链传递请求，直到有一个对象处理它为止。

优点： 
- 降低耦合度。它将请求的发送者和接收者解耦
- 简化了对象。使得对象不需要知道链的结构
- 增强给对象指派职责的灵活性。通过改变链内的成员或者调动它们的次序，允许动态地新增或者删除责任
- 增加新的请求处理类很方便。

缺点：
- 不能保证请求一定被接收
- 系统性能将受到一定影响，而且在进行代码调试时不太方便，可能会造成循环调用
- 可能不容易观察运行时的特征，有碍于除错。

## 中介者模式
用一个中介对象来封装(封装变化)一系列的对象交互。中介者使各对象不需要显式的相互引用(编译时依赖->运行时依赖)，从而使其耦合松散(管理变化)，并且可以独立地改变它们之间的交互。
中介者模式又叫调停模式，是迪米特法则的典型应用。

优点：
- 类之间各司其职，符合迪米特法则。
- 降低了对象之间的耦合性，使得对象易于独立地被复用。
- 将对象间的一对多关联转变为一对一的关联，提高系统的灵活性，使得系统易于维护和扩展。
  
缺点：
- 中介者模式将原本多个对象直接的相互依赖变成了中介者和多个同事类的依赖关系。当同事类越多时，中介者就会越臃肿，变得复杂且难以维护。
  
## 状态模式
允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了其行为。

优点：
- 封装了转换规则 
- 枚举可能的状态，在枚举状态之前需要确定状态种类
- 将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为
- 允许状态转换逻辑与状态对象合成一体，而不是某一个巨大的条件语句块
- 可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数。

缺点：
- 状态模式的使用必然会增加系统类和对象的个数
- 状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱
- 状态模式对"开闭原则"的支持并不太好，对于可以切换状态的状态模式，增加新的状态类需要修改那些负责状态转换的源代码，否则无法切换到新增状态，而且修改某个状态类的行为也需修改对应类的源代码。
  
## 备忘录模式
在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可以将该对象恢复到原先保存的状态。

优点：
- 提供了一种可以恢复状态的机制。当用户需要时能够比较方便地将数据恢复到某个历史的状态。
- 实现了内部状态的封装。除了创建它的发起人之外，其他对象都不能够访问这些状态信息。
- 简化了发起人类。发起人不需要管理和保存其内部状态的各个备份，所有状态信息都保存在备忘录中，并由管理者进行管理，这符合单一职责原则。

缺点
- 资源消耗大。如果要保存的内部状态信息过多或者特别频繁，将会占用比较大的内存资源。

## 解析器模式
给定一个语言，定义它的文法的一种表示，并定义一种解释器，这个解释器使用该表示来解释语言中的句子。
优点：
- 可扩展性比较好，灵活，由于在解释器模式中使用类来表示语言的文法规则，因此可以通过继承等机制来改变或扩展文法
- 易于实现简单文法，在语法树中的每个表达式节点类都是相似的，所以实现其文法较为容易

缺点：
- 执行效率较低。解释器模式中通常使用大量的循环和递归调用，当要解释的句子较复杂时，其运行速度很慢，且代码的调试过程也比较麻烦。
- 会引起类膨胀。解释器模式中的每条规则至少需要定义一个类，当包含的文法规则很多时，类的个数将急剧增加，导致系统难以管理与维护

## 迭代器模式
提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露(稳定)该对象的内部表示。

优点:
- 访问一个聚合对象的内容而无须暴露它的内部表示。
- 遍历任务交由迭代器完成，这简化了聚合类。
- 它支持以不同方式遍历一个聚合，甚至可以自定义迭代器的子类以支持新的遍历。
- 增加新的聚合类和迭代器类都很方便，无须修改原有代码。
- 封装性良好，为遍历不同的聚合结构提供一个统一的接口。

缺点：
- 增加了类的个数，这在一定程度上增加了系统的复杂性。
  
## 访问者模式
表示一个作用与某对象结构中的各元素的操作。使得可以在不改变(稳定)各元素的类的前提下定义(扩展)作用于这些元素的新操作(变化)。
优点：
- 扩展性好。能够在不修改对象结构中的元素的情况下，为对象结构中的元素添加新的功能。
- 复用性好。可以通过访问者来定义整个对象结构通用的功能，从而提高系统的复用程度。
- 灵活性好。访问者模式将数据结构与作用于结构上的操作解耦，使得操作集合可相对自由地演化而不影响系统的数据结构。
- 符合单一职责原则。访问者模式把相关的行为封装在一起，构成一个访问者，使每一个访问者的功能都比较单一。

缺点：
- 增加新的元素类很困难。在访问者模式中，每增加一个新的元素类，都要在每一个具体访问者类中增加相应的具体操作，这违背了“开闭原则”。
- 破坏封装。访问者模式中具体元素对访问者公布细节，这破坏了对象的封装性，违反了迪米特原则。
- 违反了依赖倒置原则。访问者模式依赖了具体类，而没有依赖抽象类。