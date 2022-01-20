
# 数组

数组的声明并不是声明一个个单独的变量，所有的数组都是由连续的内存位置组成。最低的地址对应第一个元素，最高的地址对应最后一个元素。

![](https://www.runoob.com/wp-content/uploads/2014/09/c-array-2021-01-18-2.png)

## 声明数组

```C
type arrayName [ arraySize ];

\\ 例如
double balance[10];

\\ 逐个初始化数组
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};

\\ 可以省略数组尺寸
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};

\\ 为数组中特定元素赋值
balance[4] = 50.0;
```

## 多维数组

```C
\\ 声明多维数组
type name[size1][size2]...[sizeN];

\\ 例如，下面的声明创建了一个三维 5 . 10 . 4 整型数组：
int threedim[5][10][4];

\\ 初始化二维数组
int a[3][4] = {  
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};

// 内部嵌套的括号是可选的，下面的初始化与上面是等同的：
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
```

## 传递数组给函数

以下三种方法都可以告诉编译器将要接收一个整型指针，也可以传递一个多维数组作为形式参数。

```C
// 入参形式为指针
void myFunction(int *param){} 

// 入参形式为已定义大小的数组
void myFunction(int param[10]){} 

// 入参形式为未定义大小的数组
void myFunction(int param[])
```
---

# 指针

## 指针基础

`*`操作符用于定义指针变量，指针变量可以当做数据体本体类型来进行操作，`&`操作符用于获取访问地址。

![](https://www.runoob.com/wp-content/uploads/2014/09/c-pointer.png)

在这里，type是指针的基类型，它必须是一个有效的C数据类型，var-name是指针变量的名称。用来声明指针的星号`*`与乘法中使用的星号是相同的。但是，在这个语句中，星号是用来指定一个变量是指针。以下是有效的指针声明：

```C
\\ 声明一个指针
type *var-name;

int    *ip;    /* 一个整型的指针 */
double *dp;    /* 一个 double 型的指针 */
float  *fp;    /* 一个浮点型的指针 */
char   *ch;    /* 一个字符型的指针 */
```

使用用例：

```C
int  var = 20;   /* 实际变量的声明 */
int  *ip;        /* 指针变量的声明 */
ip = &var;       /* 在指针变量中存储 var 的地址 */

/*
                var 变量的地址: 0x7ffeeef168d8
                ip 变量存储的地址: 0x7ffeeef168d8
                *ip 变量的值: 20
*/
```

## 空指针

声明或者使用的时候没有确切的地址可以赋值，会给指针赋值一个NULL，即空指针。

```C
int *ptr = NULL;
// ptr 的地址是 0x0

if(ptr)     /* 如果 p 非空，则完成 */
if(!ptr)    /* 如果 p 为空，则完成 */
```

## 指针算术运算

C 指针是一个用数值表示的地址。因此，可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-。

- 指针的每一次递增，它其实会指向下一个元素的存储单元。
- 指针的每一次递减，它都会指向前一个元素的存储单元。
- 指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。

指针可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。


## 指针数组

```C
int *ptr[MAX];    // 指针数组

const int MAX = 3;
int var[] = {10, 100, 200};
int i, *ptr[MAX];
for ( i = 0; i < MAX; i++) {
  ptr[i] = &var[i]; /* 赋值为整数的地址 */
}
```

## 指向指针的指针

指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。

![](https://www.runoob.com/wp-content/uploads/2014/09/pointer_to_pointer.jpg)

声明：

```C
int **var;  // 在变量名前放置两个星号
```

![](https://www.runoob.com/wp-content/uploads/2014/09/c-pointerxxxxx.png)

## 传递指针给函数

```C
void getSeconds(unsigned long *par){}

\\ 调用方法
unsigned long sec;
getSeconds(&sec);

\\ 或者
long balance[5] = {1000, 2, 3, 17, 50};
getSeconds(balance);
```

## 从函数返回指针

声明：

```C
int * myFunction(){}
```

## 函数指针

指向函数的指针，函数指针可以像一般函数一样，用于调用函数、传递参数。

声明：

```C
typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数、返回值的函数指针类型
```

## 回调函数

函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。

简单讲：回调函数是由别人的函数执行时调用你实现的函数。

一个比方：

你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话，过了几天店里有货了，店员就打了你的电话，然后你接到电话后就到店里去取了货。在这个例子里，你的电话号码就叫回调函数，你把电话留给店员就叫登记回调函数，店里后来有货了叫做触发了回调关联的事件，店员给你打电话叫做调用回调函数，你到店里去取货叫做响应回调事件。

```C
#include <stdlib.h>  
#include <stdio.h>
 
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}
 
// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}
 
int main(void)
{
    int myarray[10];
    /* getNextRandomValue 不能加括号，否则无法编译，因为加上括号之后相当于传入此参数时传入了 int , 而不是函数指针*/
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}
```
---

# 字符串

在 C 语言中，字符串实际上是使用 null 字符 \0 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。由于在数组的末尾存储了空字符，所以字符数组的大小比单词的字符数多一个。

```C
char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
char site[] = "RUNOOB"; // 简单初始化
```

常用操作：

- **strcpy(s1, s2);** 复制字符串 s2 到字符串 s1。
- **strcat(s1, s2);** 连接字符串 s2 到字符串 s1 的末尾。
- **strlen(s1);** 返回字符串 s1 的长度。
- **strcmp(s1, s2);** 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
- **strchr(s1, ch);** 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
- **strstr(s1, s2);** 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。


---

# 内存管理

C 语言为内存的分配和管理提供了几个函数。这些函数可以在<stdlib.h>头文件中找到。

- **void \*calloc(int num, int size);** 在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num\*size 个字节长度的内存空间，并且每个字节的值都是0。
- **void free(void \*address);** 该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
- **void \*malloc(int num);** 在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
- **void \*realloc(void \*address, int newsize);** 该函数重新分配内存，把内存扩展到 newsize。
