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

在这个面向对象实现中，构造函数的责任和一般面向对象语言中的构造函数稍微不同，首先，在 C 语言中实现函数重载模式的代码十分复杂。因此这里的构造函数不会有传入参数，更不支持函数重载。对于对象内的数据初始化可以使用一般的设置函数替代。另外，这里构造函数的工作首先是要创造一个对象，然后将对象（实际上是结构体）内的函数指针赋值，这一步也可以称为函数绑定。正如你所看到的，`create_obj`可以用于对象的生成，其参数为类名称。

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
    del(Animal, a);
    return 0;
}
```

使用`new(<类名>)`即可创建一个对象。

对于对象的删除，与一般面向对象语言有所不同的是，删除时需要指定删除的对象所属的类以调用相应的析构函数。使用`del(<类名>, <对象>)`来删除一个对象。

编译执行，可以发现成功打印了`Hello World!`。

```
Hello World!

Process finished with exit code 0
```
# 成员变量
为了演示成员变量的使用，我们为 Animal 类添加一个属性，年龄`age`。
修改`__Animal_content__`，添加`age`变量：

```
#define __Animal_content__ \
void func(say_hello)(); \
int age;
```

下面我们修改`main`函数来测试一下：

```
int main()
{
    Animal a = new(Animal);
    printf("a: My age is %d\n", a->age);
    a->age = 7;
    printf("a: My age is %d\n", a->age);
    Animal b = new(Animal);
    b->age = 5;
    printf("b: My age is %d\n", b->age);
    del(Animal, a);
    del(Animal, b);
    return 0;
}
```

运行一下：

```
a: My age is 0
a: My age is 7
b: My age is 5

Process finished with exit code 0
```

# 一般的成员函数
在实际的面向对象工程中，我们通常不直接使用对象中的成员变量，而是使用相应的设置和获取方法，这也被称为对属性的封装。

我们添加两个方法，来实现对`age`的封装。方法`get_age`用于获取当前对象的年龄，方法`grow`用于为当前对象年龄加一。

```
#define __Animal_content__ \
void func(say_hello)(); \
void func(grow)(Animal this); \
int func(get_age)(Animal this); \
int age;
```

这是修改后的`__Animal_content__`，可以发现两个方法都有一个参数`this`，这个参数指向的是当前的对象。如果方法需要用到类中的成员变量，则需要传入这个参数。

编写两个方法的实现：

```
class void grow(Animal this)
{
    this->age++;
}

class int get_age(Animal this)
{
    return this->age;
}
```

将两个方法绑定到类中：

```
new_cl->get_age = get_age;
new_cl->grow = grow;
```

修改`main`函数：

```
int main()
{
    Animal a = new(Animal);
    printf("a: My age is %d\n", a->get_age(a));
    a->grow(a);
    printf("a: My age is %d\n", a->get_age(a));
    Animal b = new(Animal);
    b->grow(b);
    b->grow(b);
    printf("b: My age is %d\n", b->get_age(b));
    del(Animal, a);
    del(Animal, b);
    return 0;
}
```

可以看到调用两个方法时都要传入自身。编译运行：

```
a: My age is 0
a: My age is 1
b: My age is 2

Process finished with exit code 0
```

# 更通用的构造函数和析构函数




# 实现继承

## 多层继承与多重继承

# 多态

# 静态成员变量
尽管一般使用获取和设置函数来获得成员变量的值，

# 后记
example 目录下有一些编写的示例程序。其中包括一些常见的面向对象设计的例子的实现。你可以参考它们进行编程。
