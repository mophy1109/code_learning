// 移除元素


#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem)
{
    int t = n;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) {
            t--;
        }
    }
    return t;
}

int main()
{
    int n;
    cin >> n;
    int A[100];
    int elem;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> elem;
    cout << removeElement(A, n, elem) <<endl;
    return 1;
}