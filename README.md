# CPlusPlus

​	my personal CPlusPlus learning repository

[toc]

## 简介

* 开发工具：VsCode、mingw-w64
* 软件环境：Window11
* 编译工具：gcc version 8.1.0 (x86_64-posix-seh-rev0)，C/C++编译

## 目录结构

```
CPlusPlus
  ├───Array
  ├───List
  └───String
```

## Array

### 最小操作次数使数组元素相等

给你一个长度为 `n` 的整数数组，每次操作将会使 `n - 1` 个元素增加 `1` 。返回让数组所有元素相等的最小操作次数。

> 因为只需要找出让数组所有元素相等的最小操作次数，所以我们不需要考虑数组中各个元素的绝对大小，即不需要真正算出数组中所有元素相等时的元素值，只需要考虑数组中元素相对大小的变化即可。
>
> 因此，每次操作既可以理解为使 n−1n-1n−1 个元素增加 111，也可以理解使 111 个元素减少 111。显然，后者更利于我们的计算。
>
> 于是，要计算让数组中所有元素相等的操作数，我们只需要计算将数组中所有元素都减少到数组中元素最小值所需的操作数，即计算
>
> $$
> \sum_{i=0}^{n-1}(nums[i]-min(nums))
> $$
> 其中*min*(*nums*)为数组 nums 中元素的最小值

题解见[minMoves.cpp](./list/minMoves.cpp)

复杂度分析：

* 时间复杂度：O(n)，其中 n 为数组中的元素数量。我们需要一次遍历求出最小值，一次遍历计算操作次数。
* 空间复杂度：O(1)


