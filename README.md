# OOP-C

## 编写你的第一个类
提供的`oo_lan.h`头文件中包含了一些用于更高效创建类的宏定义。所以在编写你的代码之前，你需要包含该头文件。

和 C++ 相似，在 C 语言中一个类也由两个文件组成，`.c`文件与`.h`文件。其中`.h`文件主要用于声明类中的函数和定义类中的成员变量，而`.c`文件则用于定义函数的具体内容。

现在我们来编写一个`Animal`类，目前只有一个成员函数`say_hello`，它的功能是打印一行`Hello World!`。

### Animal.h

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

#### define 宏定义类声明
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

### Animal.c

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

#### Animal 类的构造函数
对于一个类，首先必要的两个成员函数就是构造函数和析构函数。首先我们来看一下最简单的构造函数写法。

构造函数的定义格式是固定的：
```
<类名> new_<类名>()
{
    内容
}
```

在这个面向对象实现中，构造函数的责任和一般面向对象语言中的构造函数稍微不同，首先，在 C 语言中实现函数重载模式的代码十分复杂。因此这里的构造函数不会有传入参数，更不支持函数重载。对于对象内的数据初始化可以使用一般的设置函数替代。另外，这里构造函数的工作首先是要创造一个对象，然后将对象（实际上是结构体）内的函数指针赋值，这一步也可以称为函数绑定。

正如你所看到的，`create_obj`可以用于对象的生成，其参数为类名称。

请注意，`create_obj`在内存分配失败时返回值可能为空。因此在实际情况下你应该添加一个适当的判断语句来避免出现问题。

#### Animal 类的析构函数
似乎在这里并没有创建一个析构函数，实际上，`deconstruct_void(Animal)`的任务就是创建一个空的析构函数。后文会介绍如何创建一个正常的析构函数。

#### 成员函数的定义
在本例中只有一个成员函数，`say_hello`函数，成员函数的定义要在前面加上`class`修饰符。这是为了将成员限制于本类中而不与其他类的同名函数冲突。

### main 函数
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
## 成员变量
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

## 一般的成员函数
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


## 更通用的构造函数和析构函数
除了函数绑定外，在构造函数中我们可能还要处理一些别的工作，例如变量的初始化等。同样的，在析构函数中，我们可能也要处理一些内存释放等问题。

### 构造函数
假设我们要在对象生成时打印一条语句，那么将语句加到函数绑定部分下方即可。

```
Animal new_Animal()
{
    Animal new_cl = create_obj(Animal);
    new_cl->say_hello = say_hello;
    new_cl->get_age = get_age;
    new_cl->grow = grow;

    printf("Create.\n");

    return new_cl;
}
```

运行结果如下：

```
Create.
a: My age is 0
a: My age is 1
Create.
b: My age is 2

Process finished with exit code 0
```

### 析构函数
假设我们为`Animal`添加一个新的属性，名字。

对于变量的添加和设置获取函数等和前面一样，在此不再详细说明。

我们主要研究一下析构函数。对于名字来说必定是一串字符串，因此我们通常使用`malloc`来分配内存给这个字符串。但是如果不加处理的的话，在对象被删除时这块空间就会泄漏。因此我们需要在析构函数中对其空间进行释放。

```
void del_Animal(Animal obj)
{
    if (obj->name)
        free(obj->name);
    del_obj(obj);
}
```

和构造函数相似，析构函数的定义也有固定的格式：

```
void del_<类名>(<类名> <变量名>)
{
    内容
}
```

`del_obj`用于删除一个类的对象。在删除对象之前，我们释放了`name`所用的内存空间。这便达到了我们的目的。


## 实现继承
继承是面向对象设计的一大特征。这一节我们我们介绍一下如何使用继承。

### 多层继承与多重继承
我们暂时无法使用多重继承。不过对于一个好的面向对象设计而言，通常不会出现多重继承的情况。但是我们可以使用多层继承。

