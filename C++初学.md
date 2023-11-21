- 网课（黑马程序员）（共314节）：1，2，3，4，5，6，7，8，9，10，11，12，13，14，15，16，17，18，19，20，21，22，23，24，25，26，27，28，29，30，31，32，33，34，35，36，37，38，39，40，41，42，43，44，45，46，47，48，49，50，51，52，53，54，55，56，57，58，59，60，61，62，63，64，65，66，67，68，69，70，71，72，73，74，75，76，77，78，79，80，81，82，83，84，85，86，87，88，89，90，91，92，93，94，95，96，97，98，99，100，101，102
- 课程安排：
  - 第一阶段：C++基础入门，对C++有初步了解
    - 案例：通讯录管理系统
  - 第二阶段：C++核心编程，介绍C++面向对象编程，为大型项目做铺垫
    - 职工管理系统
  - 第三阶段：介绍C++泛型编程思想，以及STL的基本使用
    - 演讲比赛系统
  - 综合大案例：机房预约系统
- 注意事项：
  - 在typora中打开超链接的方式：Ctrl+鼠标左键点击


# 一.C++基础入门

## （一）.C++初识

### 1.第一个C++程序：

- 输出Hello World

- ```c++
  #include<iostream>
  using namespace std;
  
  int main()
  {
  	cout << "hello world" << endl;
  	system("pause");
  	return 0;
  }
  ```

### 2.注释

- 单行注释（通常放在一行代码上方，或一条语句末尾）

  - ```c++
    //单行注释
    ```

- 多行注释（通常放在一段代码上方）

  - ```c++
    /*
    多行注释
    */
    ```

### 3.变量

- 变量的作用：给一段指定的空间起名，方便操作这段内存
- 语法：`数据类型 变量名 = 初始值;`

### 4.常量

- 作用：用于记录程序中不可更改的数据

- C++定义常量的两种方法

  1. `#define 常量名 常量值`
     
  2. `const 数据类型 常量名 = 常量值`

### 5.关键字

- 再给变量或常量起名时，不得使用C++关键字

### 6.标识符命名规则

- 标识符不能是关键字
- 标识符只能由字母、数字、下划线组成
- 第一个字符必须为字母或下划线，不能是数字
- 标识符区分大小写
- 建议：给变量起名时，最好能见名知意

## （二）.数据类型

### 1.整形

| 数据类型            | 占用空间                                               |
| ------------------- | ------------------------------------------------------ |
| short(短整型)       | 2字节                                                  |
| int(整形)           | 4字节                                                  |
| long(长整型)        | Windows系统为4字节,Linux(32位)为4字节、（64位）为8字节 |
| long long(长长整形) | 8字节                                                  |

### 2.sizeof关键字

- 作用：统计数据类型所占内存大小
- 语法：`sizeof(数据类型/变量)`

### 3.实型（浮点型）

- 作用：表示小数
- 浮点型变量分两种：
  1. 单精度浮点型float（通常在float类型后加一个f），占用4个字节空间，7位有效数字
     - 科学计数法：
       - `float f=3e2;//3*10^2`
       - `float f=3e-2;//3*0.1^2`
  2. 双精度浮点型double，占用8个字节，15~16位有效数字
- 默认情况下，输出一个小数，会显示出六位有效数字

### 4.字符型

- 作用：显示单个字符
- 语法：`char ch = 'a';`
- C和C++中字符型变量只占用一个字节
- 字符型变量并不是把字符本身放到内存中存储，而是把对应的ASCll编码放到存储单元中
- 常见错误：
  - `char ch = "b";//创建字符型变量时，要用单引号`
  - `char ch = 'abc';//创建字符型变量时，单引号内只能有一个字符`
- 查看字符型变量对应的ASCll编码
  - `cout << (int)ch << endl;`
  - a - 97
  - A - 65
- ASCll编码
  - 非打印字符：**0~31**分配给了控制字符，用于控制打印机等外围设备
  - 打印字符：**32~126**分配给了能在键盘上找到的字符，当查看或打印文档时会出现

### 5.转移字符

- 作用：用于表示一些不能显示出来的字符
- 常用：
  - \n：换行
  - \\\：输出一个反斜杠\
  - \t：水平制表符（跳到下一个tab位置）

### 6.字符串型

- 作用：表示一串字符
- 两种风格：
  1. C语言风格字符串：`char 变量名[] = "字符串值"`
  2. C++风格字符串：`string 变量名 = "字符串值"`
     - 需要包含头文件`#include<string>`

### 7.布尔类型bool

- 作用：代表真或假的值
- bool类型只有两个值：
  - true---真（1）
  - false---假（0）
- bool类型只占1个字节大小
- 创建bool数据类型
  - `bool flag = true`
- 布尔类型，非0都是真

### 8.数据的输入

- 作用：用于从键盘获取数据

- 关键字：`cin`

- 语法：`cin >> 变量`

- 不同数据类型的输入

  1. 整形

     - ```c++
       int a = 0;
       cout << "请给整型变量a赋值" << endl;
       cin >> a;
       cout << "整型变量a = " << a << endl;
       ```

  2. 浮点型

     - ```c++
       float f = 3.14f;
       cout << "请给浮点型变量f赋值" << endl;
       cin >> f;
       cout << "浮点型变量f = " << f << endl;
       ```

  3. 字符型

     - ```c++
       char ch = 'a';
       cout << "请给字符型变量ch赋值" << endl;
       cin >> ch;
       cout << "字符型变量ch = " << ch << endl;
       ```

  4. 字符串型

     - ```c++
       string str = "abc";
       cout << "请给字符串型str赋值" << endl;
       cin >> str;
       cout << "字符串型str = " << str << endl;
       ```

  5. 布尔数据类型

     - ```c++
       bool flag = false;
       cout << "请给布尔类型flag赋值" << endl;
       cin >> flag;
       cout << "布尔类型flag = " << flag << endl;
       ```

## （三）.运算符

### 1.算术运算符

- +
- -
- *
- /
  - 除数不能为0
  - 两个整数相除仍然是整数
- %
  - 除数不能为0，也不能取模
  - 两个小数不能作取值运算
  - 只有整型变量可以作取模运算
- ++a
- a++
- --a
- a--

### 2.赋值运算符

- +=
- -=
- *=
- /=
- %=

### 3.比较运算符

- ==

- !=

- <

- >

- <=

- `>=`

### 4.逻辑运算符

- !		非
- &&    与
- ||       或

## （四）.程序流程结构

