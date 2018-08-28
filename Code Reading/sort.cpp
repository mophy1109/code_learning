// 作者：opooc
// 链接：https://www.nowcoder.com/discuss/85719
// 来源：牛客网

/*
按照年龄降序比较器
 比较器使用的时候 不和java一样，c++中的比较器要注意返回值要为bool类型，
  而java中的返回值可以为int类型，根据两数相减进行判断下一步的排序。
 比较器第一次比较完成后，下一次在比较的时候还是会含有第一次的排号的顺序，
  是利用了c++中sort函数的排序稳定性.
*/

#include <algorithm>
#include <iostream>
using namespace std;

//比较器的结构体
struct student {
    char name[10];
    int age;
    int classId;
};
//按照年龄升序比较器
bool compareSmallAge(student s1, student s2)
{
    //这里返回false的时候，相当于进行了一个交换操作
    return s2.age > s1.age;
}
//按照班级升序比较器
bool compareSmallClassId(student s1, student s2)
{
    return s2.classId > s1.classId;
}

void printStu(student s){
    cout << s.name << "," << s.age << "," << s.classId << endl;

}

void testComparator()
{
    student s1 = {"opooc", 21, 100};
    student s2 = {"cat", 30, 105};
    student s3 = {"dog", 1, 107};
    student s4 = {"daolao", 2, 107};
    student s5 = {"dst", 20, 103};
    student allStudent[] = {s1, s2, s3, s4, s5};
    sort(allStudent, allStudent + 5, compareSmallAge);
    for(auto s:allStudent){
        printStu(s);
    }
    //上面按照年龄升序后的结果，会继续在下面的班级降序中体现出来
    sort(allStudent, allStudent + 5, compareSmallClassId);
    for(auto s:allStudent){
        printStu(s);
    }
}

int main()
{
    testComparator();
    return 0;
}