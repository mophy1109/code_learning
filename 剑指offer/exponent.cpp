// 题目描述
// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

class Solution {
public:
    bool error = false;
    bool equal(double a, double b)
    {
        if (abs(a - b) < 0.0000001)
            return true;
        else
            return false;
    }

    double PowerWithAbsExp(double base, unsigned int absExp)
    {
        //solution 1:O(n),n=absExp
        // double result = 1.0;
        // while(absExp){
        //     result*=base;
        //     absExp--;
        // }
        // return result;

        //solution 2 :O(log n), n = absExp
        if (absExp == 0)
            return 1;
        if (absExp == 1)
            return base;
        double result = PowerWithAbsExp(base, absExp >> 1);
        result *= result;
        if (absExp & 0x1)
            result *= base;
        return result;
    }

    double Power(double base, int exponent)
    {
        if (equal(base, 0.0) && exponent < 0) {
            error = true;
            return 0.0; //error type = 1
        }

        unsigned int absExp = abs(exponent);

        double result = PowerWithAbsExp(base, absExp);
        if (exponent < 0) result = 1.0/result;
        return result;
    }
};