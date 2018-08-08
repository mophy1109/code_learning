// 题目描述
// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

/* 
在计算机中，数用补码进行运算。由于除法运算要比移位运算慢得多，因此尽可能不用除法运算。
本题可以考虑使用移位运算，但是要考虑到负数的情形。若使用右移计算1的个数，可能引起死循环（负数的符号位是1），右移会自动补充符号位。如（1000 1001）右移3位（1111 0001）
*/
class Solution {
public:
    //solution 1: 采用将1不断左移即可解决右移死循环的问题
    int  NumberOf1s1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if(n & flag){//(n&flag != 0)即(n & flag)也可
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }

    //solution 2：优化解法，将一个数减1和自身做位与运算，可以将原数最右边的1变为0
    int  NumberOf1s2(int n) {
        int count = 0;
        while(n!=0){
            n = n & (n-1);
            count++;
        }
        return count;
    }

    //solution 3：看不太懂，很有意思的做法，java语言下的
    public int NumberOf1(int n) {
        int temp = n;
        temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >>> 1);// >>> 是 java无符号移位运算
        temp = (temp & 0x33333333) + ((temp & 0xcccccccc) >>> 2);
        temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0) >>> 4);
        temp = (temp & 0x00ff00ff) + ((temp & 0xff00ff00) >>> 8);
        temp = (temp & 0x0000ffff) + ((temp & 0xffff0000) >>> 16);
        return temp;
     }
};