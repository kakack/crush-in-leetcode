# C++ 语言基础（LeetCode 向）

C++ 支持 STL（标准模板库），容器和算法丰富，是 LeetCode 中兼顾效率与书写效率的常用语言。下面分块介绍：常用容器、字符串、迭代器与范围、常用算法及语法要点。

## 常用 STL 容器

### vector（动态数组）

- `vector<int> v;`、`vector<int> v(n);`、`vector<int> v(n, 0);`、`vector<int> v = {1,2,3};`
- 操作：`v.push_back(x)`、`v.pop_back()`、`v.size()`、`v.empty()`、`v[i]`、`v.front()`、`v.back()`、`v.resize(n)`、`v.clear()`。
- 注意：`v.size()` 为无符号类型，与有符号数比较时注意避免溢出，可强转 `(int)v.size()`。

### string（字符串）

- `string s;`、`string s("hello");`、`string s(n, 'c');`
- 操作：`s.size()`/`s.length()`、`s += t`、`s.push_back(c)`、`s[i]`、`s.substr(pos, len)`、`s.find(str)`、`s.empty()`。
- 与 C 互操作：`s.c_str()` 返回 `const char*`。

### map / set（有序）与 unordered_map / unordered_set（哈希）

- **map**：键值对，按键有序。`map<K,V> m;`、`m[key]=val`、`m.find(key)`、`m.count(key)`、`m.erase(key)`；遍历 `for (auto& [k,v] : m)` 或 `for (auto& p : m)`。
- **set**：有序不重复集合。`set<T> s;`、`s.insert(x)`、`s.count(x)`、`s.erase(x)`、`s.lower_bound(x)`、`s.upper_bound(x)`。
- **unordered_map / unordered_set**：基于哈希，平均 O(1) 查找/插入，LeetCode 中更常用。接口与 map/set 类似，但无 `lower_bound` 等有序操作。

### queue 与 stack

- **queue**：`queue<T> q;`、`q.push(x)`、`q.pop()`、`q.front()`、`q.back()`、`q.size()`、`q.empty()`。注意 `pop()` 无返回值。
- **stack**：`stack<T> stk;`、`stk.push(x)`、`stk.pop()`、`stk.top()`、`stk.size()`、`stk.empty()`。

### priority_queue（堆）

- 默认最大堆（大顶堆）。`priority_queue<int> pq;`、`pq.push(x)`、`pq.pop()`、`pq.top()`。
- 最小堆：`priority_queue<int, vector<int>, greater<int>> pq;`
- 自定义比较：`priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);` 或重载 `operator<`。

### pair 与 tuple

- `pair<int,int> p = {1,2};`、`p.first`、`p.second`；`make_pair(a,b)` 或 `{a,b}`。
- `tuple` 可用 `get<i>(t)` 访问，C++17 支持 `auto [a,b,c] = t;`。

## 迭代器与范围

-  begin/end：`v.begin()`、`v.end()`；`auto it = v.begin();`，`*it` 解引用，`it++`、`it--`。
- 范围 for：`for (int x : v)`、`for (auto& x : v)`（修改）、`for (const auto& x : v)`（只读）。
- 反向：`rbegin()`、`rend()`；或 `for (auto it = v.rbegin(); it != v.rend(); ++it)`。

## 常用算法（algorithm）

- **排序**：`sort(v.begin(), v.end())`、`sort(v.begin(), v.end(), cmp)`；`stable_sort` 稳定排序。
- **二分**：`lower_bound(begin, end, x)`、`upper_bound(begin, end, x)`、`binary_search(begin, end, x)`。在有序 vector 上常用。
- **其它**：`reverse(v.begin(), v.end())`、`next_permutation(v.begin(), v.end())`、`max_element`、`min_element`、`accumulate`、`swap(a,b)`。

## 语法要点

- **引用**：`int& r = x;` 引用绑定后不能改绑定；`const int&` 只读引用，避免拷贝。
- **auto**：`auto x = ...;` 由编译器推导类型；范围 for 中常用 `auto`/`auto&`。
- **nullptr**：空指针，替代 C 的 `NULL`。
- **struct/class**：LeetCode 常给出 `ListNode`、`TreeNode` 定义，直接使用；写构造函数时注意成员初始化列表。

## 与 C 的差异

- 输入输出：`cin`/`cout` 或 C 的 `scanf`/`printf`；LeetCode 通常只需实现函数，不要求读入。
- 内存：`new`/`delete` 或 `malloc`/`free`；使用 vector/string 等可避免手写内存管理。
- 头文件：常用 `#include <vector>`、`<string>`、`<unordered_map>`、`<queue>`、`<algorithm>` 等；`using namespace std;` 可简化书写（竞赛/刷题常见）。

## 小结

刷题时优先掌握：**vector、string、unordered_map、unordered_set、queue、stack、priority_queue**，以及 **sort、lower_bound、范围 for**。再根据需要补 **map/set、pair、算法库** 即可覆盖大部分题目。

## 高频题型对应容器

- 图与 BFS：`vector<vector<int>>` + `queue`；
- TopK 与最短路：`priority_queue`；
- 计数与映射：`unordered_map`、`unordered_set`；
- 区间/二分：`sort` + `lower_bound` / `upper_bound`；
- 回溯与构造：`vector` + 递归。
