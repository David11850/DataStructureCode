# DataStructure-C-Implementation

本项目是基于 C 语言实现的基础数据结构与算法练习库，涵盖了软件工程专业大一至大二核心的数据结构知识点。

## 🚀 项目结构

本仓库采用多项目结构，每个文件夹对应一个独立的数据结构或算法实现：

### 1. 线性结构 (Linear Structures)
* **ArrayList**: 顺序表的实现
* **linkList**: 单链表
* **LinkLoopList / DoubleLoopLinkList**: 循环链表与双向循环链表
* **ArrayStack / LinkStack**: 栈的顺序存储与链式存储
* **ArrayQueue / LinkQueue**: 队列的顺序存储与链式存储

### 2. 树形结构 (Tree Structures)
* **BinaryTree**: 基础二叉树操作
* **ThreadedTree**: 线索二叉树
* **BinarySearchTree**: 二叉搜索树
* **avlTree**: 自平衡二叉搜索树 (AVL Tree)
* **Red_Black_Tree**: 红黑树实现
* **huffmanTree**: 哈夫曼树及编码

### 3. 图论算法 (Graph Theory)
* **matrixGraph / AdjacenceGraph**: 图的邻接矩阵与邻接表存储
* **Dijkstra**: 最短路径算法
* **prim / kruskal**: 最小生成树算法
* **topological sorting**: 拓扑排序
* **Keypath**: 关键路径分析

### 4. 搜索与排序 (Search & Sort)
* **find**: 基础查找算法
* **InsertSort**: 插入排序
* **SwapSort**: 交换排序（冒泡、快排等）
* **HeapSort**: 堆排序
* **mergeSort**: 归并排序
* **quickFind / quickUnino**: 并查集基础

## 🛠 开发环境
* **操作系统**: Windows 11 (WSL 2 Ubuntu 24.04 辅助测试)
* **IDE**: Visual Studio 2022 / 2026
* **语言标准**: C11 / C++ (部分测试文件)

## 🔨 如何编译
本项目使用 Visual Studio 解决方案管理。
1. 双击打开根目录下的 `DataStructure.sln`。
2. 在“解决方案资源管理器”中右键点击想要运行的项目。
3. 选择“设为启动项目”。
4. 按 `F5` 编译并运行。