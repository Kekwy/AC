# AC

> 自己进行刷题练习时的一些题解

## 笔记

静态区间和选择前缀和，动态区间和选择线段树。

快速判断一个元素是否出现集合里的时候，就要考虑哈希法；

剑指 Offer 57 - II：vector 的部分拷贝；

看到「最大化最小值」或者「最小化最大值」就要想到**二分查找**，这是一个固定的套路;

- Java 可用 `Character.isDigit` 方法判断字符是否为数字。

https://leetcode.cn/problems/subtree-of-another-tree/solutions/233896/ling-yi-ge-shu-de-zi-shu-by-leetcode-solution/
深度优先加左右子树空值的前中后序遍历可以唯一确定一个二叉树。

https://programmercarl.com/0222.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
对于完全二叉树应用分治法

list.stream().mapToInt(Integer::intValue).toArray();

前缀树

指向子节点的指针数组 children\textit{children}children。对于本题而言，数组长度为 262626，即小写英文字母的数量。此时
children[0]\textit{children}[0]
children[0] 对应小写字母 aaa，children[1]\textit{children}[1]children[1] 对应小写字母 bbb，…，children[25]
\textit{children}[25]
children[25] 对应小写字母 zzz。
布尔字段 isEnd\textit{isEnd}isEnd，表示该节点是否为字符串的结尾。

LinkedList 中有 removeLast 方法，而 List 接口中没有。

https://leetcode.cn/problems/subsets-ii/

树层剪枝与树枝剪枝

List 设置容量
List<List\<Integer>> edgeList = new ArrayList<>(123);

List 初始化
https://blog.csdn.net/qq_39101581/article/details/88393876

List<List\<Integer>> edgeList = new ArrayList<>(Collections.nCopies(n, new ArrayList<>())); 注意，此处复制的是指针（浅拷贝）

当使用邻接矩阵超出内存限制时，可以考虑使用邻接表。

private final Random random; 不要在使用随机数的地方反复创建 random 对象，可能会导致每次调用方法返回的随机数相同，应当对提前创建好的同一个
random 对象多次调用 nextInt 方法；

将负数转化为正数的处理方法：https://leetcode.cn/problems/find-the-k-sum-of-an-array/

三大余数定理：https://www.cnblogs.com/TWS-YIFEI/p/5771586.html

对于大数处理时，应尽量减少不必要的以和形式出现的中间值（减少加法运算）

List<int[]> res = new ArrayList<>();

return res.toArray(new int[0][]);

对比字符串：

(a, b)-> a.get(1).compareTo(b.get(1))

Comparator.comparing(a -> a.get(1))

TreeMap 自动排序，linkedHashMap 保留插入顺序

Iterator iter = map.entrySet().iterator();

背包问题与完全背包问题再进一步加深一下理解。

https://programmercarl.com/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.html#%E6%80%9D%E8%B7%AF

股票系列主打一个“状态”！

最大矩形和接雨水需要体会一下。

## MySQL:

各种连表仔细体会一下

尽量使用 JOIN 而不是笛卡尔积（需要手动 UNION），同时注意处理源数据表中在外部关联表中没有对应记录的情况（根据题目表述赋值）

mod(x, 2)

avg(x)

count: https://blog.csdn.net/Chenftli/article/details/92411239

count 带条件：https://blog.csdn.net/Baby_lucy/article/details/120747237

有 null 参与的表达式，其计算结果为 null

日期处理：

- 选取日期中的年月：https://blog.csdn.net/weixin_43697585/article/details/109620585
- 分组：https://blog.csdn.net/qq_24909089/article/details/94467001
- 需要了解其中的含义：'%Y-%m'
- DATEDIFF(x, y): x 比 y 晚多少天
- 关于日期的常用函数：https://blog.csdn.net/sinat_28505133/article/details/75088451

排序：

- 返回指定列数据最小的行：ORDER BY xxx LIMIT 1;

COUNT(DISTINCT xxx)：可以直接计算指定列中不同值的数量。

分类之后进行筛选：

```sql
GROUP BY class
HAVING COUNT(student) >= 5
```

COALESCE() 函数

UNION 与 UNION ALL

WITH: https://blog.csdn.net/u010520724/article/details/106498870

连续 n：https://leetcode.cn/problems/consecutive-numbers/solutions/675274/mysql-jie-fa-tong-jie-ren-yi-lian-xu-nwe-hxg4/?envType=study-plan-v2&envId=sql-free-50

OVER（PARTITION BY：https://blog.csdn.net/weixin_45003816/article/details/103721121

遇到需要保留 NULL 值的情况，想连表

MySQL CTE: Common table expression https://zhuanlan.zhihu.com/p/103180385

当过程中带有乘法且目标是得到余数的中间值过大时，可以考虑利用同余减小中间值的大小而不影响最终得到的余数。

同余：(a × 10 + b) mod m = (a mod m × 10 + b) mod m

开窗+自连接：https://leetcode.cn/problems/last-person-to-fit-in-the-bus/solutions/229666/zui-hou-yi-ge-neng-jin-ru-dian-ti-de-ren-by-leetco/?envType=study-plan-v2&envId=sql-free-50

CASE WHEN：https://blog.csdn.net/helloxiaozhe/article/details/78124138

- -- ON i1.tiv_2015 = i2.tiv_2015

  -- ON i1.pid <> i2.pid AND i1.tiv_2015 = i2.tiv_2015

注意读题，留意题目中需要输出的列名，以及按什么排序。

rank：1 2 2 4（而非 1 2 2 3）

SUBSTRING(column_name, start, length)：这将从列的值中提取一个子字符串，从指定的起始位置开始，直到指定的长度。

UPPER(expression)：这会将字符串表达式转换为大写。

LOWER(expression)：这会将字符串表达式转换为小写。

CONCAT(string1, string2, ...)：这会将两个或多个字符串连接成一个字符串。

正则表达式：

单词边界 \b

在正则表达式中，\b 是一个特殊的元字符，表示单词边界。它匹配一个单词的开始或结束的位置，而不匹配任何实际的字符。

具体来说，\b 匹配以下三种情况之一：

- 单词的开头：如果 \b 出现在一个字母或数字之前，或者在字符串的开头，它会匹配一个单词的开始位置。