### 1.顺序结构

#### （1）if语句

- 作用：执行满足条件的语句

- if语句的三种格式：

  - 单行格式

    - ```c++
      if(条件)
      {
          条件满足的语句
      }
      ```

  - 多行格式

    - ```c++
      if(条件)
      {
          条件满足的语句
      }
      else
      {
          条件不满足的语句
      }
      ```

  - 多条件

    - ```c++
      if(条件1)
      {
          条件1满足后执行的语句
      }
      else if(条件2)
      {
          条件2满足后执行的语句
      }
      ...
      else
      {
          条件都不满足执行的语句
      }
      ```

- 嵌套if语句

#### （2）三目运算符

- 作用：通过三目运算符实现简单判断

- 语法：`表达式1 ？ 表达式2 ：表达式3`

- 解释：

  - 如果表达式1为真，执行表达式2，返回表达式2的结果
  - 如果表达式1为假，执行表达式3，返回表达式3的结果

- 在C++中三目运算符返回的是变量，可以继续赋值

  - ```c++
    int a = 10;
    int b = 20;
    int c = 0;
    (a < b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    ```

#### （3）switch语句

- 作用：执行多条件分支语句

- 语法：

  - ```c++
    switch(表达式)
    {
        case 结果1:
            执行语句;break;
        case 结果2:
            执行语句;break;
        ...
        default: 
            执行语句;break;
    }
    ```

- switch语句优缺点：

  - 缺点：判断是只能是整型或字符型，不可以是一个区间；
  - 优点：结构清晰，执行效率高

- 注意：case中如果没有break，程序会一直向下执行

### 2.循环结构

#### （1）while循环语句

- 语法：

  - ```c++
    while(循环条件)
    {
        循环语句
    }
    ```

- 注意：必须提供跳出循环的出口

