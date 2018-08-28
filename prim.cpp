//分解质因数算法
#include <iostream>

using namespace std;

void prim(int m, int n = 2)
{
    if (m >= n) {
        while (m % n)
            n++;
        m /= n;
        prim(m, n);
        cout << n << endl;
    }
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    prim(m,3);
    return 0;
}