- 单词的结尾：如果 \b 出现在一个字母或数字之后，或者在字符串的末尾，它会匹配一个单词的结束位置。

- 单词的内部：如果 \b 出现在两个连续的字母或数字之间，它不会匹配任何内容，因为没有单词边界。

WHERE conditions REGEXP '\\bDIAB1.*';

(user_id,type) in ((568,6),(569,6),(600,8));

You can‘t specify target table for update in FROM clause：https://leetcode.cn/problems/delete-duplicate-emails/?envType=study-plan-v2&envId=sql-free-50

从有序表中选取第几项可以考虑使用 limit 和 offset 子句

GROUP_CONCAT(
DISTINCT expression1
ORDER BY expression2
SEPARATOR sep
);

正则式：https://leetcode.cn/problems/find-users-with-valid-e-mails/solutions/2366182/cha-zhao-yong-you-you-xiao-you-xiang-de-gn7ym/?envType=study-plan-v2&envId=sql-free-50

使用 ^ 限制从字符串开头开始匹配，$ 限制结尾。

先通过 WHERE 子句进行过滤，再执行聚合函数

MySQL 不支持 FULL JOIN（CROSS JOIN 实际上是 INNER JOIN）

但是可以用 LEFT JOIN 与 RIGHT JOIN 模拟实现：

```sql
select employee_id from (
    select e.employee_id employee_id from Employees e left join Salaries s on e.employee_id=s.employee_id where salary is null
    union all
    select s.employee_id employee_id from Employees e right join Salaries s on e.employee_id=s.employee_id where name is null
) x order by employee_id;
```

DATE(day), 可以从 DATETIME 类型中提取其 DATE 的部分。

MySQL 如何生成连续的数字/字符/时间序列：https://blog.csdn.net/horses/article/details/107349305

MySQL CTE 递归：https://www.yiibai.com/mysql/recursive-cte.html

- https://leetcode.cn/problems/find-the-subtasks-that-did-not-execute/


删除空格：

- TRIM()：删除左右两边的空格
- LTRIM()：删除左边的空格
- RTRIM()：删除右边的空格

贪心：通过局部最优推出整体最优，否则可能会使用到动态规划。

## 复习题单

力扣：142, 823, 904, 1654, 1761, offer-57, offer-11, 202, 449, 15, 1462, offer-38, 31, offer-17, offer-51, offer-19,
offer-49, offer-60, 2560, 2603, 146, 2251

## Leetcode 力扣

### 全部题目

#### [1. 两数之和](https://leetcode.cn/problems/two-sum/)

`数组` `哈希表`

| 语言   | 题解                                                                                  | 最后修改       |
|------|-------------------------------------------------------------------------------------|------------|
| C++  | [cpp/include/leetcode/1/Solution.h](./cpp/include/leetcode/1/Solution.h)            | 2023年9月3日  |
| Java | [leetcode/java/p1](leetcode/java/src/main/java/com/kekwy/leetcode/p1/Solution.java) | 2023年9月21日 |
|      |                                                                                     |            |

#### [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)

`递归` `链表` `数学`

Java：[leetcode/java/p2](leetcode/java/src/main/java/com/kekwy/leetcode/problems/P2.java)

#### [15. 三数之和](https://leetcode.cn/problems/3sum/)

`数组` `双指针` `排序`

| 语言  | 题解                                                                         | 最后修改      |
|-----|----------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/15/Solution.h](./cpp/include/leetcode/15/Solution.h) | 2023年9月4日 |
|     |                                                                            |           |

#### [18. 四数之和](https://leetcode.cn/problems/4sum/)

数组 | 双指针 | 排序

| 语言  | 题解                                         | 最后修改       |
|-----|--------------------------------------------|------------|
| C++ | [leetcode/cpp/18.cpp](leetcode/cpp/18.cpp) | 2023年10月1日 |
|     |                                            |            |

#### [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

`链表` `双指针`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/19/Solution.h](./cpp/include/leetcode/19/Solution.h) | 2023年8月29日 |
|     |                                                                            |            |

#### [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

| 语言  | 题解                                                                         | 最后修改      |
|-----|----------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/20/Solution.h](./cpp/include/leetcode/20/Solution.h) | 2023年8月8日 |
|     |                                                                            |           |

#### [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

`递归`  `链表`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/24/Solution.h](./cpp/include/leetcode/24/Solution.h) | 2023年8月29日 |
|     |                                                                            |            |

#### [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

`数组` `双指针`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/26/Solution.h](./cpp/include/leetcode/26/Solution.h) | 2023年8月26日 |
|     |                                                                            |            |

#### [27. 移除元素](https://leetcode.cn/problems/remove-element/)

`数组` `双指针`

| 语言   | 题解                                                                                    | 最后修改        |
|------|---------------------------------------------------------------------------------------|-------------|
| C++  | [cpp/include/leetcode/27/Solution.h](./cpp/include/leetcode/27/Solution.h)            | 2023年8月21日  |
| Java | [leetcode/java/p27](leetcode/java/src/main/java/com/kekwy/leetcode/p27/Solution.java) | 2023年11月16日 |
|      |                                                                                       |             |

#### [31. 下一个排列](https://leetcode.cn/problems/next-permutation/)

`数组` `双指针`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/31/Solution.h](./cpp/include/leetcode/31/Solution.h) | 2023年9月16日 |
|     |                                                                            |            |

#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

`数组` `二分查找`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/34/Solution.h](./cpp/include/leetcode/34/Solution.h) | 2023年8月13日 |
|     |                                                                            |            |

#### [35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/)

`数组` `二分查找`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/35/Solution.h](./cpp/include/leetcode/35/Solution.h) | 2023年8月13日 |
|     |                                                                            |            |

#### [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)

数组 | 哈希表 | 字符串 | 排序

| 语言  | 题解                                         | 最后修改       |
|-----|--------------------------------------------|------------|
| C++ | [leetcode/cpp/49.cpp](leetcode/cpp/49.cpp) | 2023年9月20日 |
|     |                                            |            |

#### [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

`数组` `矩阵` `模拟`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/54/Solution.h](./cpp/include/leetcode/54/Solution.h) | 2023年8月29日 |
|     |                                                                            |            |

