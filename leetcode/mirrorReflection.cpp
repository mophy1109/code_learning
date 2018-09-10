// 原题地址 https://leetcode-cn.com/contest/weekly-contest-90/problems/mirror-reflection/

// 858. 镜面反射
// 虚拟 用户通过次数 8
// 虚拟 用户尝试次数 16
// 虚拟 通过次数 8
// 虚拟 提交次数 16
// 题目难度 Medium
// 有一个特殊的正方形房间，每面墙上都有一面镜子。除西南角以外，每个角落都放有一个接受器，编号为 0， 1，以及 2。

// 正方形房间的墙壁长度为 p，一束激光从西南角射出，首先会与东墙相遇，入射点到接收器 0 的距离为 q 。

// 返回光线最先遇到的接收器的编号（保证光线最终会遇到一个接收器）。
 
// 示例：

// 输入： p = 2, q = 1
// 输出： 2
// 解释： 这条光线在第一次被反射回左边的墙时就遇到了接收器 2 。

 

// 提示：

// 1 <= p <= 1000
// 0 <= q <= p


class Solution {
public:
    int mirrorReflection(int p, int q) {
        int t = p % q;
        int i = p, j = q;
        while(t != 0){
            i = j;
            j = t;
            t = i % j;
        }
        //j为最大公约数
        
        int s = p * q / j;//最小公倍数, 最后的距离
        int reflect_times = p / j;
        
        if((q / j) % 2 == 0){
            return 0;
        }else{
            if (reflect_times  % 2 == 0){
                return 2;
            }else return 1;
        }
    }
};