### 编写 Dog 子类
我们新建一个`Animal`的子类`Dog`，以说明继承的基本用法。

想要继承`Animal`类，首先需要

```
#include "Animal.h"
```

同样我们需要声明`__Dog_content__`：

```
#define __Dog_content__ \
__Animal_content__ \
void func(bark)();

class_declaration(Dog);
```

可以看到继承的方法就是使用父类对象的`__Animal_content__`宏定义。同时我们新加入了一个自己的方法`bark`。

对于`bark`函数的实现如下：

```
void bark()
{
    printf("Bark.\n");
}
```

### 子类的构造函数和析构函数
#### 构造函数
```
Dog new_Dog()
{
    Dog new_cl = create_inher(Animal, Dog);
    new_cl->bark = bark;

    return new_cl;
}
```

子类的构造函数使用`create_inher`创建子类对象，`create_inher`根据传入的子类和父类名生成对象，并自动调用父类的构造函数。

### 覆盖父类方法
可以通过重新绑定的方式来覆盖父类的方法。例如，我们希望复写父类的`say_hello`方法，如下：

```
void say_hello()
{
    printf("Bark bark.\n");
}
```

利用重新绑定来进行覆盖：

```
new_cl->say_hello = say_hello;
```

```
int main()
{
    Dog a = new(Dog);
    a->bark();
    a->say_hello();
    del(Dog, a);
    return 0;
}
```

运行结果如下：

```
Create.
Bark.
Bark bark.

Process finished with exit code 0
```


## 多态
也可以在代码中实现多态。举个例子：

```
int main()
{
    Animal a = new(Dog);
    a->say_hello();
    del(Dog, a);
    a = new(Animal);
    a->say_hello();
    del(Animal, a);
    return 0;
}
```

运行结果如下：

```
Create.
Bark bark.
Create.
Hello World!

Process finished with exit code 0
```

可以看到，使用`Dog`类生成的对象赋值给`Animal`类的引用变量a之后，调用`a->say_hello`实际上调用的是`Dog`的`say_hello`方法。

### 向上转型和向下转型
您可以使用强制类型转换来进行向上转型和向下转型的操作。如下：

```
int main()
{
    Dog b = new(Dog);
    Animal a = (Animal)b;
    a->say_hello();
    b = (Dog)a;
    b->bark();
    del(Dog, a);
    return 0;
}
```

输出如下：

```
Create.
Bark bark.
Bark.

Process finished with exit code 0
```


## 静态成员变量
静态成员变量的定义方式和普通的变量不同，相对于变量来说和函数更为相似。假设我们现在要为`Animal`添加一个静态成员`num`以记录现在存在的`Animal`数量，在创建对象时自动加一，在销毁对象时自动减一。

首先在`__Animal_content__`中声明：

```
int static_member(num);
```

静态变量的声明需要使用`static_member`，但这里仅仅是一个引用而非变量本身。

接下来在`Animal.c`中添加`num`变量：

```
class int num;
```

然后在构造函数中使用`static_init`绑定静态变量：

```
static_init(new_cl->num, num);
```

在构造函数和析构函数中分别添加加一和减一操作，编写主函数：

```
int main()
{
    Animal a = new(Animal);
    Dog b = new(Dog);
    printf("Now have %d animal.\n", static_get(a->num));
    del(Animal, a);
    printf("Now have %d animal.\n", static_get(a->num));
    del(Dog, b);
    return 0;
}
```

尽管一般来说你应该设置额外的函数来获取`num`，不过出于演示目的这里使用`static_get`来获取静态变量的值。`static_get`实际上是解引用操作。你不能够直接使用引用来进行访问。

运行结果如下：

```
Create.
Create.
Now have 2 animal.
Now have 1 animal.

Process finished with exit code 0
```


## 后记
example 目录下有一些编写的示例程序。其中包括一些常见的面向对象设计的例子的实现。你可以参考它们进行编程。
