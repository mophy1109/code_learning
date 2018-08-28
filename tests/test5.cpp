#include <iostream>
#include <string.h>

using namespace std;

Class A
{
private:
    Char *a;

public:
    A() : a(0) {}
    A(char *aa)
    { //把aa所指字符串拷贝到a所指向的存储空间
        A = new char[strlen(aa) + 1];
        Strcpy(a, aa);
    }
    ~A() { delete[] a; }
};

int main()
{
    int a[10];
    int i = 0;
    while (cin >> a[i]) {
        i++;
    }

    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }
    return 0;
}