## List

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
```

### 奇偶链表

给定单链表的头节点 `head` ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。

**第一个节点**的索引被认为是**奇数** ， **第二个节点**的索引为**偶数** ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

> 如果链表为空，则直接返回链表。
> 对于原始链表，每个节点都是奇数节点或偶数节点。头节点是奇数节点，头节点的后一个节点是偶数节点，相邻节点的奇偶性不同。因此可以将奇数节点和偶数节点分离成奇数链表和偶数链表，然后将偶数链表连接在奇数链表之后，合并后的链表即为结果链表。

题解见[oddEvenList.cpp](./list/oddEvenList.cpp)

复杂度分析：

* 时间复杂度：O(n)，其中 n是链表的节点数。需要遍历链表中的每个节点，并更新指针
* 空间复杂度：O(1)。只需要维护有限的指针。

### 反转链表

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

> 假设链表为:$n_1->...->n_{k-1}->n_{k}->n_{k+1}->...->n_m->\varnothing$
>
> 若从节点$n_{k+1}$到$n_m$已经被反转，而我们正处于$n_k$
>
> $n_1->...->n_{k-1}->n_{k}->n_{k+1}<-...<-n_m$
>
> 我们希望$n_{k+1}$的下一个节点指向$n_k$
>
> 所以，$n_k.next.next = n_k$
>
> 需要注意的是$n_1$下一个节点必须指向 $\varnothing$。如果忽略了这一点，链表中可能会产生环。

题解见[reverseList.cpp](./list/reverseList.cpp)

复杂度分析：

* 时间复杂度：O(n)，其中 n是链表的长度。需要对链表的每个节点进行反转操作。
* 空间复杂度：O(n)，其中 n是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 n 层。

## String

### 同构字符串

给定两个字符串 `s` 和 `t` ，判断它们是否是同构的。

如果 `s` 中的字符可以按某种映射关系替换得到 `t` ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

**示例 1:**

```C++
输入：s = "egg", t = "add"
输出：true
```

**示例 2：**

```C++
输入：s = "foo", t = "bar"
输出：false
```

**示例 3：**

```C++
输入：s = "paper", t = "title"
输出：true
```

> 我们维护两张哈希表，第一张哈希表 s2t 以 s 中字符为键，映射至 t 的字符为值，第二张哈希表 t2s 以 t 中字符为键，映射至 s 的字符为值。从左至右遍历两个字符串的字符，不断更新两张哈希表，如果出现冲突（即当前下标 index 对应的字符 s[index] 已经存在映射且不为 t[index] 或当前下标 index 对应的字符 t[index] 已经存在映射且不为 s[index]）时说明两个字符串无法构成同构，返回 false
>
> 如果遍历结束没有出现冲突，则表明两个字符串是同构的，返回 true 即可。

题解见[isIsomorphic.cpp](./string/isIsomorphic.cpp)

复杂度分析：

- 时间复杂度：O(n)，其中 n 为字符串的长度。我们只需同时遍历一遍字符串 s 和 t即可。
- 空间复杂度：O(∣Σ∣)，其中 Σ 是字符串的字符集。哈希表存储字符的空间取决于字符串的字符集大小，最坏情况下每个字符均不相同，需要 O(∣Σ∣) 的空间。

### 替换空格

请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

> 遍历字符串，使用三目运算符判断空格并替换重组

题解见[replaceSpace.cpp](./string/replaceSpace.cpp)

复杂度分析：

- 时间复杂度：O(n)，其中 n 为字符串的长度。我们只需遍历一遍字符串即可。
- 空间复杂度：O(n)，额外创建字符串，长度为s.size()+2*n。

### 左旋字符串

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

> 获取str[n:] 和 str[:n]子串，目标串target = str[:n] + str[n:];

题解见[reverseLeftWords.cpp](./string/reverseLeftWords.cpp)

复杂度分析：

- 时间复杂度：O(n)，其中 n 为左旋字符串的长度。我们只需遍历一遍左旋字符串即可。
- 空间复杂度：O(n)。

### 反转字符串中的单词

给你一个字符数组 `s` ，反转其中 **单词** 的顺序。

**单词** 的定义为：单词是一个由非空格字符组成的序列。`s` 中的单词将会由单个空格分隔。

必须设计并实现 **原地** 解法来解决此问题，即不分配额外的空间。

**示例 1：**

```C++
输入：s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
输出：["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
```

**示例 2：**

```C++
输入：s = ["a"]
输出：["a"]
```

> 1.第一次翻转： 以“单词”为单位进行翻转，调整单词之间的位置关系
>
> 2.第二次翻转： 以char为单位进行翻转，对每个单词，调整单词内部的位置关系
>
> 3.这两次调整的顺序不分先后

题解见[reverseWords.cpp](./string/reverseWords.cpp)

复杂度分析：

- 时间复杂度：O(n)，其中 n 为字符串的长度。
- 空间复杂度：O(1)。

### 最长回文子串

给你一个字符串 `s`，找到 `s` 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

**示例 1：**

```C++
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

**示例 2：**

```C++
输入：s = "cbbd"
输出："bb"
```

> 对于一个子串而言，如果它是回文串，并且长度大于 222，那么将它首尾的两个字母去除之后，它仍然是个回文串。例如对于字符串 “ababa”，如果我们已经知道 “bab” 是回文串，那么 “ababa” 一定是回文串，这是因为它的首尾两个字母都是 “a”。
>
> 根据这样的思路，我们就可以用动态规划的方法解决本题。我们用 P(i,j)表示字符串 s 的第 i 到 j 个字母组成的串（下文表示成 s[i:j]）是否为回文串
> $$
> P(i,j)=\begin{cases}
> true,  &如果子串 S_i…S_j是回文串 \\
> false, &其他情况
> \end{cases}
> $$
> 这里的「其它情况」包含两种可能性：
>
> * s[i,j]本身不是一个回文子串；
> * i > j, 此时s[i,j]本身不合法。
>
> 那么我们就可以写出状态转移方程：
>
> $$
> \begin{cases}
> P(i,i) &=& true \\
> P(i,i+1) &=& (s_i==s_{i+1}) \\
> P(i,j) &=& P(i+1,j-1)\cap(s_i==s_j)
> \end{cases}
> $$
>
> 其中状态转移链为：$P(i,j)<-P(i+1,j-1)<-P(i+2,j-2)<-···<-某一边界情况$
>
> 可以发现，所有的状态在转移的时候的可能性都是唯一的。也就是说，我们可以从每一种边界情况开始「扩展」，也可以得出所有的状态对应的答案。
>
> 边界情况即为子串长度为 1 或 2 的情况。我们枚举每一种边界情况，并从对应的子串开始不断地向两边扩展。如果两边的字母相同，我们就可以继续扩展，例如从 P(i+1,j−1) 扩展到 P(i,j)；如果两边的字母不同，我们就可以停止扩展，因为在这之后的子串都不能是回文串了。
>
> 「边界情况」对应的子串实际上就是我们「扩展」出的回文串的「回文中心」。本质即为：我们枚举所有的「回文中心」并尝试「扩展」，直到无法扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度。我们对所有的长度求出最大值，即可得到最终的答案。
>

题解见[selectLongestPalindrome.cpp](./string/selectLongestPalindrome.cpp)

复杂度分析

* 时间复杂度：O(n^2)，其中 n 是字符串的长度。长度为 1和 2的回文中心分别有 n 和 n−1个，每个回文中心最多会向外扩展 O(n) 次。

* 空间复杂度：O(1)。
