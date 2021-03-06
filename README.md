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
template<class genType, int size=50>
class genClass {
  genType storage[size];
};
// 实例化对象
genClass<int> intObject1;
genClass<int, 100> intObject2;
genClass<float, 123> floatObject;
// 定义通用函数
template<class genType>
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
