# 编写你的第一个类
提供的`oo_lan.h`头文件中包含了一些用于更高效创建类的宏定义。所以在编写你的代码之前，你需要包含该头文件。

和 C++ 相似，在 C 语言中一个类也由两个文件组成，`.c`文件与`.h`文件。其中`.h`文件主要用于声明类中的函数和定义类中的成员变量，而`.c`文件则用于定义函数的具体内容。

现在我们来编写一个`Animal`类，目前只有一个成员函数`say_hello`，它的功能是打印一行`Hello World!`。

## Animal.h

下面是`Animal.h`文件的内容：

```
#ifndef OOP_EXAMPLE_ANIMAL_H
#define OOP_EXAMPLE_ANIMAL_H

#include "oo_lan.h"

#define __Animal_content__ \
void func(say_hello)();

class_declaration(Animal);

#endif
```

`.h`文件通常只有两部分，`define`宏定义和`class_declaration`宏调用。其顺序不可颠倒。

### define 宏定义类声明
`#define __<类名称>_content__`用于声明类的成员。在这个`Animal`类中，只有一个成员函数`say_hello`，成员函数的声明方式如下：

```
返回值 func(函数名)(参数列表);
```

对于普通成员变量的声明如下：

```
变量类型 变量名;
```

如果在定义时需要换行，和普通的宏定义一样在行末使用反斜杠转义即可。

`class_declaration`宏调用用于声明一些必要的结构体等。传入的参数为类名称。

## Animal.c

接下来是`.c`文件，内容如下：

```
#include "Animal.h"

class void say_hello()
{
    printf("Hello World!\n");
}

Animal new_Animal()
{
    Animal new_cl = create_obj(Animal);
    new_cl->say_hello = say_hello;

    return new_cl;
}

deconstruct_void(Animal)
```

### Animal 类的构造函数
对于一个类，首先必要的两个成员函数就是构造函数和析构函数。首先我们来看一下最简单的构造函数写法。

在这个面向对象实现中，构造函数的责任和面向对象语言中的构造函数不同，首先，在 C 语言中实现函数重载模式的代码十分复杂。因此这里的构造函数不会有传入参数，更不支持函数重载。对于对象内的数据初始化可以使用一般的设置函数替代。另外，这里构造函数的工作首先是要创造一个对象，然后将对象（实际上是结构体）内的函数指针赋值，这一步也可以称为函数绑定。正如你所看到的，`create_obj`可以用于对象的生成，其参数为类名称。

### Animal 类的析构函数
似乎在这里并没有创建一个析构函数，实际上，`deconstruct_void(Animal)`的任务就是创建一个空的析构函数。后文会介绍如何创建一个正常的析构函数。

### 成员函数的定义
在本例中只有一个成员函数，`say_hello`函数，成员函数的定义要在前面加上`class`修饰符。这是为了将成员限制于本类中而不与其他类的同名函数冲突。

## main 函数
```
#include <stdio.h>

#include "Animal.h"

int main()
{
    Animal a = new(Animal);
    a->say_hello();
    return 0;
}
```

使用`new(<类名>)`即可创建一个对象。编译执行，可以发现成功打印了`Hello World!`。

```
Hello World!

Process finished with exit code 0
```
# 成员变量

# 更通用的构造函数和析构函数

# 一般的成员函数
this

# 实现继承

## 多层继承与多重继承

# 多态

# 静态成员变量
尽管一般使用获取和设置函数来获得成员变量的值，

# 后记
example 目录下有一些编写的示例程序。其中包括一些常见的面向对象设计的例子的实现。你可以参考它们进行编程。
