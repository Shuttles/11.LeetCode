# LinkedList

约瑟夫问题来源于犹太历史学家约瑟夫，他和他的一个朋友与另外39名犹太人为了躲避罗马人藏在了一个山洞中，39位犹太人决定宁愿自杀也不能被抓到。他们商议围成一个圈，从某一个人开始数1，每数到第三得人必须自杀然后再从他之后的人继续数1。这时候，约瑟夫把朋友和自己安排在了第16和第31的位置，最终，当其他39名犹太人都自杀之后，他们俩躲过一劫。



## 141.环形链表

### 题面

给定一个链表，判断链表中是否有环。

![img](https://wx1.sinaimg.cn/mw690/005LasY6gy1gcbbmfld7nj30os19igqj.jpg)

### 我的思路

没想出来。。



### 题解思路

快慢指针法！！

想像一下操场跑步的时候，快的人一定会追上慢的人！

也就是说，如果有环的话，快指针一定会 == 慢指针！！



### 代码

PS：

1. 注意我的while和光哥代码里的while中的条件的不同！！

#### 我的

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *q, *p;
    p =  head;
    q = p->next;
    while (p && q) {
        if (p == q) return true;
        p = p->next;
        q = q->next;
        if (!q || !p) return false;
        q = q->next;
    }
    return false;
}
```

#### 光哥的

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;//q是快指针！
    if (!p) return false;
    do {
        p = p->next;
        q = q->next;
        if (!q || !q->next) return false;//if中的条件极为重要！！
        q = q->next;
    } while (p != q);
    return true;
}
```



## 202.快乐数

### 题面

![img](https://wx1.sinaimg.cn/mw690/005LasY6gy1gcbc6pc4llj30pi0l4acp.jpg)

### 我的思路

和回文数有类似之处，但是我想不出如何判断无限循环的情况！！

### 题解思路

既然能循环，那就可以借鉴环形链表的快慢指针法！

### 代码

```C
int get_next(int n) {
    int ans = 0;
    while (n) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}


bool isHappy(int n){
    int p = n, q = n;
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) break;//一定是break而不是直接return false，因为可能p == q == 1！！！
    }
    return q == 1;
}

//另一种写法,模仿环形链表的写法！！
bool isHappy(int n){
    int p = n, q = n;
    do {
        p = get_next(p);
        q = get_next(get_next(q));
    } while (p != q && q != 1);
    return q == 1;
}
```



## 142.环形链表2

### 题面





1. 160.相交链表

   编写一个程序，找到两个单链表相交的起始节点。

   1. PS:1.如果没有交点，返回NULL。

   ​     2.再返回结果后，两个链表仍须保持原有结构

   ​     3.可假定整个链表结构中没有循环

   ​     4.程序尽量满足O(n)时间复杂度，且仅用O(1)空间复杂度

   2.解题思路：

   PS：我没想出来，是看的题解QAQ

   + 原理：就是利用a+same+b == b + same + a来做

   + 利用两个指针，分别从headA和headB往后走，p走到A的尾部(NULL)就跳到headB，q类比着走，如果相交，那么一定会在某个点p == q！！！那么就可以break！！！这点很重要！！光哥就是利用这一点设计的while(p != q)从而让它的代码如此短小精悍！！

   + 对比我和hug的代码！！我就是按我的思路写的，但一看，光哥代码太nb了，令我虎躯一震！！

     光哥代码如下：

     ```C
     struct ListNode *p = headA, *q = headB;
     while (p != q) {
       p = p ? p->next : headB;
       q = q ? q->next : headA;
     }
     return p;
     ```

     

   

   3.踩过的坑：

   + 每次返回的是相交部分的最后一个节点(没有特判第一个相交的)
   + 空链表和只有一个元素的链表(if和while的条件写得是p->next而不是p)
   + [3], [2, 3] (有两个原因，一是写的是p->next而不是p，二是没有在while一进去就判等)

   4. 启示：

      1.while里的判断条件非常非常重要！

      选得好可以省很多事！要深思熟虑！！比如我写的代码和hug写的代码！

      2. 在做链表的题的时候，循环或者if的判断条件是p还是p->next很重要！！！

      用得好可以解决很多边界问题！！！比如坑2

   

2. 202.快乐数

   1. 题面：编写一个算法来判断一个数是不是”快乐数“。

      ”快乐数“定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为1，也可能是无限循环但始终变不到1。如果可以变为1，就是快乐数。

   2. 最大难点：如何判断循环？？？

      解决办法：利用链表的快慢指针法！！！

      核心代码如下：

      ```C
      int p = n, q = n;
      while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) break;//即使循环了，也有可能为1，即快乐数
      }
      return q == 1;
      ```

      

3. 234回文链表

4. 237删除链表中的节点