#### [56. 合并区间](https://leetcode.cn/problems/merge-intervals/)

`数组` `排序`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/56/Solution.h](./cpp/include/leetcode/56/Solution.h) | 2023年8月27日 |
|     |                                                                            |            |

#### [57. 插入区间](https://leetcode.cn/problems/insert-interval/)

`数组`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/57/Solution.h](./cpp/include/leetcode/57/Solution.h) | 2023年8月27日 |
|     |                                                                            |            |

#### [59. 螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

`数组` `矩阵` `模拟`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/59/Solution.h](./cpp/include/leetcode/59/Solution.h) | 2023年8月29日 |
|     |                                                                            |            |

#### [69. x 的平方根 ](https://leetcode.cn/problems/sqrtx/)

`数学` `二分查找`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/69/Solution.h](./cpp/include/leetcode/69/Solution.h) | 2023年8月13日 |
|     |                                                                            |            |

#### [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/)

`哈希表` `字符串` `滑动窗口`

| 语言  | 题解                                                                         | 最后修改       |
|-----|----------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/76/Solution.h](./cpp/include/leetcode/76/Solution.h) | 2023年8月28日 |
|     |                                                                            |            |

#### [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

`栈` `树` `深度优先搜索` `二叉树`

C++：[cpp/include/leetcode/94/Solution.h](./cpp/include/leetcode/94/Solution.h) （2023年8月9日）

#### [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [./cpp/include/leetcode/105/Solution.h](./cpp/include/leetcode/105/Solution.h) | 2023年9月16日 |
|     |                                                                                |            |

#### [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

数组 | 动态规划

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode/cpp/121.cpp](leetcode/cpp/121.cpp) | 2023年10月1日 |
|     |                                              |            |

#### [136. 只出现一次的数字](https://leetcode.cn/problems/single-number/)

位操作 | 数组

| 语言  | 题解                                           | 最后修改        |
|-----|----------------------------------------------|-------------|
| C++ | [leetcode/cpp/136.cpp](leetcode/cpp/136.cpp) | 2023年10月14日 |
|     |                                              |             |

#### [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

`哈希表` `链表` `双指针`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/142/Solution.h](./cpp/include/leetcode/142/Solution.h) | 2023年8月30日 |
|     |                                                                              |            |

#### [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

C++：[./cpp/include/leetcode/144/Solution.h](./cpp/include/leetcode/144/Solution.h) （2023年8月5日）

#### [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

`栈` `树` `深度优先搜索` `二叉树`

C++：[cpp/include/leetcode/145/Solution.h](./cpp/include/leetcode/145/Solution.h) （2023年8月9日）

#### [146. LRU 缓存](https://leetcode.cn/problems/lru-cache/)

设计 | 哈希表 | 链表 | 双向链表

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode/cpp/146.cpp](leetcode/cpp/146.cpp) | 2023年9月25日 |
|     |                                              |            |

#### [202. 快乐数](https://leetcode.cn/problems/happy-number/)

`哈希表` `数学` `双指针`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/202/Solution.h](./cpp/include/leetcode/202/Solution.h) | 2023年9月2日 |
|     |                                                                              |           |

#### [203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)

`递归` `链表`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/203/Solution.h](./cpp/include/leetcode/203/Solution.h) | 2023年8月29日 |
|     |                                                                              |            |

#### [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

`递归` `链表`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/206/Solution.h](./cpp/include/leetcode/206/Solution.h) | 2023年8月9日 |
|     |                                                                              |           |

#### [207. 课程表](https://leetcode.cn/problems/course-schedule/)

`深度优先搜索` `广度优先搜索` `图` `拓扑排序`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/207/Solution.h](./cpp/include/leetcode/207/Solution.h) | 2023年9月9日 |
|     |                                                                              |           |

#### [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

`数组` `二分查找` `前缀和` `滑动窗口`

| 语言   | 题解                                                                                      | 最后修改        |
|------|-----------------------------------------------------------------------------------------|-------------|
| C++  | [cpp/include/leetcode/209/Solution.h](./cpp/include/leetcode/209/Solution.h)            | 2023年8月26日  |
| Java | [leetcode/java/p209](leetcode/java/src/main/java/com/kekwy/leetcode/p209/Solution.java) | 2023年11月16日 |
|      |                                                                                         |             |

#### [210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii/)

`深度优先搜索` `广度优先搜索` `图` `拓扑排序`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/210/Solution.h](./cpp/include/leetcode/210/Solution.h) | 2023年9月10日 |
|     |                                                                              |            |

#### [217. 存在重复元素](https://leetcode.cn/problems/contains-duplicate/)

C++：[./cpp/include/leetcode/217/Solution.h](./cpp/include/leetcode/217/Solution.h) （2023年8月7日）

#### [228. 汇总区间](https://leetcode.cn/problems/summary-ranges/)

`数组`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/228/Solution.h](./cpp/include/leetcode/228/Solution.h) | 2023年8月26日 |
|     |                                                                              |            |

#### [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)

C++：[cpp/include/leetcode/232/MyQueue.h](cpp/include/leetcode/232/MyQueue.h) （2023年8月8日）

#### [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

`哈希表` `字符串` `排序`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/242/Solution.h](./cpp/include/leetcode/242/Solution.h) | 2023年8月31日 |
|     |                                                                              |            |

#### [283. 移动零](https://leetcode.cn/problems/move-zeroes/)

`数组` `双指针`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/283/Solution.h](./cpp/include/leetcode/283/Solution.h) | 2023年8月26日 |
|     |                                                                              |            |

#### [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)

树 | 深度优先搜索 | 动态规划 | 二叉树

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode/cpp/337.cpp](leetcode/cpp/337.cpp) | 2023年9月18日 |
|     |                                              |            |

#### [349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

`数组` `哈希表` `双指针` `二分查找` `排序`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/349/Solution.h](./cpp/include/leetcode/349/Solution.h) | 2023年9月3日 |
|     |                                                                              |           |

#### [367. 有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/)

`数学` `二分查找`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/367/Solution.h](./cpp/include/leetcode/367/Solution.h) | 2023年8月13日 |
|     |                                                                              |            |

#### [383. 赎金信](https://leetcode.cn/problems/ransom-note/)

