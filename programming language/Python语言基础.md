# Python 语言基础（LeetCode 向）

Python 语法简洁、内置类型丰富，是 LeetCode 上常用的语言之一。下面按「刷题常用」组织：内置类型、控制流、函数与类、常用标准库。

## 基本语法与类型

- **整数与浮点**：`int` 任意精度，`float` 双精度。除法 `/` 为真除法，`//` 为整除，`%` 取余，`**` 幂。
- **布尔**：`True` / `False`，逻辑运算 `and`、`or`、`not`。
- **None**：表示空值，类似其他语言的 `null`。

## 字符串 str

- 单引号、双引号、三引号均可；支持切片 `s[i:j]`、`s[::-1]` 反转。
- 常用方法：`len(s)`、`s.split()`、`s.strip()`、`s.join(iterable)`、`s.find()`/`s.index()`、`s.replace()`、`s.startswith()`/`s.endswith()`。
- 不可变，拼接大量字符串时可用 `list` 收集再 `''.join()`。

## 列表 list

- 有序、可变、可重复。`a = []`、`a = [1,2,3]`、`a = [0]*n`。
- 索引与切片：`a[i]`、`a[-1]`、`a[i:j]`、`a[::2]`。
- 常用方法：`append(x)`、`extend(iterable)`、`insert(i,x)`、`pop([i])`、`remove(x)`、`reverse()`、`sort()`/`sorted(a)`。
- 列表推导：`[x*2 for x in a if x>0]`；二维初始化 `[[0]*m for _ in range(n)]`（不要用 `[[0]*m]*n`，会共享行）。

## 字典 dict 与集合 set

- **dict**：键值对，键不可变且不重复。`d = {}`、`d = {'a':1}`；`d[key]` 不存在会 KeyError，可用 `d.get(key, default)`；`d.keys()`、`d.values()`、`d.items()`；`key in d`。
- **set**：无序、不重复。`s = set()`、`s = {1,2,3}`；`add`、`remove`/`discard`、`in`。常用于去重、判存在，平均 O(1)。

## 元组 tuple

- 不可变有序序列。`t = (1,2)`、`t = 1,2`；多用于多返回值、哈希键、固定结构。

## 控制流

- **条件**：`if / elif / else`，注意冒号和缩进。
- **循环**：`for x in iterable:`；`for i in range(n):`（`range(start, end, step)`）；`while cond:`。
- **break**、**continue**；**else** 可与 `for`/`while` 搭配，表示「正常结束未 break」时执行。

## 函数与递归

- 定义：`def f(a, b=0):`；可变参数 `*args`、`**kwargs`。
- 返回值：`return x` 或 `return a, b`（实际返回元组）；无 return 则返回 `None`。
- 递归与 LeetCode：注意递归深度，必要时改迭代或显式栈。

## 类与对象

- 定义类：`class Node:`；构造函数 `def __init__(self, val=0, left=None, right=None):`。
- 实例属性：`self.xxx`；LeetCode 常用 `TreeNode`、`ListNode` 等已给出定义，直接使用即可。

## 常用标准库（刷题）

- **collections**：`deque` 双端队列（BFS、滑动窗口）、`defaultdict` 默认值字典、`Counter` 计数、`OrderedDict`（按插入序）。
- **heapq**：堆，`heapq.heapify(list)`、`heapq.heappush(h, x)`、`heapq.heappop(h)`，默认最小堆；最大堆可存 `(-x, x)`。
- **bisect**：二分查找与插入。`bisect_left(a, x)`、`bisect_right(a, x)`、`insort_left`/`insort_right`。
- **itertools**：`permutations`、`combinations`、`product`、`chain` 等，枚举与组合常用。
- **functools**：`lru_cache` 用于记忆化递归（如 DP、带缓存的 DFS）。

## 注意点

- 默认参数避免用可变对象：不要 `def f(a=[])`，用 `def f(a=None): a = a or []`。
- 深拷贝与浅拷贝：`list.copy()` 浅拷贝；嵌套结构需 `import copy; copy.deepcopy(x)`。
- 整数与字符串转换：`int(s)`、`str(n)`、`ord(c)`、`chr(n)`。
- LeetCode 中常用 `sys.stdin` 较少，直接实现所给函数接口即可。

## 高频题型对应库

- BFS/最短路：`collections.deque`；
- TopK/合并 K 路：`heapq`；
- 计数与分组：`Counter`、`defaultdict(list)`；
- 二分：`bisect_left`、`bisect_right`；
- 记忆化搜索：`@lru_cache(None)`。
