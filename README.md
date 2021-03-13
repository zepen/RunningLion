# RunningLion
数据结构与算法学习笔记

### C++ 基础知识
* 1.1 抽象数据类型
  
  抽象数据类型（ADT）是计算机科学中具有类似行为的特定类别的数据结构的数学模型。
* 1.2 封装
  
   面向对象程序设计（OOP）以对象为中心，对象用类来定义，类是一个模板，对象根据类来创建。类中定义的函数称为成员函数，类中使用的变量称为成员数据。
数据及其相关操作的结合称为数据封装。对象是类的实例，是用类定义创建的实体。
  C++的强大特性是能够在类声明中使用类型参数来声明通用类。
```c++
// 定义通用类
template<typename genType, int size=50>
class genClass {
  genType storage[size];
};
// 实例化对象
genClass<int> intObject1;
genClass<int, 100> intObject2;
genClass<float, 123> floatObject;
// 定义通用函数
template<typename genType>
void swap(genType& el1, genType& el2){
  genType tmp = el1;
  el1 = el2;
  el2 = tmp;
}
```
* 1.3 继承
  
  OOL允许创建类的层次关系，所以对象不一定是单一类的实例。
```c++
// 基类
class BaseClass{
public:
    BaseClass(){}
    void f(string s = "unknow"){
        cout << "Function h() in BaseClass called from" << s << endl;
    }

protected:
    void g(string s = "unknow") {
        cout << "Function g() in BaseClass called from" << s << endl;
    }

private:
    void h(){
        cout << "Function h() is BaseClass\n";
    }
};
// 子类
class SubClass1 : public virtual BaseClass{
public:
    void f(string s = "unknow"){
        cout << "Function f() in subClass1 called from" << s << endl;
        g("subClass1");
    }
};

```
* 1.4 指针
```c++
int a = 1;
int *p; // 定义指针
p = &a; // 指向变量内存

int a1 [10];  // 定义数组
int *p1 = new int[10]; // 动态分配，指针指向数组起始位置
delete [] p1; // 释放内存

int &b = a; // 引用, 就是别名

double f(double x){
   return 2*x;
} // 定义函数

double sum(double (*f)(double), int n, int m){
   double result = 0;
   for (int i = n; i <= m; i++)
        result += f(i);
        return result;
} // 函数作为参数传入
sum(f, 0 ,10); // 调用sum函数


```
* 1.5 多态性
```c++
// virtual实现动态绑定
class Class1{
public:
virtual void f(){
cout << "Function f() in Class1\n";
}
void g(){
cout << "Function g() in Class1\n";
}
};

class Class2{
public:
virtual void f(){
cout << "Function f() in Class2\n";
}
void g(){
cout << "Function g() in Class2\n";
}
};

Class1 class1, *p;
p = &class1;
p->f(); // 调用class1中的f方法
p->g(); // 调用class1中的g方法

Class2 class2;
p = (Class1*) &class2; // 指针指向class2对象
p->f(); // 调用class2中的f方法
p->g(); // 调用class1中的g方法
```

* 1.7 标准模板库
  
  STL包含的容器有: vector、deque、list、forward_list、map、multimap、unordered_map、unordered_multimap、
  set、multiset、unordered_set、unordered_multiset、 stack、queue、priority_queue
```c++
#include <algorithm>
// 头文件包含70多种通用算法
```

### 复杂度分析
* 1.8 大 O 表示法

定义 1: 如果存在正是 c和 N, 对于所有的 n >= N, 有 f(n) <= cg(n), 则 f(n) = O(g(n))

* 1.9 大 O 表示法的性质

性质1: 如果 f(n) = O(g(n)), g(n) = O(h(n)), 那么 f(n) = O(h(n))

性质2: 如果 f(n) = O(h(n)), g(n) = O(h(n)), 则 f(n) + g(n) = O(h(n))

性质3: an^k = O(n^k)

性质4: 对于任何正数 j, n^k = O(n^(k + j))

性质5: 如果 f(n) = cg(n), 则 f(n) = O(g(n))

性质6: 对于任意正数 a 和 b (b != 1), loga(n) = O(logb(n))

性质7: 对于任何正数 a != 1, loga(n) = O(lgn), 其中 lgn = log2(n)

* 2.0

定义 2: 若存在正数 c 和 N, 对于所有的 n >= N, 有 f(n) >= cg(n), 则 f(n) = Ω(g(n))

定义 3: 若存在正数 c1、c2 及 N, 对于所有 n >= N, 有 c1g(n) <= f(n) <= c2g(n), 则 f(n) = Θ(g(n))

* 2.1 复杂度示例

在每秒运行一百万次的计算机上的执行时间 (1s = 10^6 us = 10^3 ms)
<table>
    <tr>
        <th colspan="1">类别</th>
        <th colspan="1">复杂度</th>
        <th colspan="6">操作次数和执行时间(1条指令/微秒)</th>
    </tr>
    <tr>
        <th colspan="2">n</th>
        <th colspan="1">10</th>
        <th colspan="1">10^2</th>
        <th colspan="1">10^3</th>
        <th colspan="1">10^4</th>
        <th colspan="1">10^5</th>
        <th colspan="1">10^6</th>
    </tr>
    <tr>
        <td>常数</td>
        <td>O(1)</td>
        <td>1us</td>
        <td>1us</td>
        <td>1us</td>
        <td>1us</td>
        <td>1us</td>
        <td>1us</td>
    </tr>
    <tr>
        <td>对数</td>
        <td>O(1gn)</td>
        <td>3us</td>
        <td>7us</td>
        <td>10us</td>
        <td>13us</td>
        <td>16us</td>
        <td>20us</td>
    </tr>
    <tr>
        <td>线性</td>
        <td>O(n)</td>
        <td>10us</td>
        <td>100us</td>
        <td>1ms</td>
        <td>10ms</td>
        <td>0.1s</td>
        <td>1s</td>
    </tr>
    <tr>
        <td>O(nlgn)</td>
        <td>O(nlgn)</td>
        <td>33us</td>
        <td>664us</td>
        <td>10ms</td>
        <td>133ms</td>
        <td>1.6s</td>
        <td>20s</td>
    </tr>
    <tr>
        <td>二次</td>
        <td>O(n^2)</td>
        <td>100us</td>
        <td>10ms</td>
        <td>1s</td>
        <td>1.7m</td>
        <td>16.7m</td>
        <td>11.6d</td>
    </tr>
    <tr>
       <td>三次</td>
        <td>O(n^3)</td>
        <td>1ms</td>
        <td>1s</td>
        <td>16.7m</td>
        <td>11.6d</td>
        <td>31.7y</td>
        <td>31709y</td>
    </tr>
    <tr>
        <td>指数</td>
        <td>O(2^n)</td>
        <td>10ms</td>
        <td>3.17*10^7y</td>
        <td>10^301</td>
        <td>10^3010</td>
        <td>10^30103</td>
        <td>10^301030</td>
    </tr>
</table>

### 链表

### 栈与队列

### 递归

### 二叉树

### 多叉树

### 图

### 排序

### 散列

### 数据压缩

### 内存管理

### 字符串匹配


### Reference
[1][美] Adam Drozdek, Data Structures and Algorithms in C++, 4th Edition