`哈希表` `字符串` `计数`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/383/Solution.h](./cpp/include/leetcode/383/Solution.h) | 2023年9月4日 |
|     |                                                                              |           |

#### [449. 序列化和反序列化二叉搜索树](https://leetcode.cn/problems/serialize-and-deserialize-bst/)

`树` `深度优先搜索` `广度优先搜索` `设计` `二叉搜索树` `字符串` `二叉树`

| 语言  | 题解                                                                     | 最后修改      |
|-----|------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/449/Codec.h](./cpp/include/leetcode/449/Codec.h) | 2023年9月4日 |
|     |                                                                        |           |

#### [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

`数组` `哈希表`

| 语言  | 题解                                                                           | 最后修改      |
|-----|------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/454/Solution.h](./cpp/include/leetcode/454/Solution.h) | 2023年9月4日 |
|     |                                                                              |           |

#### [547. 省份数量](https://leetcode.cn/problems/number-of-provinces/)

深度优先搜索 | 广度优先搜索 | 并查集 | 图

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode/cpp/547.cpp](leetcode/cpp/547.cpp) | 2023年9月19日 |
|     |                                              |            |

#### [605. 种花问题](https://leetcode.cn/problems/can-place-flowers/)

贪心 | 数组

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode/cpp/605.cpp](leetcode/cpp/605.cpp) | 2023年9月29日 |
|     |                                              |            |

#### [630. 课程表 III](https://leetcode.cn/problems/course-schedule-iii/)

`贪心` `数组` `排序` `堆（优先队列）`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/630/Solution.h](./cpp/include/leetcode/630/Solution.h) | 2023年9月11日 |
|     |                                                                              |            |

#### [684. 冗余连接](https://leetcode.cn/problems/redundant-connection/)

`深度优先搜索` `广度优先搜索` `并查集` `图`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/684/Solution.h](./cpp/include/leetcode/684/Solution.h) | 2023年8月25日 |
|     |                                                                              |            |

#### [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream/)

`树` `设计` `二叉搜索树` `二叉树` `数据流` `堆（优先队列）`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/703/KthLargest.h](cpp/include/leetcode/703/KthLargest.h) | 2023年8月10日 |
|     |                                                                                |            |

#### [704. 二分查找](https://leetcode.cn/problems/binary-search/)

`数组` `二分查找`

| 语言   | 题解                                                                                      | 最后修改        |
|------|-----------------------------------------------------------------------------------------|-------------|
| C++  | [cpp/include/leetcode/704/Solution.h](./cpp/include/leetcode/704/Solution.h)            | 2023年8月13日  |
| Java | [leetcode/java/p704](leetcode/java/src/main/java/com/kekwy/leetcode/p704/Solution.java) | 2023年11月16日 |
|      |                                                                                         |             |

#### [707. 设计链表](https://leetcode.cn/problems/design-linked-list/)

`设计` `链表`

| 语言  | 题解                                                                                   | 最后修改       |
|-----|--------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/707/MyLinkedList.h](./cpp/include/leetcode/707/MyLinkedList.h) | 2023年8月29日 |
|     |                                                                                      |            |

#### [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/)

C++：[./cpp/include/leetcode/743/Solution.h](./cpp/include/leetcode/743/Solution.h) （2023年8月6日）

#### [802. 找到最终的安全状态](https://leetcode.cn/problems/find-eventual-safe-states/)

深度优先搜索 | 广度优先搜索 | 图 | 拓扑排序

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode\cpp\802.cpp](leetcode\cpp\802.cpp) | 2023年9月19日 |
|     |                                              |            |

#### [823. 带因子的二叉树](https://leetcode.cn/problems/binary-trees-with-factors/)

`数组` `哈希表` `动态规划` `排序`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/823/Solution.h](./cpp/include/leetcode/823/Solution.h) | 2023年8月29日 |
|     |                                                                              |            |

#### [841. 钥匙和房间](https://leetcode.cn/problems/keys-and-rooms/)

深度优先搜索 | 广度优先搜索 | 图

| 语言  | 题解                                           | 最后修改       |
|-----|----------------------------------------------|------------|
| C++ | [leetcode\cpp\841.cpp](leetcode\cpp\841.cpp) | 2023年9月20日 |
|     |                                              |            |

#### [844. 比较含退格的字符串](https://leetcode.cn/problems/backspace-string-compare/)

`栈` `双指针` `字符串` `模拟`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/844/Solution.h](./cpp/include/leetcode/844/Solution.h) | 2023年8月26日 |
|     |                                                                              |            |

#### [904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets/)

`数组` `哈希表` `滑动窗口`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/904/Solution.h](./cpp/include/leetcode/904/Solution.h) | 2023年8月26日 |
|     |                                                                              |            |

#### [977. 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)

`数组` `双指针` `排序`

| 语言   | 题解                                                                                      | 最后修改        |
|------|-----------------------------------------------------------------------------------------|-------------|
| C++  | [cpp/include/leetcode/977/Solution.h](./cpp/include/leetcode/977/Solution.h)            | 2023年8月26日  |
| Java | [leetcode/java/p977](leetcode/java/src/main/java/com/kekwy/leetcode/p977/Solution.java) | 2023年11月16日 |
|      |                                                                                         |             |

#### [1222. 可以攻击国王的皇后](https://leetcode.cn/problems/queens-that-can-attack-the-king/description/)

`数组` `矩阵` `模拟`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1222/Solution.h](./cpp/include/leetcode/1222/Solution.h) | 2023年9月14日 |
|     |                                                                                |            |

#### [1123. 最深叶节点的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/)

`树` `深度优先搜索` `广度优先搜索` `哈希表` `二叉树`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/1123/Solution.h](./cpp/include/leetcode/1123/Solution.h) | 2023年9月6日 |
|     |                                                                                |           |

#### [1135. 最低成本联通所有城市](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/)

C++：[./cpp/include/leetcode/1135/Solution.h](./cpp/include/leetcode/1135/Solution.h) （2023年8月6日）

#### [1267. 统计参与通信的服务器](https://leetcode.cn/problems/count-servers-that-communicate/)

`深度优先搜索` `广度优先搜索` `并查集` `数组` `计数` `矩阵`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1267/README.md](./cpp/include/leetcode/1267/README.md) | 2023年8月24日 |
|     |                                                                              |            |

