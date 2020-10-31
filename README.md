# 数据结构实验

#### 介绍
1619303班的2020年数据结构上机实验题

## Chapter_2:线性表

1.用顺序结构和链式结构分别实现线性表

2.设元素值为整型的线性表L，分别采用顺序结构和链式结构存储，编写函数，实现线性表的就地逆置

3.设线性表L，元素值为整型的且存在相同值，分别采用顺序结构和链式结构存储，编写函数，利用原空间，删除重复的元素值。

4. CSP 题目 

问题描述：一次放学的时候，小明已经规划好了自己回家的路线，并且能够预测经过各个路段的时间。同时，小明通过学校里安装的“智慧光明”终端，看到了出发时刻路上经过的所有红绿灯的指示状态。请帮忙计算小明此次回家所需要的时间。

输入格式：

　　输入的第一行包含空格分隔的三个正整数 r、y、g，表示红绿灯的设置。这三个数均不超过 106。

　　输入的第二行包含一个正整数 n，表示小明总共经过的道路段数和路过的红绿灯数目。

　　接下来的 n 行，每行包含空格分隔的两个整数 k、t。k=0 表示经过了一段道路，将会耗时 t 秒，此处 t 不超过 106；k=1、2、3 时，分别表示出发时刻，此处的红绿灯状态是红灯、黄灯、绿灯，且倒计时显示牌上显示的数字是 t，此处 t 分别不会超过 r、y、g。

输出格式：

　　输出一个数字，表示此次小明放学回家所用的时间。

样例输入：
```
30 3 30
8
0 10
1 5
0 11
2 2
0 6
0 3
3 10
0 3
```
样例输出：
```
46
```
样例说明：

　　小明先经过第一段路，用时10秒。第一盏红绿灯出发时是红灯，还剩5秒；小明到达路口时，这个红绿灯已经变为绿灯，不用等待直接通过。接下来经过第二段路，用时11秒。第二盏红绿灯出发时是黄灯，还剩两秒；小明到达路口时，这个红绿灯已经变为红灯，还剩11秒。接下来经过第三、第四段路，用时9秒。第三盏红绿灯出发时是绿灯，还剩10秒；小明到达路口时，这个红绿灯已经变为红灯，还剩两秒。接下来经过最后一段路，用时3秒。共计10+11+11+9+2+3=46秒。

评测用例规模与约定：

　　有些测试点具有特殊的性质：

　　* 前2个测试点中不存在任何信号灯。

　　测试点的输入数据规模：

　　* 前6个测试点保证n≤103。

　　* 所有测试点保证n≤105。

5. CSP 题目

问题描述：近来，跳一跳这款小游戏风靡全国，受到不少玩家的喜爱。

　　简化后的跳一跳规则如下：玩家每次从当前方块跳到下一个方块，如果没有跳到下一个方块上则游戏结束。

　　如果跳到了方块上，但没有跳到方块的中心则获得1分；跳到方块中心时，若上一次的得分为1分或这是本局游戏的第一次跳跃则此次得分为2分，否则此次得分比上一次得分多两分（即连续跳到方块中心时，总得分将+2，+4，+6，+8...）。

　　现在给出一个人跳一跳的全过程，请你求出他本局游戏的得分（按照题目描述的规则）。

输入格式：

　　输入包含多个数字，用空格分隔，每个数字都是1，2，0之一，1表示此次跳跃跳到了方块上但是没有跳到中心，2表示此次跳跃跳到了方块上并且跳到了方块中心，0表示此次跳跃没有跳到方块上（此时游戏结束）。

输出格式：

　　输出一个整数，为本局游戏的得分（在本题的规则下）。

样例输入：
```
1 1 2 2 2 1 1 2 2 0
```
样例输出：
```
22
```
数据规模和约定：

　　对于所有评测用例，输入的数字不超过30个，保证0正好出现一次且为最后一个数字。

附加题：习题集 1.19 1.20 2.19