- while循环练习案例：猜数字

  - 文件：[02.循环练习案例：猜数字.cpp](https://github.com/zzx051900/C-/blob/a6acf6b607c39e605b74af9503e11088bb27613e/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/2.%E5%BE%AA%E7%8E%AF%E7%BB%93%E6%9E%84%E6%A1%88%E4%BE%8B-%E7%8C%9C%E6%95%B0%E5%AD%97.cpp)

#### （2）do...while循环语句

- 语法：

  - ```c++
    do
    {
        循环语句
    }while(循环条件);
    ```

- 注意：与while的区别在于do...while会先执行一次循环语句，再判断条件

- 文件：[3.循环结构案例-水仙花数.cpp](https://github.com/zzx051900/C-/blob/a6acf6b607c39e605b74af9503e11088bb27613e/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/3.%E5%BE%AA%E7%8E%AF%E7%BB%93%E6%9E%84%E6%A1%88%E4%BE%8B-%E6%B0%B4%E4%BB%99%E8%8A%B1%E6%95%B0.cpp)

#### （3）for循环

- 语法：

  - ```c++
    for(起始表达式;条件表达式;末尾循环体)
    {
        循环语句
    }
    ```
  
- 文件：[4.循环结构案例-敲桌子.cpp](https://github.com/zzx051900/C-/blob/a6acf6b607c39e605b74af9503e11088bb27613e/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/4.%E5%BE%AA%E7%8E%AF%E6%A1%88%E4%BE%8B-%E6%95%B2%E6%A1%8C%E5%AD%90.cpp)



#### （4）嵌套循环

- 再循环里再嵌套一层循环

### 3.跳转语句

#### （1）break语句

- 作用：用于跳出选择循环或循环结构
- break使用的时机；
  - 出现在switch条件语句，终止case并跳出switch
  - 出现在循环语句，跳出当前循环
  - 出现在嵌套循环，跳出最内层的循环

#### （2）continue语句

- 在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

#### （3）goto语句

- 作用：无条件跳转语句
- 语法：
  - `goto 标记;`    
  - `标记：`

## （五）.数组

### 1.一维数组

#### （1）一维数组的定义方式

- 三种方式：

  1. `数据类型 数组名[数组长度];`

     - 全局数组，未初始化时，默认值都是 0

     - 局部数组，未初始化时，默认值为随机的不确定的值（-858993460）

  2. `数据类型 数组名[数组长度] = {值1,值2,...};`

     - 如果在数组初始化数据时，没有全部填写完，会用0来填补数据

  3. `数据类型 数组名[] = {值1,值2,...};`

     - 这种定义方式必须有初始长度

#### （2）一维数组的数组名

- 用途：
  1. 统计整个数组在内存中的长度
     - `sizeof(arr);//整个数组占用空间`
     - `sizeof(arr[0]);//每个元素所占内存空间`
     - `sizeof(arr)/sizeof(arr[0]);//数组中元素个数`
  2. 获取数组在内存中的首地址
     - `cout << arr <<endl;`
- 注意：数组名是常量，不可以赋值

#### （3）一维数组案例

1. 文件：[5.一维数组案例-寻找最大值.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/5.%E4%B8%80%E7%BB%B4%E6%95%B0%E7%BB%84%E6%A1%88%E4%BE%8B-%E5%AF%BB%E6%89%BE%E6%9C%80%E5%A4%A7%E5%80%BC.cpp)
2. 文件：[6.一维数组案例-数组元素逆置.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/6.%E4%B8%80%E7%BB%B4%E6%95%B0%E7%BB%84%E6%A1%88%E4%BE%8B-%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E9%80%86%E7%BD%AE.cpp)

#### （4）冒泡排序（升序）

- 算法思想：
  1. 比较相邻的元素，如果第一个比第二个大，就交换它们两个
  2. 对每一对相邻元素做相同工作，执行完毕后，找到第一个最大值
  3. 重复以上步骤，由于每次执行一轮会将目前最大值放在最后，所以每次执行次数减一，直到不需要比较
- 文件：[7.冒泡排序.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/7.%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F.cpp)

### 2.二维数组

#### （1）二维数组定义方式

- 四种方式：
  1. `数据类型 数组名[行数][列数];`
  2. `数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3,数据4}};`
  3. `数据类型 数组名[行数][列数] = {数据1,数据2,数据3,数据4};`
  4. `数据类型 数组名[][列数] = {数据1,数据2,数据3,数据4};`

#### （2）二维数组的数组名

- 作用：
  - 查看二维数组所占内存空间
    - `sizeof(arr);//二维数组占用空间`
    - `sizeof(arr[0]);//第一行所占内存空间`
    - `sizeof(arr)/sizeof(arr[0]);//二维数组行数`
    - `sizeof(arr[0])/sizeof(arr[0][0]);//二维数组列数`
    - `sizeof(arr)/sizeof(arr[0][0]);//数组中元素个数`
  - 查看二维数组首地址

## （六）.函数

### 1.函数的作用

- 将一段经常使用的代码封装起来，减少重复代码；一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能

### 2.函数的定义

- 五个步骤：

  1. 返回值类型
  2. 函数名
  3. 参数列表
  4. 函数体语句
  5. return表达式

- 语法：

  - ```c++
    返回时类型 函数名(参数列表)
    {
        函数体语句;
        return表达式
    }
    ```

### 3.函数的调用

- 功能：使用定义好的函数
- 语法：`函数名(参数)`

### 4.值传递

- 值传递，就是函数调用时，将实参传递给形参
- 值传递时，如果形参发生改变，并不会影响实参

### 5.函数的常见样式

- 四种：
  - 无参无返
  - 有参无返
  - 无参有返
  - 有参有返

### 6.函数声明

- 作用：告诉编译器函数名称及如何调用函数，函数的实际主体可以单独定义
- 函数的声明可以多次，但是函数的定义只有一次

### 7.函数的分文件编写

- 作用：让代码结构更加清晰
- 四个步骤：
  1. 创建后缀名为.h的头文件
  2. 创建后缀名为.cpp的源文件
  3. 在头文件中写函数的声明
  4. 在源文件中写函数的定义

## （七）.指针

### 1.指针的作用

- 作用：通过指针间接访问内存
- 内存编号从0开始记录，一般用十六进制表示
- 可以用指针变量保存地址

### 2.指针变量的定义和使用

- `指针定义的语法：数据类型 *指针变量名`

- ```c++
  int a = 10;
  int *p = &a;//指针p记录变量a的地址
  ```

- 使用指针：通过解引用的方式找到指针指向的内存；指针前加 * 表示解引用，找到指针指向的内存中的数据

- `*p = 100;`

### 3.指针所占内存空间

- 在32位操作系统下，占用4个字节
- 在64位操作系统下，占用8个字节

### 4.空指针和野指针

- 空指针：指针变量指向内存中编号为0的空间
  - 用途：初始化指针变量
  - 注意空指针指向的内存不可以访问（内存编号0~255为系统占用内存，不允许用户访问）
- 野指针：指针变量指向非法的内存空间
- 总结：空指针和野指针都不是我们要访问的空间，因此不要访问

### 5.const修饰指针

- 三种情况：

  1. const修饰指针 （常量指针）

     - ```c++
       const放在指针变量的*的左边时，修饰的是*p,也就是说，不能通过p改变*p的值    
           eg：const int *p=&num;        
       		*p=20;//不可以        
       		p=&n;//可以
       ```

     - 特点：指针的指向可以修改，但是指针指向的值不可以修改

  2. const修饰常量 （指针常量）

     - ```c++
       const放在指针变量*的右边时，修饰的是p本身，即p的地址无法改变    
           eg：int * const p=&num;       
       		*p=20;//可以       
       		p=&20;//不可以
       ```

     - 特点：指针的指向不可以修改，但是指针指向的值可以修改

  3. const既修饰指针，又修饰常量

     - ```c++
       const int * const p=&num;//此时内容和地址都不能更改
       ```

### 6.指针和数组

- 利用指针访问数组元素

- ```c++
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int *p = arr;
  cout << *p << endl;//输出数组第一个元素1
  p++;//指针向后偏移4个字节
  cout << *p << endl;//输出数组第二个元素2
  //遍历输出
  *p = arr;
  int sz = sizeof(arr)/sizeof(arr[0]);
  while(sz)
  {
      cout << *p <<endl;
      p++;
      sz--;
  }
  ```

### 7.指针和函数

- 作用：利用指针作函数参数，可以修改实参的值

- ```c++
  void swap(int* p1, int* p2)
      //这里的int* p1是表明p1是一个指针，也可写成int *p1，但这里的*p1不是解引用的意思，仅仅还是表明p1是一个指针
  {
  	int temp = 0;
  	temp = *p1;
  	*p1 = *p2;
  	*p2 = temp;
  }
  int main()
  {
  	int a = 10, b = 20;
  	cout << "a=" << a << endl;
  	cout << "b=" << b << endl;
  	swap(&a, &b);
  	cout << "a=" << a << endl;
  	cout << "b=" << b << endl;
  	system("pause");
  	return 0;
  }
  ```

### 8.指针、数组、函数

- 案例描述：封装一个函数，利用冒泡排序，实现对整型数组的排序
- 文件：[8.指针配合数组和函数案例-冒泡排序.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/8.%E6%8C%87%E9%92%88%E9%85%8D%E5%90%88%E6%95%B0%E7%BB%84%E5%92%8C%E5%87%BD%E6%95%B0%E6%A1%88%E4%BE%8B-%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F.cpp)

## （八）.结构体

### 1.结构体基本概念

- 结构体属于用户自定义数据类型，允许用户储存不同的数据类型

### 2.结构体定义和使用

- 语法：

  - ```c++
    struct 结构体名
    {
        结构体成员列表
    };
    ```

- 通过结构体创建变量的三种方式：

  1. `struct 结构体名 变量名;`（常用）
  2. `struct 结构体名 变量名 = {成员1值,成员2值,...};`（常用）
  3. `定义结构体时顺便创造变量`（少用）

- ```c++
  #include<iostream>
  #include<string>
  using namespace std;
  struct Student
  {
  	string name;
  	int age;
  	int score;
  }s3;
  int main()
  {
  	//第一种创建变量方式
  	struct Student s1;
  	s1.name = "aaa";
  	s1.age = 18;
  	s1.score = 100;
  	cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;
  	//第二种创建变量方式
  	struct Student s2 = { "bbb", 19, 90 };
  	cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 分数：" << s2.score << endl;
  	//第三种方式，定义结构体时顺便创造变量
  	s3.name = "ccc";
  	s3.age = 20;
  	s3.score = 95;
  	cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << endl;
  	system("pause");
  	return 0;
  }
  
  ```

- 注意：

  - 创建结构体变量的时候，关键字struct可以省略
  - 结构体变量用操作符"."访问成员

### 3.结构体数组

- 将自定义的结构体放入数组中方便维护

- 语法：

  - ```c++
    struct 结构体名 数组名[元素个数] = {{},{},...,{}};
    ```

- ```c++
  //1.定义结构体
  struct Student
  {
  	string name;
  	int age;
  	int score;
  };
  //2.创建结构体数组,并顺便给结构体数组中的元素赋值
  struct Student stuArr[] =
  {
      {"aaa",18,90},
      {"bbb",19,95},
      {"ccc",20,100}
  }
  //3.也可后续再给元素赋值
  stuArr[2].name = "ddd";
  stuArr[2].age = 21;
  stuArr[2].score = 85;
  //4.遍历结构体数组
  for(int i = 0;i < 3;i++)
  {
      cout << "姓名:" << stuArr[i].name
           << " 年龄:" << stuArr[i].age
           << " 分数:" << stuArr[i].score <<endl;
  }
  ```

### 4.结构体指针

- 作用：通过指针访问结构体中的成员

- 使用操作符`->`可以通过结构体指针访问结构体属性

- ```c++
  //1.定义结构体
  struct Student
  {
  	string name;
  	int age;
  	int score;
  };
  //2.创建结构体变量
  struct Student s = {"aaa",18,90};
  //3.通过指针指向结构体变量
  struct Student *p = &s;
  //4.通过指针访问结构体变量中的数据
  cout << "姓名:" << p->name
  	<< " 年龄:" << p->age
  	<< " 分数:" << p->score << endl;
  ```

### 5.结构体嵌套结构体

- 作用：结构体中的成员可以是另一个结构体

- ```c++
  struct Student
  {
  	string name;
  	int age;
  	int score;
  };
  struct Teacher
  {
      int id;
      string name;
      int age;
      struct Student stu;
  }
  //创建老师
  struct Teacher t;
  t.stu.name = "aaa";
  ```

### 6.结构体作函数参数

- 作用：将结构体作为参数向函数中传递

- 两种传递方式：

  - 值传递
  - 地址传递

- ```c++
  #include<iostream>
  #include<string>
  using namespace std;
  
  struct Student
  {
  	string name;
  	int age;
  	int score;
  };
  
  //输出结构体数组元素
  //值传递
  void printStu1(struct Student s)
  {
  	cout << "姓名:" << s.name
  		<< " 年龄:" << s.age
  		<< " 分数:" << s.score << endl;
  }
  
  //地址传递
  void printStu2(struct Student* p)
  {
  	cout << "姓名:" << p->name
  		<< " 年龄:" << p->age
  		<< " 分数:" << p->score << endl;
  }
  
  int main()
  {
  	struct Student s1;
  	s1.name = "aaa";
  	s1.age = 18;
  	s1.score = 100;
  
  	//值传递
  	printStu1(s1);
  
  	//地址传递
  	printStu2(&s1);
  	struct Student *p = &s1;
  	printStu2(p);
  	
  	system("pause");
  	return 0;
  }
  
  ```

- 总结：如果不想修改主函数中的数据，用值传递；反之用地址传递

### 7.结构体中const使用场景

- 作用：用const来防止误操作

- 将函数中的形参改为指针，可以减少内存空间，不会复制新的副本

  - 如果函数不需要修改结构体元素的值，在形参指针前加入const之后，一旦有修改的操作，就会报错，可以防止误操作

- ```c++
  //地址传递
  void printStu2(const struct Student* p)
  {
  	stu->age = 50;//会报错，操作失败
      cout << "姓名:" << p->name
  		<< " 年龄:" << p->age
  		<< " 分数:" << p->score << endl;
  }
  ```

### 8.结构体案例

- 案例1：
  - 案例描述：学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
    - 设计学生和老师的结构体，其中在老师的结构体中有老师的姓名和一个存放5名学生的数组作为成员
    - 学生的成员有姓名、考试分数
    - 创建数组存放3名老师，通过函数给每个老师及所带学生赋值
    - 最终打印出老师数据以及老师所带学生的数据
  - 文件：
    - [9.1结构体案例1（视频讲解版）.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/9.1%E7%BB%93%E6%9E%84%E4%BD%93%E6%A1%88%E4%BE%8B1%EF%BC%88%E8%A7%86%E9%A2%91%E8%AE%B2%E8%A7%A3%E7%89%88%EF%BC%89.cpp)
    - [9.2结构体案例1（改进版）.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/9.2%E7%BB%93%E6%9E%84%E4%BD%93%E6%A1%88%E4%BE%8B1%EF%BC%88%E6%94%B9%E8%BF%9B%E7%89%88%EF%BC%89.cpp)
- 案例2：
  - 案例描述：
    - 设计一个英雄的结构体，包括成员姓名，年龄，性别
    - 创建结构体数组，存放5名英雄
    - 通过冒泡排序，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果
  - 文件：[10.结构体案例2.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/10.%E7%BB%93%E6%9E%84%E4%BD%93%E6%A1%88%E4%BE%8B2.cpp)

# 一阶段案例：通讯录管理系统

## （一）系统需求

- 利用C++实现一个通讯录管理系统

- 需要实现的功能：

  - 添加联系人：向通讯录中添加新人，新人信息包括（姓名、性别、年龄、联系电话、家庭住址），最多记录1000人

  - 显示联系人：显示通讯录中所有联系人信息

  - 删除联系人：按照姓名进行删除指定联系人

  - 查找联系人：按照姓名查看指定联系人信息

  - 修改联系人：按照姓名重新修改指定联系人

  - 清空联系人：清空通讯录中所有信息
  - 退出通讯录：退出当前使用的通讯录

## （二）创建项目

- 创建一个C++项目（VS2013版本）

  1. 文件→新建→项目→visual C++→空项目     （Ctrl+Shift+N）
  2. 源文件（右键）→添加→新建项→C++文件   （Ctrl+Shift+A）

## （三）菜单功能

- 功能描述：用户选择功能的页面

- ```c++
  void menu()
  {
  	cout << "*************************" << endl;
  	cout << "******	1.添加联系人	******" << endl;
  	cout << "******	2.显示联系人	******" << endl;
  	cout << "******	3.删除联系人	******" << endl;
  	cout << "******	4.查找联系人	******" << endl;
  	cout << "******	5.修改联系人	******" << endl;
  	cout << "******	6.清空联系人	******" << endl;
  	cout << "******	0.退出通讯录	******" << endl;
  	cout << "*************************" << endl;
  }
  ```

## （四）退出功能

- 退出通讯录功能

- 思路：根据用户不同选择，进入不同功能，选择swich结构，选择0时退出

- ```c++
  int select = 0;//存放用户输入的选择
  	
  	while (1)
  	{
  		menu();//调用菜单
  		cin >> select;//用户输入选择
  		switch (select)
  		{
  		case 1:
  			break;//1.添加联系人
  		case 2:
  			break;//2.显示联系人
  		case 3:
  			break;//3.删除联系人	
  		case 4:
  			break;//4.查找联系人
  		case 5:
  			break;//5.修改联系人
  		case 6:
  			break;//6.清空联系人
  		case 0:
  			cout << "欢迎下次使用" << endl;
  			system("pause");//按任意键继续
  			return 0;
  			break;//0.退出通讯录
  		default:
  			break;
  		}
  ```

## （五）添加联系人

- 向通讯录中添加新人，新人信息包括（姓名、性别、年龄、联系电话、家庭住址），最多记录1000人

- 步骤：

  - 设计联系人结构体

    - 信息包括（姓名、性别、年龄、联系电话、家庭住址）

    - ```c++
      //联系人结构体
      struct Person
      {
      	string name;//姓名
      	int sex;//性别
      	int age;//年龄
      	string phone;//电话
      	string addr;//住址
      };
      ```

  - 设计通讯录结构体

    - 通讯录结构体，用于维护一个最大容量为1000人的联系人结构体数组，并记录当前通讯录中联系人数量

    - ```c++
      struct Addressbooks
      {
      	struct Person personArray[MAX];//联系人结构体类型的数组
      	int size;//通讯录中已添加人数
      };
      ```
  
  - main函数中创建通讯录
  
    - 添加联系人函数封装好后，在main函数中创建一个通讯录变量，这个变量就是我们需要一直维护的通讯录
  
    - ```c++
      Addressbooks abs;//创建通讯录结构体变量
      	abs.size = 0;//初始化通讯录中当前人数个数
      ```
  
  - 封装添加联系人功能
  
    - 添加联系人前先判断通讯录是否已满，若满了则不再添加；若未满则将新联系人信息逐个加入通讯录
  
    - ```c++
      //添加联系人
      void addPerson(Addressbooks* abs)
      {
      	//先判断通讯录是否已满
      	if (abs->size == MAX)
      	{
      		cout << "通讯已满，无法添加" << endl;
      		return;
      	}
      	//姓名
      	cout << "请输入姓名" << endl;
      	cin >> abs->personArray[abs->size].name;//这里的访问方式有点疑惑；数组下标即为已有联系人个数
      	//性别
      	cout << "请输入性别" << endl;
      	cout << "1 --- 男" << endl;
      	cout << "2 --- 女" << endl;
      	while (1)//需要循环输入判断，直到输入正确(1或2）
      	{
      		int sex = 0;
      		cin >> sex;
      		if (sex == 1 || sex == 2)
      		{
      			abs->personArray[abs->size].sex = sex;
      			break;
      		}
      		else
      		{
      			cout << "输入有误，请重新输入" << endl;
      		}
      	}
      	//年龄
      	cout << "请输入年龄" << endl;
      	while (1)//需要循环输入判断，直到输入正确(大于0且小于等于150）
      	{
      		int age = 0;
      		cin >> age;
      		if (age > 0 && age <= 150)
      		{
      			abs->personArray[abs->size].age = age;
      			break;
      		}
      		else
      		{
      			cout << "输入有误，请重新输入" << endl;
      		}
      	}
      	//电话
      	cout << "请输入电话" << endl;
      	cin >> abs->personArray[abs->size].phone;
      	//家庭住址
      	cout << "请输入家庭住址" << endl;
      	cin >> abs->personArray[abs->size].addr;
      	abs->size++;	//已有联系人数量加1
      	cout << "添加成功" << endl;
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```
  
  - 测试添加结构体功能
  
    - ```c++
      case 1:
      			addPerson(&abs);//添加联系人
      			break;
      ```

## （六）显示联系人

- 功能描述：显示通讯录中全部已有联系人信息

- 步骤：

  - 封装显示联系人函数
    - 判断当前通讯录中有没有人员，若人员为0，则提示记录为空；若人数大于0，则显示联系人信息
    
    - ```c++
      void showPerson(Addressbooks* abs)//可以用值传递，但浪费空间，所以用地址传递；是不是用const修饰更好？
      {
      	if (abs->size == 0)
      	{
      		cout << "记录为空" << endl;
      	}
      	for (int i = 0; i < abs->size; i++)
      	{
      		cout << "姓名：" << abs->personArray[i].name << "\t";
      		cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";//使用了一个3目运算符，若为1，则输出男；不为1，则输出女
      		cout << "年龄：" << abs->personArray[i].age << "\t";
      		cout << "电话：" << abs->personArray[i].phone << "\t";
      		cout << "住址：" << abs->personArray[i].addr << "\t";
      	}
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```
    
  - 测试显示联系人函数

    - ```c++
      case 2:
      			showPerson(&abs);//2.显示联系人
      			break;
      ```

## （七）删除联系人

- 功能描述：按照姓名进行删除指定联系人

- 步骤：

  - 封装检测联系人是否存在（为什么要单独封装一个检测功能？因为这个功能会多个函数经常重复用到）

    - 先判断用户输入的联系人是否存在，如果存在则返回联系人在通讯录的位置；不存在则返回-1

    - 注意："控制传输跳过的实例化"，cese语句中若需要实例化对象，则需要将这段case语句中的代码用大括号括起来

    - ```c++
      //检测联系人是否存在
      int isExist(Addressbooks* abs,string name)
      {
      	for (int i = 0; i < abs->size; i++)
      	{
      		if (abs->personArray[i].name == name)
      		{
      			return i;//找到了，返回联系人数组下标
      		}
      		return -1;//如果遍历结束都没有找到，则返回-1
      	}
      }
      ```

  - 封装删除联系人函数

    - ```c++
      void deletePerson(Addressbooks* abs)
      {
      	cout << "请输入您要删除的联系人" << endl;
      	string name;
      	cin >> name;
      	int ret = isExist(abs, name);//这里的abs已经是指针类型，不需要再取地址
      	if (ret == -1)
      	{
      		cout << "查无此人" << endl;
      	}
      	else
      	{
      		//将要删除联系人后面的联系人信息依次前移，最后联系人数量减一
      		for (int i = ret; i < abs->size; i--)
      		{
      			abs->personArray[i] = abs->personArray[i + 1];//可以直接将整个联系人结构体赋过去
      		}
      		abs->size--;
      		cout << "删除成功" << endl;
      	}
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```

  - 测试删除联系人功能
  
    - ```c++
      case 3:
      			deletePerson(&abs);//3.删除联系人	
      			break;
      ```

## （八）查找联系人

- 功能描述：按照姓名查找联系人并输出其全部信息

- 步骤：

  - 封装查找联系人函数

    - ```c++
      void findPerson(Addressbooks* abs)
      {
      	cout << "请输入您要查找的联系人" << endl;
      	string name;
      	cin >> name;
      	//检测联系人是否存在
      	int ret = isExist(abs, name);
      	if (ret == -1)
      	{
      		cout << "查无此人" << endl;
      	}
      	else
      	{
      		cout << "找到了该联系人，信息如下：" << endl;
      		cout << "姓名：" << abs->personArray[ret].name << "\t";
      		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";//使用了一个3目运算符，若为1，则输出男；不为1，则输出女
      		cout << "年龄：" << abs->personArray[ret].age << "\t";
      		cout << "电话：" << abs->personArray[ret].phone << "\t";
      		cout << "住址：" << abs->personArray[ret].addr << "\t";
      	}
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```

  - 测试查找联系人功能
  
    - ```c++
      case 4:
      			findPerson(&abs);//4.查找联系人
      			break;
      ```

## （九）修改联系人

- 功能描述：按照姓名重新修改指定联系人

- 步骤：

  - 封装修改联系人函数

    - 查找用户输入的联系人，如果查找成功则进行修改；查找失败则提示查无此人

    - ```c++
      void modifyPerson(Addressbooks* abs)
      {
      	cout << "请输入您要删除的联系人" << endl;
      	string name;
      	cin >> name;
      	//检测联系人是否存在
      	int ret = isExist(abs, name);
      	if (ret == -1)
      	{
      		cout << "查无此人" << endl;
      	}
      	else
      	{
      		//姓名
      		cout << "请输入修改后的姓名" << endl;
      		cin >> abs->personArray[abs->size].name;//这里的访问方式有点疑惑；数组下标即为已有联系人个数
      		//性别
      		cout << "请输入修改后的性别" << endl;
      		cout << "1 --- 男" << endl;
      		cout << "2 --- 女" << endl;
      		while (1)//需要循环输入判断，直到输入正确(1或2）
      		{
      			int sex = 0;
      			cin >> sex;
      			if (sex == 1 || sex == 2)
      			{
      				abs->personArray[abs->size].sex = sex;
      				break;
      			}
      			else
      			{
      				cout << "输入有误，请重新输入" << endl;
      			}
      		}
      		//年龄
      		cout << "请输入修改后的年龄" << endl;
      		while (1)//需要循环输入判断，直到输入正确(大于0且小于等于150）
      		{
      			int age = 0;
      			cin >> age;
      			if (age > 0 && age <= 150)
      			{
      				abs->personArray[abs->size].age = age;
      				break;
      			}
      			else
      			{
      				cout << "输入有误，请重新输入" << endl;
      			}
      		}
      		//电话
      		cout << "请输入修改后的电话" << endl;
      		cin >> abs->personArray[abs->size].phone;
      		//家庭住址
      		cout << "请输入修改后的家庭住址" << endl;
      		cin >> abs->personArray[abs->size].addr;
      	}
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```

  - 测试修改联系人功能
  
    - ```c++
      case 5:
      			modifyPerson(&abs);//5.修改联系人
      			break;
      ```

## （十）清空联系人

- 功能描述：清空通讯录中所有联系人

- 步骤：

  - 封装清空联系人函数

    - 只需要把通讯录的联系人数量置为0即可，逻辑清空

    - ```c++
      void clearPerson(Addressbooks* abs)
      {
      	abs->size = 0;
      	cout << "通讯录以清空" << endl;
      	system("pause");//请按任意键继续
      	system("cls");//清屏操作
      }
      ```

  - 测试清空联系人功能
  
    - ```c++
      case 6:
      			{
      				cout << "请确认是否要清空全部联系人\n 0 --- 取消\n 1 --- 确认" << endl;
      				int cle = 0;
      				cin >> cle;
      				if (cle == 1)
      				{
      					clearPerson(&abs);//6.清空联系人
      				}
      				else
      				{
      					cout << "欢迎下次使用" << endl;
      					system("pause");//按任意键继续
      				}
      				break;
      			}
      ```

## （十一）完整文件：

- 11.[C++学习一阶段案例：通讯录管理系统.cpp](https://github.com/zzx051900/C-/blob/a39f5c2707dd177f4d6719720c9eadf0d43ca457/C%2B%2B%E7%A8%8B%E5%BA%8F%E7%BB%83%E4%B9%A0%E4%BB%A3%E7%A0%81/11.C%2B%2B%E5%AD%A6%E4%B9%A0%E4%B8%80%E9%98%B6%E6%AE%B5%E6%A1%88%E4%BE%8B%EF%BC%9A%E9%80%9A%E8%AE%AF%E5%BD%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F.cpp)



# 二.C++核心编程

- 本阶段主要针对C++面向对象编程技术做详细讲解，探讨C++中的核心精髓

## （一）内存分区模型

- 内存四区：
  - C++程序在执行时，将内存大方向划分为四个区域：
    - 代码区：存放函数体的二进制代码，由操作系统进行管理
    - 全局区：存放全局变量和静态变量以及常量
    - 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
    - 堆区：由程序员分配和释放，若程序员不释放，程序结束时由系统回收
  - 内存四区的意义：不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程

###  1.程序运行前

- 在程序编译后，生成了exe可执行程序，未执行前分为两个区域：
  - 代码区：
    - 存放CPU执行的机器指令
    - 代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
    - 代码区是**只读**的，只读的原因是防止程序意外修改了它的指令
  - 全局区：
    - 全局变量和静态变量存放在此
    - 全局区还包含了常量区、字符串常量和其他常量也存放在此，包括const修饰的全局变量（全局常量）
    - 该区域的数据在程序结束后由操作系统释放
    - 局部变量、const修饰的局部变量（局部常量）都不在全局区

### 2.程序运行后

#### 栈区：

- 由编译器自动分配释放，存放函数的参数值（函数的形参数据），局部变量等

- 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

  - 若返回局部变量的地址，用指针接收，在主函数中解引用输出：
    - 第一次可以正确打印，是因为编译器做了保留
    - 第二次打印这个数据就不再保留，会输出一段随机值

  - 所以不要使用这种操作

- ```c++
  int* func()
  {
      int a = 10;
      return &a;
  }
  int main()
  {
      int *p = func();
      cout << *p << endl;//第一次可以正确打印，是因为编译器做了保留
      cout << *p << endl;//第二次打印这个数据就不再保留，会输出一段随机值
      system("pause");
      return 0;
  }
  ```

#### 堆区：

- 由程序员分配和释放，若程序员不释放，程序结束时由系统回收；在C++中主要利用new在堆区开辟内存

- ```c++
  int* p = new int(10);
  ```

### 3.new操作符

- C++中呢哇操作符在堆区开辟空间

- 堆区开辟的数据，由程序员手动开辟，手动释放，利用操作符delete

  - ```c++
    //释放
    delete p;
    ```

- 语法：`new 数据类型`

- 利用new创建的数据，会返回该数据对应的类型的指针

  - 用new创建一个整形变量

    - ```c++
      int* p = new int(10);//10代表这个整形变量现在赋的初值
      ```

  - 用new创建一个整形数组

    - ```c++
      int* arr = new int[10];//10代表数组有10个元素
      //释放数组时
      delete[] arr;
      ```

    - 

## （二）引用

###  1.引用的基本使用

- 作用：给变量起别名

- 语法：`数据类型 &别名 = 原名`

- 示例：

  - ```c++
    int a = 10;
    int &b = a;
    cout << a << endl;
    cout << b << endl;
    b = 20;
    cout << a << endl;
    cout << b << endl;
    ```

###  2.引用注意事项

- 引用必须初始化

- 引用在初始化之后，不可以改变

- 示例：

  - ```c++
    int a = 10;
    int &b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    //int &b;//非法，“需要初始值设定项”
    int c = 20;
    //int &b = c;//非法，“多次初始化”
    b = c;//同时将a的值也改变了，所以引用在初始化后不可以改变
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    ```

###  3.引用作函数参数

- 作用：函数传参时，可以用引用的技术让形参修饰实参

- 优点：可以简化指针修改实参

- 示例：

  - ```c++
    void swap(int &a, int &b)
    {
    	int temp = a;
    	a = b;
    	b = temp;
    }
    
    int main()
    {
    	int a = 10;
    	int b = 20;
    	swap(a, b);
    	cout << "a = " << a << endl;//20
    	cout << "b = " << b << endl;//10
    	system("pause");
    	return 0;
    }
    ```

- 总结：通过引用参数产生的效果和按地址传递是一样的，引用的语法更简单

###  4.引用作函数返回值

- 引用是可以作为函数的返回值的

- 注意：不要返回局部变量引用

  - 类似于不要返回局部变量的地址

- 用法：函数调用作为左值

  - ```c++
    int& test()
    {
    	static int a = 10;
    	return a;
    }
    
    int main()
    {
    	int &ref = test();
    	cout << "ref = " << ref << endl;
    	cout << "ref = " << ref << endl;
    	test() = 100;//相当于"a = 100"
    	cout << "ref = " << ref << endl;
    	system("pause");
    	return 0;
    }
    ```

###  5.引用的本质

- 本质：引用的本质在C++内部实现是一个**指针常量**

- ```c++
  //发现是引用，转换为 int* const ref = &a;
  void func(int& ref)
  {
  	ref = 100;// ref是引用，转换为 *ref = 100
  }
  
  int main()
  {
  	
  	int a = 10;
  	int &ref = a;//自动转换为 int * const ref = &a;指针常量是指针指向不可更改(但指针指向内存空间的值可以更改），也说明了引用为什么不可以更改
  	ref = 20;//内部发现ref是引用，自动转换为：*ref = 20;
  	cout << "a = " << a << endl;
  	cout << "ref = " << ref << endl;
  	system("pause");
  	return 0;
  }
  ```

- 总结：C++推荐用引用技术，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了

###  6.常量引用

- 作用：常量引用主要用来修饰形参，方式误操作

  - 在函数形参列表中，可以加const修饰形参，防止形参改变实参

  - ```c++
    int a = 10;
    int &ref = 10;//非法的，引用必须引一块合法的内存空间
    const int &ref = 10;//合法，因为加上const后，编译器会将这句代码改为int temp = 10;const int &ref = temp;
    //加入const后变为只读，不可以修改	
    ```

## （三）函数提高

###  1.函数的默认参数

- 在C++中，函数的型参是可以有默认值的

- 语法：`返回值类型 函数名(参数 = 默认值)`

- 注意：

  - 如果我们自己传入数据，就用自己的数据，如果没有，就用默认值

  - 如果某个位置已经有了默认参数，那么从这个位置从左向右都必须有默认值

    - ```c++
      //错误案例:
      int func(int a, int b = 20, int c)
      {
      	return a + b + c;
      }
      ```

  - 如果函数声明有默认参数，函数实现不能有默认参数（声明和实现只能有一个默认参数

    - ```c++
      //错误案例：
      //函数声明
      int func(int a = 10,int b = 20);
      //函数实现
      int func(int a = 10,int b = 20)
      {
          return a + b;
      }
      //报错：重定义默认参数
      ```

- 示例：

  - ```c++
    //如果我们自己传入数据，就用自己的数据，如果没有，就用默认值
    int func(int a, int b = 20, int c = 30)
    {
    	return a + b + c;
    }
    int main()
    {
    	cout << func(10) << endl;//60
    	cout << func(10, 30) << endl;//70
    	
    	system("pause");
    	return 0;
    }
    ```

###  2.函数的占位参数

- C++中函数的形参列表可以有占位参数，用来作占位，调用函数时必须填补该位置

- 语法：`返回值类型 函数名(数据类型)`

- 占位参数，还可以有默认参数

- 示例：

- ```c++
  void func(int a, int)
  {
  	cout << "func" << endl;
  }
  
  int main()
  {
  	func(10,20);
  
  	system("pause");
  	return 0;
  }
  ```

###  3.函数重载

#### （1）概述：

- 作用：函数名可以相同，提高复用性

- 函数重载满足条件：

  - 同一个作用域下
  - 函数名称相同
  - 函数参数类型不同，或者个数不同，或者顺序不同

- 注意：函数的返回值不可以作为函数重载的条件（无法重载只按返回值类型区分的函数）

- 示例：

  - ```c++
    void func()
    {
    	cout << "func的调用1" << endl;
    }
    void func(int a)
    {
    	cout << "func的调用2" << endl;
    }
    void func(double a)
    {
    	cout << "func的调用3" << endl;
    }
    void func(int a, double b)
    {
    	cout << "func的调用4" << endl;
    }
    void func(double a, int b)
    {
    	cout << "func的调用5" << endl;
    }
    
    int main()
    {
    	func();
    	func(10);
    	func(3.14);
    	func(10, 3.14);
    	func(3.14, 10);
    
    	system("pause");
    	return 0;
    }
    ```

#### （2）函数重载注意事项

- 引用作为重载条件

  - ```c++
    void func(int &a)
    {
    	cout << "func(int &a)的调用" << endl;
    }
    void func(const int &a)
    {
    	cout << "func(const int &a)的调用" << endl;
    }
    
    int main()
    {
    	int a = 10;
    	func(a);
    	func(10);//int &a = 10;不合法   但const int &a = 10;合法
    	
    	system("pause");
    	return 0;
    }
    ```

- 函数重载遇到函数默认参数

  - ```c++
    void func(int a)
    {
    	cout << "func(int a)的调用" << endl;
    }
    void func(int a, int b = 10)
    {
    	cout << "func(int a,int b = 10)的调用" << endl;
    }
    
    int main()
    {
    	
    	func(10);//报错；当函数重载碰到默认参数，可能出现二义性报错，要尽量避免
    	func(10, 20);//正常运行
    	
    	system("pause");
    	return 0;
    }
    ```

## （四）类和对象

- C++面向对象三大特性：封装、继承、多态
- C++认为万事万物都皆为对象，对象上有其属性和行为
  - 人可以作为对象，属性：姓名、年龄、身高、体重...，行为：走、跑、跳、吃饭、唱歌
  - 车可以作为对象，属性：轮胎、方向盘、车灯...，行为：载人、放音乐、用空调
- 具有相同性质的对象，我们可以将其抽象为类，人属于人类、车属于车类

### 1.封装

#### （1）封装的意义

- 封装的意义：

  1. 将属性和行为作为一个整体，表现生活中的事物

  2. 将属性和行为加以权限控制

##### 封装的意义1：

  - 在设计类的时候，将属性和行为作为一个整体，表现生活中的事物

  - 语法：

    - ```c++
      class 类名
      { 
          //访问权限：
          //属性:
          //行为（函数）:
      };
      ```

    - 类中的属性和行为，统一称为**成员**

    - 属性，也称为成员属性、成员变量

    - 行为，也称为成员函数，成员方法

  - 示例1：设计一个圆类，求圆的周长

    - ```c++
      #include<iostream>
      #include<string>
      using namespace std;
      
      //设计一个圆类，求圆的周长
      
      const double PI = 3.14;//圆周率
      
      class Circle	//定义圆类
      {
      	//访问权限:
      	//公共权限
      public:
      
      	//属性:
      	int m_r;//半径
      
      	//行为（函数）:
      	double calculateZC()//计算圆的周长
      	{
      		return 2 * PI * m_r;
      	}
      };
      
      int main()
      {	
      	Circle c1;//通过圆类，创建（实例化）一个具体的圆（对象）
      	c1.m_r = 10;//给圆对象的属性赋值，半径赋值10
      	cout << "圆的周长为" << c1.calculateZC() << endl;//调用类的行为（函数）
      
      	system("pause");
      	return 0;
      }
      ```

  - 示例2：设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

    - ```c++
      #include<iostream>
      #include<string>
      using namespace std;
      //学生类
      class Student
      {
      //访问权限
      public:	//公共权限
      	//属性:
      	string m_Name;//姓名
      	int m_Id;//学号
      	//行为：
      	//展示学号和姓名
      	void showStudent()
      	{
      		cout << "姓名：" << m_Name << " 学号：" << m_Id << endl;
      	}
      	//给姓名赋值
      	void setName(string name)
      	{
      		m_Name = name;
      	}
      	//给学号赋值
      	void setId(int id)
      	{
      		m_Id = id;
      	}
      };
      int main()
      {
      	//创建一个具体的学生（实例化）
      	Student s1;
      	//s1进行属性赋值
      	s1.m_Id = 1;
      	s1.m_Name = "aaa";
      	//显示学生信息
      	s1.showStudent();
      	//将s1的名字和学号更改
      	s1.setName("bbb");
      	s1.setId(2);
      	s1.showStudent();
      	system("pause");
      	return 0;
      }
      ```

##### 封装的意义2：

- 类在设计时，可以把属性和行为放在不同的权限下，加以控制

- 访问权限有三种：

  - 公共权限：public（成员类内可以访问，类外可以访问）
  - 保护权限：protected（成员类内可以访问，类外不可以访问（儿子可以访问父亲中的保护内容））
  - 私有权限：private（成员类内可以访问，类外不可以访问（儿子不可以访问父亲中的隐私内容））

- 示例：

- ```c++
  #include<iostream>
  #include<string>
  using namespace std;
  class Person
  {
  public:	//公共权限
  	string m_Name;//姓名
  protected:	//保护权限
  	string m_Car;//汽车
  private:	//私有权限
  	string m_Password;//个人密码
  public:
  	void func()
  	{
  		m_Name = "aaa";
  		m_Car = "拖拉机";
  		m_Password = "123456";
  		//三种权限都可在类内正常访问
  	}		
  };
  int main()
  {
  	Person p1;
  	p1.m_Name = "bbb";
  	//p1.m_Car = "自行车";//保护权限，类外不可访问（报错：成员已声明，不可访问。）
  	//p1.m_Password = "111111";//私有权限，类外不可访问（报错：成员已声明，不可访问。）
  
  	system("pause");
  	return 0;
  }
  ```

####  （2）struct和class的区别

- 在C++中struct和class唯一的区别就在于**默认的访问权限不同**

- 区别：

  - struct默认权限为公共
  - class默认权限为私有

- ```c++
  class C1
  {
  	int m_A;	//默认权限为私有
  };
  struct C2
  {
  	int m_A;	//默认权限为公共
  };
  int main()
  {
  	C1 c1;
  	//c1.m_A = 100;//报错；因为私有变量在类外不可以访问
  	C2 c2;
  	c2.m_A = 100;//正常
  	system("pause");
  	return 0;
  }
  ```

#### （3）成员属性设置为私有

- 成员设置为私有的优点：

  1. 将所有成员设置为私有，可以自己控制读写权限
  2. 对于写权限，我们可以检测数据的有效性

- ```c++
  ```

- 

### 2.对象的初始化和清理

### 3.C++对象模型和this指针

### 4.友元

### 5.运算符重载

### 6.继承

### 7.多态

## （五）文件操作