#### [1333. 餐厅过滤器](https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/)

数组 | 排序

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode\cpp\1333.cpp](leetcode\cpp\1333.cpp) | 2023年9月27日 |
|     |                                                |            |

#### [1462. 课程表 IV](https://leetcode.cn/problems/course-schedule-iv/description/?envType=daily-question&envId=2023-09-12)

`深度优先搜索` `广度优先搜索` `图` `拓扑排序`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1462/Solution.h](./cpp/include/leetcode/1462/Solution.h) | 2023年9月14日 |
|     |                                                                                |            |

#### [1448. 统计二叉树中好节点的数目](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/)

`树` `深度优先搜索` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1448/Solution.h](./cpp/include/leetcode/1448/Solution.h) | 2023年8月25日 |
|     |                                                                                |            |

#### [1572. 矩阵对角线元素的和](https://leetcode.cn/problems/matrix-diagonal-sum/)

`数组` `矩阵`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1572/Solution.h](./cpp/include/leetcode/1572/Solution.h) | 2023年8月11日 |
|     |                                                                                |            |

#### [1654. 到家的最少跳跃次数](https://leetcode.cn/problems/minimum-jumps-to-reach-home/)

`广度优先搜索` `数组` `动态规划`

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1654/README.md](./cpp/include/leetcode/1654/README.md) | 2023年8月30日 |
|     |                                                                              |            |

#### [1761. 一个图中连通三元组的最小度数](https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph/)

`图`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/1761/Solution.h](./cpp/include/leetcode/1761/Solution.h) | 2023年8月31日 |
|     |                                                                                |            |

#### [1921. 消灭怪物的最大数量](https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/)

`贪心` `数组` `排序`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/1921/Solution.h](./cpp/include/leetcode/1921/Solution.h) | 2023年9月3日 |
|     |                                                                                |           |

#### [1993. 树上的操作](https://leetcode.cn/problems/operations-on-tree/)

树 | 深度优先搜索 | 广度优先搜索 | 设计 | 哈希表

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode\cpp\1993.cpp](leetcode\cpp\1993.cpp) | 2023年9月23日 |
|     |                                                |            |

#### [2240. 买钢笔和铅笔的方案数](https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/)

`数学` `枚举`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/2240/Solution.h](./cpp/include/leetcode/2240/Solution.h) | 2023年9月1日 |
|     |                                                                                |           |

#### [2251. 花期内花的数目](https://leetcode.cn/problems/number-of-flowers-in-full-bloom/)

数组 | 哈希表 | 二分搜索 | 有序集 | 前缀和 | 排序

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode/cpp/2251.cpp](leetcode/cpp/2251.cpp) | 2023年9月28日 |
|     |                                                |            |

#### [2511. 最多可以摧毁的敌人城堡数目](https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/)

`数组` `双指针`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/2511/Solution.h](./cpp/include/leetcode/2511/Solution.h) | 2023年9月2日 |
|     |                                                                                |           |

#### [2560. 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv/)

数组 | 二分查找

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode/cpp/2560.cpp](leetcode/cpp/2560.cpp) | 2023年9月19日 |
|     |                                                |            |

#### [2562. 找出数组的串联值](https://leetcode.cn/problems/find-the-array-concatenation-value/)

数组 | 双指针 | 模拟

| 语言  | 题解                                             | 最后修改        |
|-----|------------------------------------------------|-------------|
| C++ | [leetcode/cpp/2562.cpp](leetcode/cpp/2562.cpp) | 2023年10月12日 |
|     |                                                |             |

#### [2582. 递枕头](https://leetcode.cn/problems/pass-the-pillow/)

数学 | 模拟

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode/cpp/2582.cpp](leetcode/cpp/2582.cpp) | 2023年9月26日 |
|     |                                                |            |

#### [2591. 将钱分给最多的儿童](https://leetcode.cn/problems/distribute-money-to-maximum-children/)

贪心 | 数学

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode/cpp/2591.cpp](leetcode/cpp/2591.cpp) | 2023年9月22日 |
|     |                                                |            |

#### [2594. 修车的最少时间](https://leetcode.cn/problems/minimum-time-to-repair-cars/)

`数组` `二分查找`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/2594/Solution.h](./cpp/include/leetcode/2594/Solution.h) | 2023年9月7日 |
|     |                                                                                |           |

#### [2596. 检查骑士巡视方案](https://leetcode.cn/problems/check-knight-tour-configuration/)

`深度优先搜索` `广度优先搜索` `数组` `矩阵` `模拟`

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/2596/Solution.h](./cpp/include/leetcode/2596/Solution.h) | 2023年9月14日 |
|     |                                                                                |            |

#### [2603. 收集树中金币](https://leetcode.cn/problems/collect-coins-in-a-tree/)

树 | 图 | 拓扑排序 | 数组

| 语言  | 题解                                             | 最后修改       |
|-----|------------------------------------------------|------------|
| C++ | [leetcode/cpp/2603.cpp](leetcode/cpp/2603.cpp) | 2023年9月21日 |
|     |                                                |            |

#### [2605. 从两个数字数组里生成最小数字](https://leetcode.cn/problems/form-smallest-number-from-two-digit-arrays/)

`数组` `哈希表` `枚举`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/2605/Solution.h](./cpp/include/leetcode/2605/Solution.h) | 2023年9月5日 |
|     |                                                                                |           |

#### [2641. 二叉树的堂兄弟节点 II](https://leetcode.cn/problems/cousins-in-binary-tree-ii/)

`树` `深度优先搜索` `广度优先搜索` `哈希表` `二叉树`

Java：[leetcode/java/p2641](leetcode/java/src/main/java/com/kekwy/leetcode/problems/P2641.java)

#### [2651. 计算列车到站时间](https://leetcode.cn/problems/calculate-delayed-arrival-time/)

`数学`

| 语言  | 题解                                                                             | 最后修改      |
|-----|--------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/2651/Solution.h](./cpp/include/leetcode/2651/Solution.h) | 2023年9月8日 |
|     |                                                                                |           |

### 剑指 Offer（第 2 版）

#### [剑指 Offer 03. 数组中重复的数字](https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

