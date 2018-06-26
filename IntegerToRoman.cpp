// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together.
// Twelve is written as, XII, which is simply X + II. The number twenty seven is written
// as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However,
// the numeral for four is not IIII. Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four.
// The same principle applies to the number nine, which is written as IX.
// There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: 3
// Output: "III"
// Example 2:

// Input: 4
// Output: "IV"
// Example 3:

// Input: 9
// Output: "IX"
// Example 4:

// Input: 58
// Output: "LVIII"
// Explanation: C = 100, L = 50, XXX = 30 and III = 3.
// Example 5:

// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

#include <string>

using namespace std;

class AGoodSolution {
public:
    string intToRoman(int num)
    {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"",  "C",  "CC",  "CCC",  "CD",
                      "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"",  "X",  "XX",  "XXX",  "XL",
                      "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"",  "I",  "II",  "III",  "IV",
                      "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] +
               I[num % 10];
    }
};

class MySolution {
public:
    string intToRoman(int num)
    {
        string result = "";
        while (num >= 1000) {
            num -= 1000;
            result += "M";
        }

        //num <1000
        if (num >= 900) {
            num -= 900;
            result += "CM";
        } else if (num >= 500) {
            num -= 500;
            result += "D";
        } else if (num >= 400) {
            num -= 400;
            result += "CD";
        }

        //num < 400
        while (num >= 100) {
            num -= 100;
            result += "C";
        }

        //num < 100
        if (num >= 90) {
            num -= 90;
            result += "XC";
        } else if (num >= 50) {
            num -= 50;
            result += "L";
        } else if (num >= 40) {
            num -= 40;
            result += "XL";
        }

        //num < 40
        while (num >= 10) {
            num -= 10;
            result += "X";
        }

        //num < 10
        if (num == 9) {
            num -= 9;
            result += "IX";
        } else if (num >= 5) {
            num -= 5;
            result += "V";
        } else if (num == 4) {
            num -= 4;
            result += "IV";
        }

        while (num >= 1) {
            num--;
            result += "I";
        }

        return result;
    }
};