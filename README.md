# List

`yiming::list<T>` 是一个用于学习的循环双向链表实现，使用哨兵节点管理首尾链接。

## 功能特点

- 双向迭代器
- 在指定迭代器位置插入和删除元素
- 从头部或尾部插入、删除元素
- 初始化列表构造、拷贝构造和 copy-swap 赋值
- `clear()` 和 `size()`

## 构建与运行

本项目使用 Visual Studio 解决方案构建。请安装 Visual Studio 2019，并选择 **使用 C++ 的桌面开发** 工作负载，同时安装 MSVC v142 工具集和 Windows 10 SDK。

打开 `List.sln`，选择 **Debug | x64**，然后生成并运行 `List` 项目。控制台程序会先运行自定义链表的回归断言，再运行标准库链表示例。请使用 Debug 配置，以确保断言保持启用。

也可以在 Visual Studio 开发者命令提示符中执行：

```bat
msbuild List.sln /p:Configuration=Debug /p:Platform=x64
x64\Debug\List.exe
```

## 文件说明

- `List.h`：`yiming::list<T>` 实现及迭代器类型。
- `List_test.cpp`：回归断言和 `std::list` 示例。
- `List_sim_test.cpp`：自定义链表的补充用法示例；当前 Visual Studio 项目未将其纳入构建。

## 基本用法

```cpp
#include "List.h"

int main()
{
    yiming::list<int> values{ 1, 2, 3 };
    auto second = values.begin();
    ++second;
    auto next = values.erase(second);
    values.insert(next, 4);
}
```

`erase(pos)` 要求 `pos` 指向链表中的元素，不能传入 `end()`。对空链表调用 `pop_front()` 或 `pop_back()` 也不合法。