`数组` `哈希表` `排序`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-03/Solution.h](./cpp/include/leetcode/offer-03/Solution.h) | 2023年9月1日 |
|     |                                                                                        |           |

#### [剑指 Offer 04. 二维数组中的查找](https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

`数组` `二分查找` `分治` `矩阵`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-04/Solution.h](./cpp/include/leetcode/offer-04/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 05. 替换空格](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

`字符串`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-05/Solution.h](./cpp/include/leetcode/offer-05/Solution.h) | 2023年8月29日 |
|     |                                                                                        |            |

#### [剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

`栈` `递归` `链表` `双指针`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-06/Solution.h](./cpp/include/leetcode/offer-06/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 07. 重建二叉树](https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/)

`树` `数组` `哈希表` `分治` `二叉树`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-07/Solution.h](./cpp/include/leetcode/offer-07/Solution.h) | 2023年7月16日 |
|     |                                                                                        |            |

#### [剑指 Offer 09. 用两个栈实现队列](https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

`栈` `设计` `队列`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-09/Solution.h](./cpp/include/leetcode/offer-09/Solution.h) | 2023年9月1日 |
|     |                                                                                        |           |

#### [剑指 Offer 10- I. 斐波那契数列](https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof/)

`记忆` `数学` `动态规划`

| 语言  | 题解                                                                 | 最后修改       |
|-----|--------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 10- I.cpp](leetcode/cpp/剑指 Offer 10- I.cpp) | 2023年9月17日 |
|     |                                                                    |            |

#### [剑指 Offer 10- II. 青蛙跳台阶问题](https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)

`记忆` `数学` `动态规划`

| 语言  | 题解                                                                   | 最后修改       |
|-----|----------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 10- II.cpp](leetcode/cpp/剑指 Offer 10- II.cpp) | 2023年9月17日 |
|     |                                                                      |            |

#### [剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

`数组` `二分查找`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-11/Solution.h](./cpp/include/leetcode/offer-11/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 12. 矩阵中的路径](https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof/)

`数组` `回溯` `矩阵`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-12/Solution.h](./cpp/include/leetcode/offer-12/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 13. 机器人的运动范围](https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)

`深度优先搜索` `广度优先搜索` `动态规划`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-13/Solution.h](./cpp/include/leetcode/offer-13/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 14- I. 剪绳子](https://leetcode.cn/problems/jian-sheng-zi-lcof/)

数学 | 动态规划

| 语言  | 题解                                                                    | 最后修改       |
|-----|-----------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 15.cpp](leetcode/cpp/剑指%20Offer%2014-%20I.cpp) | 2023年9月18日 |
|     |                                                                       |            |

#### [剑指 Offer 14- II. 剪绳子 II](https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/)

数学 | 动态规划

| 语言  | 题解                                                                    | 最后修改       |
|-----|-----------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 15.cpp](leetcode/cpp/剑指%20Offer%2014-%20I.cpp) | 2023年9月18日 |
|     |                                                                       |            |

#### [剑指 Offer 15. 二进制中1的个数](https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)

位操作

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 15.cpp](leetcode/cpp/剑指%20Offer%2015.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 16. 数值的整数次方](https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)

`递归` `数学`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-16/Solution.h](./cpp/include/leetcode/offer-16/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 17. 打印从1到最大的n位数](https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)

`数组` `数学`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-17/Solution.h](./cpp/include/leetcode/offer-17/Solution.h) | 2023年9月16日 |
|     |                                                                                        |            |

#### [剑指 Offer 18. 删除链表的节点](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

`链表`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-18/Solution.h](./cpp/include/leetcode/offer-18/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 19. 正则表达式匹配](https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)

递归 | 字符串 | 动态规划

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 19.cpp](leetcode/cpp/剑指 Offer 19.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 20. 表示数值的字符串](https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)

`字符串`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-20/Solution.h](./cpp/include/leetcode/offer-20/Solution.h) | 2023年8月30日 |
|     |                                                                                        |            |

#### [剑指 Offer 21. 调整数组顺序使奇数位于偶数前面](https://leetcode.cn/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/)

`数组` `双指针` `排序`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-21/Solution.h](./cpp/include/leetcode/offer-21/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

`链表` `双指针`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-22/Solution.h](./cpp/include/leetcode/offer-22/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 24. 反转链表](https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/)

`递归` `链表`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-24/Solution.h](./cpp/include/leetcode/offer-24/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 25. 合并两个排序的链表](https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)

`递归` `链表`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-25/Solution.h](./cpp/include/leetcode/offer-25/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 26. 树的子结构](https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/)

`树` `深度优先搜索` `二叉树`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-26/Solution.h](./cpp/include/leetcode/offer-26/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 27. 二叉树的镜像](https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/)

`树` `深度优先搜索` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-27/Solution.h](./cpp/include/leetcode/offer-27/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 28. 对称的二叉树](https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/)

`树` `深度优先搜索` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-28/Solution.h](./cpp/include/leetcode/offer-27/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 29. 顺时针打印矩阵](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)

`数组` `矩阵` `模拟`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-29/Solution.h](./cpp/include/leetcode/offer-29/Solution.h) | 2023年9月1日 |
|     |                                                                                        |           |

#### [剑指 Offer 30. 包含min函数的栈](https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/)

`栈` `设计`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-30/Solution.h](./cpp/include/leetcode/offer-30/Solution.h) | 2023年9月1日 |
|     |                                                                                        |           |

#### [剑指 Offer 31. 栈的压入、弹出序列](https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)

`栈` `数组` `模拟`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-31/Solution.h](./cpp/include/leetcode/offer-31/Solution.h) | 2023年9月1日 |
|     |                                                                                        |           |

#### [剑指 Offer 32 - I. 从上到下打印二叉树](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)

`树` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                         | 最后修改      |
|-----|--------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-32-I/Solution.h](./cpp/include/leetcode/offer-32-I/Solution.h) | 2023年9月2日 |
|     |                                                                                            |           |

#### [剑指 Offer 32 - II. 从上到下打印二叉树 II](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

`树` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                           | 最后修改      |
|-----|----------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-32-II/Solution.h](./cpp/include/leetcode/offer-32-II/Solution.h) | 2023年9月2日 |
|     |                                                                                              |           |

#### [剑指 Offer 32 - III. 从上到下打印二叉树 III](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)

`树` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                             | 最后修改      |
|-----|------------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-32-III/Solution.h](./cpp/include/leetcode/offer-32-III/Solution.h) | 2023年9月2日 |
|     |                                                                                                |           |

#### [剑指 Offer 33. 二叉搜索树的后序遍历序列](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

`栈` `树` `二叉搜索树` `递归` `二叉树` `单调栈`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-33/Solution.h](./cpp/include/leetcode/offer-33/Solution.h) | 2023年9月16日 |
|     |                                                                                        |            |

#### [剑指 Offer 34. 二叉树中和为某一值的路径](https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)

`树` `深度优先搜索` `回溯` `二叉树`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-34/Solution.h](./cpp/include/leetcode/offer-34/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 35. 复杂链表的复制](https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/)

`哈希表` `链表`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-35/Solution.h](./cpp/include/leetcode/offer-35/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 36. 二叉搜索树与双向链表](https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)

`栈` `树` `深度优先搜索` `二叉搜索树` `链表` `二叉树` `双向链表`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-36/Solution.h](./cpp/include/leetcode/offer-36/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 37. 序列化二叉树](https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/)

`树` `深度优先搜索` `广度优先搜索` `设计` `字符串` `二叉树`

| 语言  | 题解                                                                               | 最后修改      |
|-----|----------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-37/Codec.h](./cpp/include/leetcode/offer-37/Codec.h) | 2023年9月3日 |
|     |                                                                                  |           |

#### [剑指 Offer 38. 字符串的排列](https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/)

`字符串` `回溯`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-38/Solution.h](./cpp/include/leetcode/offer-38/Solution.h) | 2023年9月16日 |
|     |                                                                                        |            |

#### [剑指 Offer 40. 最小的k个数](https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/)

`数组` `分治` `快速选择` `排序` `优先级队列`

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 40.cpp](leetcode/cpp/剑指 Offer 40.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 41. 数据流中的中位数](https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)

`设计` `双指针` `数据流 ` `排序` `优先级队列`

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 41.cpp](leetcode/cpp/剑指 Offer 41.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 42. 连续子数组的最大和](https://leetcode.cn/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)

数组 | 分治 | 动态规划

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 42.cpp](leetcode/cpp/剑指 Offer 42.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 43. 1～n 整数中 1 出现的次数](https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)

递归 | 数学 | 动态规划

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 43.cpp](leetcode/cpp/剑指%20Offer%2043.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 44. 数字序列中某一位的数字](https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)

数学 | 二分搜索

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 44.cpp](leetcode/cpp/剑指%20Offer%2044.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 45. 把数组排成最小的数](https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)

贪心 | 字符串 | 排序

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 45.cpp](leetcode/cpp/剑指%20Offer%2045.cpp) | 2023年9月17日 |
|     |                                                                  |            |

#### [剑指 Offer 46. 把数字翻译成字符串](https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)

字符串 | 动态规划

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 46.cpp](leetcode/cpp/剑指 Offer 46.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 47. 礼物的最大价值](https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/)

数组 | 动态规划 | 矩阵

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 47.cpp](leetcode/cpp/剑指%20Offer%2047.cpp) | 2023年9月17日 |
|     |                                                                  |            |

#### [剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)

哈希表 | 字符串 | 滑动窗口

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 48.cpp](leetcode/cpp/剑指 Offer 48.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 49. 丑数](https://leetcode.cn/problems/chou-shu-lcof/)

哈希表 | 数学 | 动态规划 | 优先级队列

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 49.cpp](leetcode/cpp/剑指 Offer 49.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 50. 第一个只出现一次的字符](https://leetcode.cn/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)

`队列` `哈希表` `字符串` `计数`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-50/Solution.h](./cpp/include/leetcode/offer-50/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 51. 数组中的逆序对](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)

`树状数组` `线段树` `数组` `二分查找` `分治` `有序集合` `归并排序`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-51/Solution.h](./cpp/include/leetcode/offer-51/Solution.h) | 2023年9月16日 |
|     |                                                                                        |            |

#### [剑指 Offer 52. 两个链表的第一个公共节点](https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)

`哈希表` `链表` `双指针`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-52/Solution.h](./cpp/include/leetcode/offer-52/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

`数组` `二分查找`

| 语言  | 题解                                                                                         | 最后修改      |
|-----|--------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-53-I/Solution.h](./cpp/include/leetcode/offer-53-I/Solution.h) | 2023年9月1日 |
|     |                                                                                            |           |

#### [剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/)

`位运算` `数组` `哈希表` `数学` `二分查找`

| 语言  | 题解                                                                                           | 最后修改      |
|-----|----------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-53-II/Solution.h](./cpp/include/leetcode/offer-53-II/Solution.h) | 2023年9月2日 |
|     |                                                                                              |           |

#### [剑指 Offer 54. 二叉搜索树的第k大节点](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)

`树` `深度优先搜索` `二叉搜索树` `二叉树`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-54/Solution.h](./cpp/include/leetcode/offer-54/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 55 - I. 二叉树的深度](https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/)

`树` `深度优先搜索` `广度优先搜索` `二叉树`

| 语言  | 题解                                                                                         | 最后修改      |
|-----|--------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-55-I/Solution.h](./cpp/include/leetcode/offer-55-I/Solution.h) | 2023年9月2日 |
|     |                                                                                            |           |

#### [剑指 Offer 55 - II. 平衡二叉树](https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/)

`树` `深度优先搜索` `二叉树`

| 语言  | 题解                                                                                           | 最后修改      |
|-----|----------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-55-II/Solution.h](./cpp/include/leetcode/offer-55-II/Solution.h) | 2023年9月2日 |
|     |                                                                                              |           |

#### [剑指 Offer 56 - I. 数组中数字出现的次数](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)

位操作 | 数组

| 语言  | 题解                                                                           | 最后修改       |
|-----|------------------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 56 - I.cpp](leetcode/cpp/剑指%20Offer%2056%20-%20I.cpp) | 2023年9月17日 |
|     |                                                                              |            |

#### [剑指 Offer 56 - II. 数组中数字出现的次数 II](https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)

位操作 | 数组

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 56 - II.cpp](leetcode/cpp/剑指%20Offer%2056%20-%20II.cpp) | 2023年9月18日 |
|     |                                                                                |            |

#### [剑指 Offer 57. 和为s的两个数字](https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

`数组` `双指针` `二分查找`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-57/Solution.h](./cpp/include/leetcode/offer-57/Solution.h) | 2023年8月31日 |
|     |                                                                                        |            |

#### [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

数学 | 双指针 | 枚举

| 语言  | 题解                                                                             | 最后修改       |
|-----|--------------------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 57 - II.cpp](leetcode/cpp/剑指%20Offer%2057%20-%20II.cpp) | 2023年9月18日 |
|     |                                                                                |            |

#### [剑指 Offer 58 - I. 翻转单词顺序](https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/)

`双指针` `字符串`

| 语言  | 题解                                                                                         | 最后修改       |
|-----|--------------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-58-I/Solution.h](./cpp/include/leetcode/offer-58-I/Solution.h) | 2023年8月31日 |
|     |                                                                                            |            |

#### [剑指 Offer 58 - II. 左旋转字符串](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

`数学` `双指针` `字符串`

| 语言  | 题解                                                                                           | 最后修改       |
|-----|----------------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-58-II/Solution.h](./cpp/include/leetcode/offer-58-II/Solution.h) | 2023年8月30日 |
|     |                                                                                              |            |

#### [剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

`队列` `滑动窗口` `单调队列` `堆（优先级队列）`

| 语言  | 题解                                                                                         | 最后修改      |
|-----|--------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-59-I/Solution.h](./cpp/include/leetcode/offer-59-I/Solution.h) | 2023年9月1日 |
|     |                                                                                            |           |

#### [剑指 Offer 59 - II. 队列的最大值](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/)

`设计` `队列` `单调队列`

| 语言  | 题解                                                                                           | 最后修改      |
|-----|----------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-59-II/Solution.h](./cpp/include/leetcode/offer-59-II/Solution.h) | 2023年9月1日 |
|     |                                                                                              |           |

#### [剑指 Offer 60. n个骰子的点数](https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/)

数学 | 动态规划 | 概率和统计

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 60.cpp](leetcode/cpp/剑指%20Offer%2060.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 61. 扑克牌中的顺子](https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

`数组` `排序`

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 61.cpp](leetcode/cpp/剑指 Offer 61.cpp) | 2023年9月16日 |
|     |                                                              |            |

#### [剑指 Offer 62. 圆圈中最后剩下的数字](https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)

递归 | 数学

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 62.cpp](leetcode/cpp/剑指%20Offer%2062.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 63. 股票的最大利润](https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/)

`数组` `动态规划`

| 语言  | 题解                                                           | 最后修改       |
|-----|--------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 63.cpp](leetcode/cpp/剑指 Offer 63.cpp) | 2023年9月17日 |
|     |                                                              |            |

#### [剑指 Offer 64. 求1+2+…+n](https://leetcode.cn/problems/qiu-12n-lcof/)

`位运算` `递归` `脑筋急转弯`

| 语言  | 题解                                                                                     | 最后修改      |
|-----|----------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-64/Solution.h](./cpp/include/leetcode/offer-64/Solution.h) | 2023年9月2日 |
|     |                                                                                        |           |

#### [剑指 Offer 65. 不用加减乘除做加法](https://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/)

位操作 | 数学

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 65.cpp](leetcode/cpp/剑指%20Offer%2065.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 66. 构建乘积数组](https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/)

数组 | 前缀和

| 语言  | 题解                                                               | 最后修改       |
|-----|------------------------------------------------------------------|------------|
| C++ | [leetcode/cpp/剑指 Offer 66.cpp](leetcode/cpp/剑指%20Offer%2066.cpp) | 2023年9月18日 |
|     |                                                                  |            |

#### [剑指 Offer 67. 把字符串转换成整数](https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/)

`字符串`

| 语言  | 题解                                                                                     | 最后修改       |
|-----|----------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/offer-67/Solution.h](./cpp/include/leetcode/offer-67/Solution.h) | 2023年8月30日 |
|     |                                                                                        |            |

#### [剑指 Offer 68 - I. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

`树` `深度优先搜索` `二叉搜索树` `二叉树`

| 语言  | 题解                                                                                         | 最后修改      |
|-----|--------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-68-I/Solution.h](./cpp/include/leetcode/offer-68-I/Solution.h) | 2023年9月3日 |
|     |                                                                                            |           |

#### [剑指 Offer 68 - II. 二叉树的最近公共祖先](https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

`树` `深度优先搜索` `二叉树`

| 语言  | 题解                                                                                           | 最后修改      |
|-----|----------------------------------------------------------------------------------------------|-----------|
| C++ | [cpp/include/leetcode/offer-68-II/Solution.h](./cpp/include/leetcode/offer-68-II/Solution.h) | 2023年9月3日 |
|     |                                                                                              |           |

### 程序员面试金典（第 6 版）

#### [面试题 02.07. 链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

`哈希表` `链表` `双指针`

| 语言  | 题解                                                                                                   | 最后修改       |
|-----|------------------------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/interview-02.07/Solution.h](./cpp/include/leetcode/interview-02.07/Solution.h) | 2023年8月30日 |
|     |                                                                                                      |            |

### 力扣杯 - 竞赛合集

#### [LCP 06. 拿硬币](https://leetcode.cn/problems/na-ying-bi/)

数组 | 数学

| 语言  | 题解                                                   | 最后修改       |
|-----|------------------------------------------------------|------------|
| C++ | [leetcode/cpp/LCP 06.cpp](leetcode/cpp/LCP%2006.cpp) | 2023年9月20日 |
|     |                                                      |            |

#### [LCP 50. 宝石补给](https://leetcode.cn/problems/WHnhjV/)

`数组` `模拟`

| 语言  | 题解                                                                                 | 最后修改       |
|-----|------------------------------------------------------------------------------------|------------|
| C++ | [cpp/include/leetcode/lcp-50/Solution.h](./cpp/include/leetcode/lcp-50/Solution.h) | 2023年9月15日 |
|     |                                                                                    |            |

## Nowcoder 牛客

